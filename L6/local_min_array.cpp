#include <iostream>

using namespace std;

int clamp(int n, int a, int b)
{
    if (a > n)
    {
        return a;
    }
    if (b < n)
    {
        return b;
    }
    else
    {
        return n;
    }
}

int find_min_index(int n, int col, int **arr, bool column = true)
{
    int min_index = 0;
    int min;
    if (column)
    {
        min = arr[0][col];
        for (int i = 1; i < n; i++)
        {
            if (min > arr[i][col]){
                min_index = i;
                min=arr[i][col];
            }
        }
        return min_index;
    }
    else
    {
        min = arr[col][0];
        for (int i = 1; i < n; i++)
        {
            if (min > arr[col][i]){
                min_index = i;
                min=arr[col][i];
            }
        }
        return min_index;
    }
}

int main()
{
    int n;
    cin >> n;
    // Setup matrix
    int **arr = (int **)malloc(n * sizeof(int *));
    for (int r = 0; r < n; r++)
    {
        arr[r] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    int L = 0;
    int R = n - 1;
    int T = 0;
    int D = n - 1;
    
    int found = false;

    while(!found){
        
    }

    // Free Memory of matrix;
    for (int r = 0; r < n; r++)
    {
        free(arr[r]);
    }
    free(arr);
    return 0;
}