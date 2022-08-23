#include <ctime>
#include <cstdlib>
#include <cmath>
#include "pi_sim.h"


double PiSim::generate()
{
    double x;
    double y;
    int count {0};

    for (int i = 0; i < genQty; i++)
    {
        x = dblRandom();
        y = dblRandom();
        if(dist(x, y) <= 1)
            count ++;
    }

    return static_cast<double>(count) / genQty * 4.0;
    

}

double  PiSim::dblRandom()
{
    return static_cast<double> (rand()) / RAND_MAX;
}

double  PiSim::dist(double x, double y)
{
    return sqrt(x*x + y*y);
}