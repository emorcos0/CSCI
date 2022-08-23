#ifndef PI_SIM_H
#define PI_SIM_H

const int DEFAULT_GEN_QTY{1'000'000};


class PiSim
{
public: 
    PiSim() : PiSim(DEFAULT_GEN_QTY) { }
    PiSim(int genQty) : genQty{genQty} { }

    double generate();

private:
    int genQty;
    double dblRandom();
    double dist(double, double);
};

#endif