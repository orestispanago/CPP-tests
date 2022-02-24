#include <cstdio>
#include <vector>
#include "spline.h"
#include "water.h"

int main(int, char **)
{
    using namespace std;
    double t_w = 293.15;
    double t_rho, t_cp;
    tie(t_rho, t_cp) = water_properties(t_w);
    printf("Water rho at %.3f is %.3f\n", t_w, t_rho);
    printf("Water Cp at %.3f is %.3f\n", t_w, t_cp);
}