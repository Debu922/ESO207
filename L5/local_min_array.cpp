#include <iostream>

using namespace std;

int clamp(int a, int b, int i)
{
    if (i < a)
    {
        return a;
    }
    else if (i >= b)
    {
        return b;
    }
    else
    {
        return i;
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    bool is_min = false;
    int L = 0;
    int R = n;
    int x;
    while (!is_min)
    {
        x = (L + R) / 2;
        if (arr[x] > arr[clamp(0, n, x - 1)])
        {
            R = x;
            continue;
        }
        else if (arr[x] > arr[clamp(0, n, x + 1)])
        {
            L = x+1;
            continue;
        }
        else
        {
            is_min = true;
        }
    }
    cout<<"Index of local min: "<<x<<" Local minima value: "<<arr[x]<<endl;

    return 0;
}