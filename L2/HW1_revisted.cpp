#include <iostream>
#include <time.h>

using namespace std;

/**
 * Rfib - Recursive fibbonacci
 * 
 * @param n to which fibbionaci number is to be calculated.
 * 
 * @return nth fibonnacci trimmed by 2020.
 */
int Rfib(long long int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
    {
        return (Rfib(n - 1) + Rfib(n - 2)) % 2020;
    }
}

/**
 * Ifib - Iterative fibbonacci
 * 
 * @param n to which fibbionaci number is to be calculated.
 * 
 * @return nth fibonnacci trimmed by 2020.
 */
int Ifib(long long int n)
{
    if (n == 0)
        return 1;
    else if (n == 1)
        return 1;
    else
    {
        int a = 0;
        int b = 1;
        for (long long int i = 1; i <= n; i++)
        {
            int temp = b;
            b = a + b;
            a = temp % 2020;
        }
        return a;
    }
}

/**
 * matrix_mul - multiplies two matrixes
 * 
 * @param a 2x2 matrix to be multiplied (on the left).
 * @param b 2x2 matrix to be multiplied (on the right).
 * @param result 2x2 matrix which will store the result for the multiplication.
 * 
 * @return void.
 */
void matrix_mul(int a[2][2], int b[2][2], int result[2][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < 2; k++)
            {
                result[i][j] += a[i][k] * b[k][j];
                result[i][j] %= 2020;
            }
        }
    }
}

/**
 * get_n_matrix - Calculate the A^n matrix recursively.
 * 
 * @param n 2x2 matrix to be multiplied (on the left).
 * @param result 2x2 matrix which will store the resultant matrix.
 * 
 * @return void.
 */
void get_n_matrix(long long int n, int result[2][2])
{
    if (n == 1 || n == 0)
    {
        result[0][0] = 1;
        result[1][0] = 1;
        result[0][1] = 1;
        result[1][1] = 0;
        return;
    }

    if (n % 2 == 0)
    {
        int matrix[2][2] = {1, 1, 1, 1};
        get_n_matrix(n / 2, matrix);
        int prod[2][2] = {0};
        matrix_mul(matrix, matrix, result);
    }
    else
    {
        int matrix[2][2] = {1, 1, 1, 1};
        get_n_matrix(n / 2, matrix);
        int prod[2][2] = {0};
        int A[2][2] = {1, 1, 1, 0};
        matrix_mul(matrix, matrix, prod);
        matrix_mul(prod, A, result);
    }
}

/**
 * Ffib - Fast fibbonacci
 * 
 * @param n to which fibbionaci number is to be calculated.
 * 
 * @return nth fibonnacci trimmed by 2020.
 */
int Ffib(long long int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    else
    {
        int matrix[2][2] = {0};
        get_n_matrix(n, matrix);
        return matrix[0][0];
    }
}

int main()
{
    long long int n = 1;
    int algorithm_type = 0;
    int output;
    clock_t start, end;

    cout << "Please input the desired number: ";
    cin >> n;
    cout << "\nPlease input desired algorithm (0 == Iterative (def),1 == Recursive,2 == fast): ";
    cin >> algorithm_type;

    if (algorithm_type == 1)
    {
        start = clock();
        output = Rfib(n);
        end = clock();
    }
    else if (algorithm_type == 0)
    {
        start = clock();
        output = Ifib(n);
        end = clock();
    }
    else
    {
        start = clock();
        output = Ffib(n);
        end = clock();
    }

    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);

    cout << "Output: " << output << endl;
    cout << "Time Taken(s): " << time_taken << endl;

    cout << "Program has ended. \n";
    return 0;
}