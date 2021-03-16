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

unsigned long long int U(long long int n)
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

int main()
{
    long long int n;
    cin >> n;

    cout << U(n) % 1000000007;

    return 0;
}
