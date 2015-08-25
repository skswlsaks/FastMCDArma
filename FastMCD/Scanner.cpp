#include <iostream>
#include "Scanner.h"
#include <armadillo>
#include <cstring>

using namespace arma;
using namespace std;

mat data;

void Scanner::split(const string& s, int rowNum) {
    int count = 0;
    int i = 0;
    int j = (int) s.find(deliminator);
    i = ++j;
    j = (int) s.find(deliminator, j);
    
    while (count < colNum) {
        string tmp = s.substr(i, j-i);
        data(rowNum, count) = atof(tmp.c_str());
        
        i = ++j;
        j = (int) s.find(deliminator, j);
        
        ++count;
    }
}

void Scanner::loadfile(char **argv) {
    string tmp;
    
    ifstream in(argv[1]);
    
    if (!in)
        cout << "ERROR loading file!" << endl;
    
    int rowNum = 0;
    
    while (!in.eof()) {
        getline(in, tmp, '\n');
        ++rowNum;
    }
    
    ifstream intmp(argv[1]);
    
    data.resize(rowNum - 2, colNum);
    
    int rowNumCount = 0;
    // Get rid of first line (they are titles)
    getline(intmp, tmp, '\n');
    
    while (!intmp.eof()) {
        if(rowNumCount == rowNum - 2) break;
        getline(intmp, tmp, '\n');
        split(tmp, rowNumCount);
        tmp.clear();
        ++rowNumCount;
    }
}

int Scanner::file(int argc, char **argv) {
    
    if (argc < 2)
        return -1;
    
    data.resize(1,colNum);
    
    loadfile(argv);
    
    return 0;
}
