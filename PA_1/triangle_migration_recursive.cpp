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

int main()
{
    long long int n;
    cin >> n;

    cout << U_recursive(n) % 1000000007;

    return 0;
}
