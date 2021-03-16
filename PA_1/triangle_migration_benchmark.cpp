/* 
    #########################################
    # Solution by Debaditya Bhattacharya    #
    # Roll No: 190254                       #
    # Email-id: debbh@iitk.ac.in            #
    # Hackkerrank-id: @debbh922             #
    #########################################
*/
#include <iostream>
#include <time.h>
#include <chrono>
using namespace std;

// ###############################################################
//                       Recursive Algorithm
// ###############################################################
long long int D_recursive(long long int n);
long long int U_recursive(long long int n);

long long int U_recursive(long long int n)
{
    if (n == 0)
    {
        return 1;
    }
    return 3 * U_recursive(n - 1) + D_recursive(n - 1);
}

long long int D_recursive(long long int n)
{
    if (n == 0)
    {
        return 0;
    }
    return 3 * D_recursive(n - 1) + U_recursive(n - 1);
}

// ###############################################################
//                      Iterative Algorithm
// ###############################################################

unsigned long long int U_iterative(long long int n)
{
    unsigned long long int U_internal = 1;
    unsigned long long int D_internal = 0;

    for (long long int i = 0; i < n; i++)
    {
        unsigned long long int temp = U_internal;
        U_internal = (3 * U_internal + D_internal) % 1000000007;
        D_internal = (3 * D_internal + temp) % 1000000007;
    }
    return U_internal;
}

// ###############################################################
//                        Power Algorithm
// ###############################################################

void matrix_mul(long long int a[2][2], long long int b[2][2], long long int result[2][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < 2; k++)
            {
                result[i][j] += a[i][k] * b[k][j];
                result[i][j] %= 1000000007;
            }
        }
    }
}

void U_power_matrix(long long int n, long long int matrix[2][2])
{
    if (n == 0)
    {
        matrix[0][0] = 1;
        matrix[0][1] = 0;
        matrix[1][0] = 0;
        matrix[1][1] = 0;
    }
    else if (n == 1)
    {
        matrix[0][0] = 3;
        matrix[0][1] = 1;
        matrix[1][0] = 1;
        matrix[1][1] = 3;
    }
    else if (n % 2 == 0)
    {
        long long int temp[2][2];
        U_power_matrix(n / 2, temp);
        matrix_mul(temp, temp, matrix);
    }
    else
    {
        long long int temp1[2][2];
        long long int temp2[2][2];
        long long int A[2][2] = {3, 1, 1, 3};
        U_power_matrix(n / 2, temp1);
        matrix_mul(temp1, temp1, temp2);
        matrix_mul(temp2, A, matrix);
    }
}
// ###############################################################
//                      Benchmark Functions
// ###############################################################

long long int benchmark_recursive(long long int n)
{
    auto start = chrono::steady_clock::now();
    static_cast<void>(U_recursive(n));
    auto end = chrono::steady_clock::now();
    return chrono::duration_cast<chrono::nanoseconds>(end - start).count();
}

long long int benchmark_iterative(long long int n)
{
    auto start = chrono::steady_clock::now();
    static_cast<void>(U_iterative(n));
    auto end = chrono::steady_clock::now();
    return chrono::duration_cast<chrono::nanoseconds>(end - start).count();
}

long long int benchmark_power(long long int n)
{
    auto start = chrono::steady_clock::now();
    long long int matrix[2][2];
    static_cast<void>(U_power_matrix(n, matrix));
    auto end = chrono::steady_clock::now();
    return chrono::duration_cast<chrono::nanoseconds>(end - start).count();
}

// ###############################################################
//                            Main Loop
// ###############################################################

int main()
{
    freopen("benchmark_output.txt", "w", stdout);
    cout.precision(12);
    cout << fixed;

    // Recursive Benchmark

    for (int j = 1; j <= 20; j++)
    {
        cout << j << " ";
    }
    cout << endl;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 1; j <= 20; j++)
        {
            cout << benchmark_recursive(j) << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Iterative Benchmark
    for (int j = 1; j <= 10000; j += 500)
    {
        cout << j << " ";
        if (j == 1)
        {
            j = 0;
        }
    }
    cout << endl;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 1; j <= 10000; j += 500)
        {
            cout << benchmark_iterative(j) << " ";
            if (j == 1)
            {
                j = 0;
            }
        }
        cout << endl;
    }
    cout << endl;

    // Power Benchmark
    long long int n = 1;
    for (int j = 0; j < 16; j++)
    {
        cout << n << " ";
        n *= 10;
    }
    cout<<endl;
    for (int i = 0; i < 1000; i++)
    {
        long long int n = 1;
        for (int j = 0; j < 16; j++)
        
        {
            cout << benchmark_power(n) << " ";
            n *= 10;
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}