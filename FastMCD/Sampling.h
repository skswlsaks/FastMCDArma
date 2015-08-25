#ifndef __FastMCD__Sampling__
#define __FastMCD__Sampling__

#include <armadillo>
#include "Scanner.h"
#include "Calculations.h"

using namespace arma;
using namespace std;

extern mat data;

class Sampling {
public:
    Sampling() {};
    mat nonZeroSample(mat sample);
    mat randomSample(int p, int i);
    mat addSample(mat sample);
    ~Sampling() {};

};





#endif /* defined(__FastMCD__Sampling__) */
