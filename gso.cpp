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
