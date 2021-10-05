#include "all.h"

using namespace std;

void power(int n, vector<double>& A, vector<double>& u0, vector<double>& v,
           vector<double>& lambda, vector<vector<double>>& ev)
{
    // Setting BLAS parameters
    double alpha = 1.0;
    double beta = 0.0;
    int inc_u, inc_v;
    inc_u = inc_v = 1;

    // Setting u = u0
    vector<double> u(n, 0.0);
    cblas_dcopy(n, u0.data(), 1, u.data(), 1);

    // Calculate eigen vectors and values
    for (int i = 0; i < n; i++)
    {
        printf("\x1b[41m Roop number = %d\x1b[m\n", i);
        double eps = 1.0;
        double lambda1, lambda2;
        int count = 0;

        while (eps > 1.0e-15)
        {
            cblas_dgemv(CblasColMajor, CblasNoTrans, n, n, alpha, A.data(), n,
                        u.data(), inc_u, beta, v.data(),
                        inc_v);  // v^{k+1 = Au^{k}}
            if (i != 0)
            {
                gso(n, i, v, A, u0, ev);
            }

            sdz(n, v);  // standabilization of v
            // printf("v = \n");
            // printvec(n, v);
            cblas_dcopy(n, v.data(), 1, u.data(), 1);  // Regenesis of u (u = v)

            if (count % 2 == 0)
            {
                lambda1 = eigen_value(n, A, u);
                cout << "lambda1 = " << endl;
                printf("%5.15e\n", lambda1);
            }
            else
            {
                lambda2 = eigen_value(n, A, u);
                cout << "lambda2 = " << endl;
                printf("%5.15e\n", lambda2);
            }

            if (count > 0)
            {
                eps = abs(lambda1 - lambda2);
            }
            count += 1;
        }  // while
        printf("u = \n");
        // printvec(n, u);
        copy(u.begin(), u.end(), ev.at(i).begin());
        lambda.at(i) = lambda2;
        root_shift(n, i, A, ev, lambda2);
    }
}