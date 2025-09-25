#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <tumour_model/Model.hpp>

namespace py = pybind11;

PYBIND11_MODULE(_core, m) {
    m.doc() = "Bindings for the BVCBM tumour growth model";

    m.def(
        "full_simulation", &tumour_model::FullSimulation,
        py::arg("p0"), py::arg("psc"), py::arg("dmax"), py::arg("gage"), py::arg("page"), py::arg("start_volume"),
        py::arg("simtime"),
        R"pbdoc(Execute a monophasic tumour growth simulation.

Parameters
----------
p0 : float
    Probability of cancer cell division per day.
psc : float
    Probability of PSC activation per hour.
dmax : int
    Maximum diffusion distance for nutrients.
gage : int
    Number of hours before a cancer cell can divide again.
page : int
    Number of hours before a PSC can activate a neighbour.
start_volume : float
    Target tumour volume used to seed the simulation.
simtime : int
    Number of simulated days after the tumour reaches the starting volume.

Returns
-------
list[float]
    Daily tumour volumes over the course of the simulation.)pbdoc");

    m.def(
        "full_simulation_biphasic", &tumour_model::FullSimulation_biphasic,
        py::arg("p0_1"), py::arg("psc_1"), py::arg("dmax_1"), py::arg("gage_1"), py::arg("page"),
        py::arg("p0_2"), py::arg("psc_2"), py::arg("dmax_2"), py::arg("gage_2"), py::arg("tau"),
        py::arg("start_volume"), py::arg("simtime"),
        R"pbdoc(Execute a biphasic tumour growth simulation with a parameter switch at time tau.)pbdoc");
}