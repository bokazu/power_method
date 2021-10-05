#include "all.h"

using namespace std;

double eigen_value(int n, vector<double>& A, vector<double>& u)
{
    vector<double> y(n);
    double lambda;
    double alpha = 1.0;
    double beta = 0.0;

    cblas_dgemv(CblasColMajor, CblasNoTrans, n, n, alpha, A.data(), n, u.data(),
                1, beta, y.data(), 1);                 // y=Au'
    lambda = cblas_ddot(n, u.data(), 1, y.data(), 1);  // t[y]・u'

    return lambda;
}