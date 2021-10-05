#include "all.h"

using namespace std;

void gso(int n, int i, vector<double>& v, vector<double>& A, vector<double>& u0,
         vector<vector<double>>& ev)
{
    double cef;
    for (int row_num = 0; row_num < i; row_num++)
    {
        cef = -1.0 * cblas_ddot(n, v.data(), 1, ev[row_num].data(), 1);
        cblas_daxpy(n, cef, ev.at(row_num).data(), 1, v.data(), 1);
    }
}

void sdz(int n, vector<double>& v)
{
    double a = 1. / cblas_dnrm2(n, v.data(), 1);
    cblas_dscal(n, a, v.data(), 1);

    // Check norm
    double norm = cblas_dnrm2(n, v.data(), 1);
    double eps = abs(1.0 - norm);
    if (eps > 1.0e-14)
    {
        printf("\x1b[31m NORM ERROR\x1b[39m\n");
    }
}
#include "all.h"

using namespace std;

void root_shift(int n, int i, vector<double>& A, vector<vector<double>>& ev,
                double lambda2)
{
    vector<double> y(n, 0.0);
    lambda2 = -1.0 * lambda2;
    cblas_daxpy(n, lambda2, ev.at(i).data(), 1, y.data(), 1);  // calculate
                                                               // |x><x|
    cblas_dger(CblasRowMajor, n, n, 1.0, y.data(), 1.0, ev.at(i).data(), 1.0,
               A.data(), n);
}

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