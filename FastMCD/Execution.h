#ifndef __FastMCD__Execution__
#define __FastMCD__Execution__

#include "Scanner.h"
#include "Sampling.h"
#include "Calculations.h"
#include <armadillo>

using namespace arma;

extern mat data;

class Execution {
public:
    mat step4();
    void step5();
    void reweight(mat Hnew);
private:
    double chisq[10] =  {
        0.4549364, 1.3862944, 2.3659739, 3.3566940,
        4.3514602, 5.3481206, 6.3458112, 7.3441215,
        8.3428327, 9.3418178};
    double chisq2[10] = {
        5.023886, 7.377759, 9.348404, 11.143287,
        12.832502, 14.449375, 16.012764, 17.534546,
        19.022768, 20.483177};
};



#endif /* defined(__FastMCD__Execution__) */
