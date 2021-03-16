/* 
    #########################################
    # Solution by Debaditya Bhattacharya    #
    # Roll No: 190254                       #
    # Email-id: debbh@iitk.ac.in            #
    # Hackkerrank-id: @debbh922             #
    #########################################
*/
#include <iostream>
using namespace std;

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

int main()
{
    long long int n;
    cin >> n;
    long long int matrix[2][2];
    U_power_matrix(n, matrix);
    cout << matrix[0][0] << ", " << matrix[1][0];
    return 0;
}