#pragma once

#include <vector>

class Pancreas;

namespace tumour_model {

::Pancreas* SeedAndGrowToStartVolume(double p0, double psc, int dmax, int gage, int page, double startVolume);
::Pancreas* CreateNewParticle(double p0, double psc, int dmax, int gage, int page, ::Pancreas* pancreas);
void UpdateParticle(double p0, double psc, int dmax, int gage, int page, ::Pancreas* pancreas);
std::vector<double> FullSimulation(double p0, double psc, int dmax, int gage, int page, double startVolume, int simtime);
std::vector<double> FullSimulation_biphasic(double p0_1, double psc_1, int dmax_1, int gage_1, int page,
                                            double p0_2, double psc_2, int dmax_2, int gage_2,
                                            double tau, double startVolume, int simtime);

} 