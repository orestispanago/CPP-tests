#include <vector>
#include "spline.h"
#include <iostream>

namespace air
{

    std::vector<double> temps = {250, 300, 350, 400, 450};
    std::vector<double> rhos = {1.4235, 1.1771, 1.0085, 0.88213, 0.8770};
    std::vector<double> ks = {0.0223, 0.0263, 0.03, 0.0338, 0.0373};
    tk::spline rho_spline(temps, rhos);
    tk::spline k_spline(temps, ks);

    void check_temp(double temp)
    {
        if (temp < temps[0] || temp > temps.back())
        {
            std::cout << "Air temperature: " << temp << " out of interpolation range.\n";
            exit(1);
        }
    }

    double rho(double temp)
    {
        check_temp(temp);
        return rho_spline(temp);
    }

    double k(double temp)
    {
        check_temp(temp);
        return k_spline(temp);
    }
}