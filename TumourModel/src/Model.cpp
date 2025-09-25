#include <tumour_model/Model.hpp>

#include <tumour_model/Pancreas.hpp>
#include <vector>

namespace tumour_model {

using ::Cell;
using ::Pancreas;
using ::Params;

Pancreas* SeedAndGrowToStartVolume(double p0, double psc, int dmax, int gage, int page, double startVolume) {
    Params* parameters = new Params(p0, psc, dmax, gage, page);
    std::vector<Cell*> empty;
    Pancreas* pancreas = new Pancreas(empty, parameters);
    pancreas->CreateInitialTumour();

    double volume = 0.0;
    int days = 0;
    while (volume < startVolume && days < 200) {
        volume = pancreas->SimulateOneDay(days++);
    }

    return pancreas;
}

Pancreas* CreateNewParticle(double p0, double psc, int dmax, int gage, int page, Pancreas* pancreas) {
    return pancreas->CreateNewParticle(new Params(p0, psc, dmax, gage, page));
}

void UpdateParticle(double p0, double psc, int dmax, int gage, int page, Pancreas* pancreas) {
    pancreas->UpdateParameters(new Params(p0, psc, dmax, gage, page));
}

std::vector<double> FullSimulation_biphasic(double p0_1, double psc_1, int dmax_1, int gage_1, int page, double p0_2,
                                            double psc_2, int dmax_2, int gage_2, double tau, double startVolume,
                                            int simtime) {
    Params* parameters = new Params(p0_1, psc_1, dmax_1, gage_1, page);
    std::vector<Cell*> empty;
    Pancreas* pancreas = new Pancreas(empty, parameters);
    pancreas->CreateInitialTumour();

    double volume = 0.0;
    int days1 = 0;
    while (volume < startVolume && days1 < 200) {
        volume = pancreas->SimulateOneDay(days1++);
    }

    std::vector<double> tumourVolumes(simtime);

    int days2 = 0;
    while (days2 < tau) {
        tumourVolumes[days2] = pancreas->SimulateOneDay(1);
        days2++;
    }

    pancreas->UpdateParameters(new Params(p0_2, psc_2, dmax_2, gage_2, page));

    while (days2 < simtime) {
        tumourVolumes[days2] = pancreas->SimulateOneDay(1);
        days2++;
    }

    delete parameters;
    delete pancreas;

    return tumourVolumes;
}

std::vector<double> FullSimulation(double p0, double psc, int dmax, int gage, int page, double startVolume, int simtime) {
    Params* parameters = new Params(p0, psc, dmax, gage, page);
    std::vector<Cell*> empty;
    Pancreas* pancreas = new Pancreas(empty, parameters);
    pancreas->CreateInitialTumour();

    double volume = 0.0;
    int days1 = 0;
    while (volume < startVolume && days1 < 200) {
        volume = pancreas->SimulateOneDay(days1++);
    }

    std::vector<double> tumourVolumes(simtime);
    int days2 = 0;
    while (days2 < simtime) {
        tumourVolumes[days2] = pancreas->SimulateOneDay(1);
        days2++;
    }

    delete parameters;
    delete pancreas;

    return tumourVolumes;
}

} 