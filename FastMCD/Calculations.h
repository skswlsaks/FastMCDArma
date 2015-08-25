#ifndef __FastMCD__Calculations__
#define __FastMCD__Calculations__

#include "Scanner.h"
#include "Sampling.h"

using namespace std;
using namespace arma;

extern mat data;

class Calculations {
public:
    Calculations() {};
    mat mean_col(mat m);
    mat covariance(mat m);
    vec mahDistance(mat mean, mat cov);
    mat Cstep(mat Hold, int h);
};



#endif /* defined(__FastMCD__Calculations__) */
