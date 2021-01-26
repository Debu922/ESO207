#include <iostream>
#define MAX_ARRAY_SIZE 100

using namespace std;

int main()
{
    int n;
    cin >> n;
    int matrix[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int L = 0;
    int T = 0;
    int R = n;
    int B = n;

    return 0;
}