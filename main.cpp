#include "water.h"
#include "air.h"

int main(int, char **)
{
    double t_w = 293.15;
    double rho_w, cp_w;
    // tie(t_rho, t_cp) = water_properties(t_w);
    rho_w = water::rho(t_w);
    cp_w = water::cp(t_w);
    printf("Water rho at %.2f is %.3f\n", t_w, rho_w);
    printf("Water Cp at %.2f is %.3f\n", t_w, cp_w);

    double t_air = 300;
    double rho_air, k_air;
    rho_air = air::rho(t_air);
    k_air = air::k(t_air);
    printf("Air rho at %.2f is %.3f\n", t_air, rho_air);
    printf("Air k at %.2f is %.3f\n", t_air, k_air);
}
