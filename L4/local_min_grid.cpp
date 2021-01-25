#include <iostream>
#include <time.h>

using namespace std;

struct pos
{
    int x;
    int y;
    pos(int x1, int y1)
    {
        x = x1;
        y = y1;
    }
};

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
    freopen("local_min_grid_i.txt", "r", stdin);
    freopen("local_min_grid_o.txt", "w", stdout);

    int n;
    cin >> n;
    int matrix[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[j][i];
        }
    }

    int flag = 0;
    pos current_pos(n / 2, n / 2);

    /*
          a
        d x b
          c
    */
    while (flag == 0)
    {
        int a = matrix[current_pos.x][clamp(0, n, current_pos.y - 1)];
        int b = matrix[clamp(0, n, current_pos.x + 1)][current_pos.y];
        int c = matrix[current_pos.x][clamp(0, n, current_pos.y + 1)];
        int d = matrix[clamp(0, n, current_pos.x - 1)][current_pos.y];
        int x = matrix[current_pos.x][current_pos.y];
        if (a < x)
        {
            current_pos.y = current_pos.y - 1;
            continue;
        }
        if (b < x)
        {
            current_pos.x = current_pos.x + 1;
            continue;
        }
        if (c < x)
        {
            current_pos.y = current_pos.y + 1;
            continue;
        }
        if (d < x)
        {
            current_pos.x = current_pos.x - 1;
            continue;
        }
        flag == 1;
        break;
    }
    cout << "The position of local minima is (" << current_pos.x << "," << current_pos.y << ")" << endl;
    cout << "The value of the local minima is " << matrix[current_pos.x][current_pos.y];
    return 0;
}