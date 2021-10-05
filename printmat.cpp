#include "all.h"

using namespace std;

void printmat(int n, vector<double> A)
{
    double mtmp;
    for (int row_num = 0; row_num < n; row_num++)
    {
        printf("[");
        for (int col_num = 0; col_num < n; col_num++)
        {
            mtmp = A[col_num + n * row_num];
            printf("%5.5e", mtmp);
            if (col_num < n - 1)
            {
                printf(",");
            }
        }
        if (row_num < n - 1)
        {
            printf("];\n ");
        }
        else
        {
            printf("]");
        }
    }
    printf("]\n");
}

void printvec(int n, vector<double> B)
{
    double vtmp;
    printf("[");
    for (int col_num = 0; col_num < n; col_num++)
    {
        vtmp = B[col_num];
        printf("%5.5e", vtmp);
        if (col_num < n - 1)
        {
            printf(",");
        }
    }
    printf("]\n");
}

void printvec(int n, vector<vector<double>> C)
{
    double vtmp;
    for (int row_num = 0; row_num < n; row_num++)
    {
        printf("[");
        for (int col_num = 0; col_num < n; col_num++)
        {
            vtmp = C.at(row_num).at(col_num);
            printf("%5.5e", vtmp);
            if (col_num < n - 1)
            {
                printf(",");
            }
        }
        if (row_num < n - 1)
        {
            printf("];\n ");
        }
        else
        {
            printf("]");
        }
    }
    printf("]\n");
}