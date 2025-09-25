cmake_minimum_required(VERSION 3.18)
project(bvcbm LANGUAGES CXX)

option(BVCBM_BUILD_PYTHON "Build the Python extension module" OFF)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(bvcbm STATIC
    TumourModel/src/Model.cpp
)

set_target_properties(bvcbm PROPERTIES POSITION_INDEPENDENT_CODE ON)

target_include_directories(bvcbm
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/TumourModel/include>
        $<INSTALL_INTERFACE:include>
)

target_compile_features(bvcbm PUBLIC cxx_std_17)

if(BVCBM_BUILD_PYTHON)
    find_package(pybind11 CONFIG REQUIRED)

    pybind11_add_module(_core MODULE TumourModel/bindings/bvcbm_module.cpp)
    target_link_libraries(_core PRIVATE bvcbm)

    install(TARGETS _core DESTINATION bvcbm)
endif()

install(TARGETS bvcbm EXPORT bvcbmTargets)
install(DIRECTORY TumourModel/include/ DESTINATION include)

if(BVCBM_BUILD_PYTHON)
    install(DIRECTORY python/bvcbm/ DESTINATION bvcbm FILES_MATCHING PATTERN "*.py")
endif()

install(EXPORT bvcbmTargets NAMESPACE bvcbm:: DESTINATION lib/cmake/bvcbm)