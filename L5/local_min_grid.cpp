// This Algorithm runs with O(log(n)
#include <iostream>
#define MAX_ARRAY_SIZE 100

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

int find_min_row(int n, int *arr, int m_col)
{
    int m_row = 0;
    int min = *(arr + m_col);
    for (int i = 0; i < n; i++)
    {
        if (min > *(arr + (i * n) + m_col))
        {
            min = *(arr + (i * n) + m_col);
            m_row = i;
        }
    }
    return m_row;
}

int main()
{
    freopen("local_min_grid_i.txt", "r", stdin);
    freopen("local_min_grid_o.txt", "w", stdout);
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
    int R = n - 1;
    bool found = false;
    int m_col;
    int m_row;
    while (!found)
    {
        m_col = L + R / 2;
        m_row = find_min_row(n, (int *)matrix, m_col);
        cout << m_row << " ";
        if (matrix[m_row][clamp(m_col - 1, 0, n - 1)] < matrix[m_row][m_col])
        {
            R = clamp(m_col - 1, 0, n - 1);
        }
        else if (matrix[m_row][clamp(m_col + 1, 0, n - 1)] < matrix[m_row][m_col])
        {
            L = clamp(m_col + 1, 0, n - 1);
        }
        else
        {
            found = true;
        }
    }
    cout << "Min is located at (" << m_col << ", " << m_row << ")" << endl;

    return 0;
}