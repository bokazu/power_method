#include "all.h"

using namespace std;

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