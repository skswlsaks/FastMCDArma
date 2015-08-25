#include "Sampling.h"
#include <armadillo>

using namespace std;
using namespace arma;


mat Sampling::randomSample(int p, int i) {
    //default_random_engine generator;
    //suniform_int_distribution<int> distribution(0, (int) data.n_rows);
    int indexOfData[p];
    for (int i = 0; i < p; ++i) {
        indexOfData[i] = -1;
    }
    
    int count = 0;
    mat sample(p, data.n_cols);
    do {
        srand((i+1) * (count+1) * (int) time(0));
        int tmp = rand() % (data.n_rows);
        //int tmp = distribution(generator);
        
        if (find(indexOfData, indexOfData+p, tmp)
            == indexOfData+p) {
            sample.row(count) = data.row(tmp);
            indexOfData[count] = tmp;
            ++count;
        }
    } while (count < p);
    cout << "LOPP" << endl;
    return sample;
}

mat Sampling::nonZeroSample(mat sample) {
    Calculations cal;
    mat cov;
    double determinent;
    do {
        cov = cal.covariance(sample);
        determinent = ::det(sample);
        if (determinent == 0) {
            sample = addSample(sample);
        }
    } while (determinent == 0);
    return sample;
}

mat Sampling::addSample(mat sample) {
    int n = (int) sample.n_rows;
    sample.resize(n+1, sample.n_cols);
    srand((int) time(0));
    int tmp = rand() % (data.n_rows);
    sample.row(n) = data.row(tmp);
    return sample;
}