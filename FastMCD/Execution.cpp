#include "Execution.h"
#include <armadillo>

using namespace std;
using namespace arma;

mat Execution::step4() {
    Sampling s;
    Calculations cal;
    int n = (int) data.n_rows;
    int p = (int) data.n_cols;
    int h = (n + p +1)/2;
    
    vec res(500);
    vector<mat> sets;
    for (int i = 0; i < 500; ++i) {
        if (i == 499)
            cout << "Here" << endl;
        mat J;
        int tmppp = i;
        do {
            J = s.randomSample(p+1, ++tmppp);
            J.print("sample");
        } while (!::all((vec) J));
        mat Hnew = cal.Cstep(J, h);
        Hnew = cal.Cstep(Hnew, h);
        Hnew = cal.Cstep(Hnew, h);
        res(i) = det(cal.covariance(Hnew));
        sets.push_back(Hnew);
    }
    
    uvec indexes = ::sort_index(res);
    indexes.resize(10);
    vec res2(10);
    vector<mat> sets2;
    for (int i = 0; i < 10; ++i) {
        mat tmp = sets[i];
        double deter = 0;
        //double prev = 0;
        for (int j = 0; j < 10; ++j) {
            tmp = cal.Cstep(tmp, h);
            deter = det(cal.covariance(tmp));
        }
//        do {
//            prev = deter;
//            tmp = cal.Cstep(tmp, h);
//            deter = det(cal.covariance(tmp));
//        } while (deter == 0 || deter == prev);
        res2(i) = deter;
        sets2.push_back(tmp);
    }
    indexes = ::sort_index(res2);
    return sets[indexes(0)];
}

void Execution::reweight(mat Hnew) {
    Calculations cal;
    mat mu = cal.mean_col(Hnew);
    mat s = cal.covariance(Hnew);
    vec md = cal.mahDistance(mu, s);
    mat s_rw = ::median(md) / chisq[mu.n_cols-1] * s;
    vec md_rw = cal.mahDistance(mu, s_rw);
    uvec mdindex = find(md_rw > chisq2[mu.n_cols-1]);
    mat outliers = data.elem(mdindex);
    mat s_out = cal.covariance(outliers);
    mat mu_out = cal.mean_col(outliers);
    mat maha_out = cal.mahDistance(mu_out, s_out);
}
