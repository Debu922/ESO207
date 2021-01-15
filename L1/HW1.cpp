#include <iostream>
#include <time.h>

using namespace std;

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
        for (long long int i = 2; i <= n; i++)
        {
            int temp = b;
            b = a + b;
            a = temp % 2020;
        }
        return a;
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
    cout << "\nPlease input desired algorithm (0 == Iterative (def),1 == Recursive): ";
    cin >> algorithm_type;

    if (algorithm_type == 1)
    {
        start = clock();
        output = Rfib(n);
        end = clock();
    }
    else
    {
        start = clock();
        output = Ifib(n);
        end = clock();
    }

    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);

    cout << "Output: " << output << endl;
    cout << "Time Taken(s): " << time_taken << endl;

    cout << "Program has ended. \n";
    return 0;
}