// who: emorcos
// what: <the function of this program>
// why: <the name of the lab>
// when: < the due date of this lab.

#include "pi_sim.h"

#include <iostream>



int main(int argc, char const *argv[])
{
	PiSim pi{1'000'000'000};

    std::cout << "pi is estimated as " << pi.generate() << std::endl;
	
	return 0;
}
