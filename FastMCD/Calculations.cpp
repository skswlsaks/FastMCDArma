#include "Calculations.h"
#include <armadillo>

using namespace std;
using namespace arma;


mat Calculations::mean_col(mat m) {
    return ::mean(m, 0);
}

mat Calculations::covariance(mat m) {
    return ::cov(m);
}

vec Calculations::mahDistance(mat mean, mat cov) {
    int n = (int) data.n_rows;
    vec md(n);
    for (int i = 0; i < n; ++i) {
        mat x_i = data.row(i) - mean;
        mat y = ::solve(cov, ::trans(x_i));
        md(i) = ::as_scalar(x_i * y);
    }
    return md;
}

mat Calculations::Cstep(mat Hold, int h) {
    mat Told = mean_col(Hold);
    mat Sold = covariance(Hold);
    vec md = mahDistance(Told, Sold);
    uvec q = ::sort_index(md);
    q.resize(h);
    return data.elem(q);
}