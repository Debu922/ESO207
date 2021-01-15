#include <iostream>
#include <time.h>

using namespace std;

int Rpower(int x, long long int n, int m)
{
    if (n == 0)
        return 1;
    else
    {
        int temp = Rpower(x, n - 1, m);
        return (temp * x) % m;
    }
}

int Fpower(int x, long long int n, int m)
{
    if (n == 0)
        return 1;
    else if (n % 2 == 0)
    {
        int temp = Fpower(x, n / 2, m);
        return (temp * temp)%m ;
    }
    else
    {
        int temp = Fpower(x, n / 2, m);
        return (temp * temp * x)%m;
    }
}

int main()
{
    int x;
    long long int n;
    int m;
    int algorithm_type;
    int output;

    clock_t start, end;

    cout << "Enter x,n,m" << endl;
    cin >> x >> n >> m;
    cout << "Enter Algorithm (0 - Recursive, 1 - factored)" << endl;
    cin >> algorithm_type;

    if (algorithm_type == 0)
    {
        start = clock();
        output = Rpower(x, n, m);
        end = clock();
    }
    else
    {
        start = clock();
        output = Fpower(x, n, m);
        end = clock();
    }

    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);

    cout << "Output: " << output << endl;
    cout << "Time Taken(s): " << time_taken << endl;
    cout << "Program has ended. \n";

    return 0;
}