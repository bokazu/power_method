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