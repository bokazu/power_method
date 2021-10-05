#include "all.h"

using namespace std;

lapack_int LAPACKE_dsyev(int matrix_layout, char jobz, char uplo, lapack_int n,
                         double *a, lapack_int lda, double *w);

int main()
{
    int n;
    vector<double> A;
    // Setting Matrix(Column Major)
    string filename("sample/sample1.txt");
    double number;

    ifstream sample_file(filename);
    if (!sample_file.is_open())
    {
        cerr << "Could not open the file - '" << filename << "'" << endl;
        return EXIT_FAILURE;
    }
    while (sample_file >> number)
    {
        A.push_back(number);
        n++;
    }
    sample_file.close();
    n = sqrt(n);
    vector<double> AA(n * n);
    cblas_dcopy(n * n, A.data(), 1, AA.data(), 1);
    vector<double> u0(n, 0.0), v(n, 0.0), lambda(n, 0.0);
    vector<vector<double>> ev(n, vector<double>(n, 0.0));

    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        u0.at(i) = (double)rand() / RAND_MAX;
    }

    printf("A = \n");
    printmat(n, A);
    printf("u0 = \n");
    printvec(n, u0);

    power(n, A, u0, v, lambda, ev);

    printf("/******************************************************************"
           "*********************/\n");
    printf("/***********************************  My answer  "
           "***************************************/\n");
    printf("/******************************************************************"
           "*********************/\n");

    printf("A = \n");
    printmat(n, AA);
    printf("\n");
    printf("\x1b[41m Eigen values \x1b[m\n");
    printf("lambda = \n");
    printvec(n, lambda);
    printf("\n");
    printf("\x1b[41m Eigen vectors \x1b[m\n");
    for (int i = 0; i < n; i++)
    {
        cout << "u[" << i << "] = \n";
        printvec(n, ev.at(i));
        printf("\n");
    }

    // Checking answer by lapack
    printf("/******************************************************************"
           "*********************/\n");
    printf("/*******************************  Compare my answer with "
           "LAPCKE***********************/\n");
    printf("/******************************************************************"
           "*********************/\n");
    vector<double> lw(n);
    LAPACKE_dsyev(LAPACK_COL_MAJOR, 'V', 'U', n, AA.data(), n, lw.data());

    printf("\x1b[41m Eigen values \x1b[m\n");
    printf("lambda = \n");
    printvec(n, lw);
    printf("\n");

    printf("\x1b[41m Eigen vectors \x1b[m\n");
    printf("u = \n");
    printmat(n, AA);
    printf("\n");
}