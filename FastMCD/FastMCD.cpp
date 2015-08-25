#include <iostream>
#include <armadillo>
#include "Scanner.h"
#include "Calculations.h"
#include "Execution.h"

using namespace std;
using namespace arma;

extern mat data;

int main(int argc, char **argv) {
    
//    mat data(2,3);
//    
//    data.fill(3);
//    
//    data.print("Data:");
    
    Scanner *scanner = new Scanner();
    scanner->file(argc, argv);
//    data.print("Data:");
    Execution e;
    mat m = e.step4();
    
//    mat J(2,1);
//    J.row(0) = data.row(1283);
//    J.row(1) = data.row(539);
//    J.print();
//    Calculations cal;
//    (cal.Cstep(J, 800)).print();
    
    m.print("cov:");
    
    delete scanner;
    
}