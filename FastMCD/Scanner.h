#ifndef __FastMCD__Scanner__
#define __FastMCD__Scanner__

#include <armadillo>
#include<string>

using namespace arma;
using namespace std;

class Scanner {
public:
    Scanner() {};
    ~Scanner() {};
    int file(int argc, char **argv);
    void loadfile(char **argv);
    void split(const string& s, int rowNum);
    char deliminator = ',';
    int colNum = 1;
};

#endif /* defined(__FastMCD__Scanner__) */
