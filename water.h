#include <vector>
#include "spline.h"
// #include <tuple>
#include <iostream>

namespace water
{

    // std::tuple<double, double> water_properties(double temp)
    // {
    //     // Calculates water thermophysical properties from temperature
    //     std::vector<double> temps = {278.15, 298.15, 323.15, 348.15, 368.15}; // must be increasing
    //     std::vector<double> rho = {1000, 997.1, 988, 974.9, 961.9};
    //     std::vector<double> cp = {4200, 4183, 4181, 4190, 4210};
    //     tk::spline rho_spline(temps, rho);
    //     tk::spline cp_spline(temps, cp);
    //     return std::make_tuple((temp), cp_spline(temp));
    // }

    std::vector<double> temps = {278.15, 298.15, 323.15, 348.15, 368.15}; // must be increasing
    std::vector<double> rhos = {1000, 997.1, 988, 974.9, 961.9};
    std::vector<double> cps = {4200, 4183, 4181, 4190, 4210};
    std::vector<double> ks = {0.5576, 0.5948, 0.6305, 0.653, 0.6634};
    tk::spline rho_spline(temps, rhos);
    tk::spline cp_spline(temps, cps);
    tk::spline k_spline(temps, ks);

    void check_temp(double temp)
    {
        if (temp < temps[0] || temp > temps.back())
        {
            std::cout << "Water temperature: " << temp << " out of interpolation range.\n";
            exit(1);
        }
    }

    double rho(double temp)
    {
        check_temp(temp);
        return rho_spline(temp);
    }

    double cp(double temp)
    {
        check_temp(temp);
        return cp_spline(temp);
    }

    double k(double temp)
    {
        check_temp(temp);
        return k_spline(temp);
    }
}