#include <vector>
#include "spline.h"
#include <tuple>

std::tuple<double, double> water_properties(double temp)
{
    // Calculates water thermophysical properties from temperature
    std::vector<double> temps = {278.15, 298.15, 323.15, 348.15, 368.15}; // must be increasing
    std::vector<double> rho = {1000, 997.1, 988, 974.9, 961.9};
    std::vector<double> cp = {4200, 4183, 4181, 4190, 4210};
    tk::spline rho_spline(temps, rho);
    tk::spline cp_spline(temps, cp);
    return std::make_tuple((temp), cp_spline(temp));
}

double water_cp(double temp)
{
    std::vector<double> temps = {278.15, 298.15, 323.15, 348.15, 368.15}; // must be increasing
    std::vector<double> cp = {4200, 4183, 4181, 4190, 4210};

    tk::spline s(temps, cp);
    return s(temp);
}

double water_k(double temp)
{
    std::vector<double> temps = {278.15, 298.15, 323.15, 348.15, 368.15}; // must be increasing
    std::vector<double> k = {0.5576, 0.5948, 0.6305, 0.653, 0.6634};

    tk::spline s(temps, k);
    return s(temp);
}
