#include<iostream>

void matrix_mul(int a[2][2], int b[2][2], int result[2][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < 2; k++)
            {
                result[i][j] += a[i][k] * b[k][j];
                result[i][j] %= 2020;
            }
        }
    }
}

int main(){
    int a[2][2] = {1,20,300,400};
    int b[2][2] = {1,1,1,1};
    int result[2][2] = {-1,-1,-1,-1};
    matrix_mul(a,b,result);
    std::cout<<result;
    return 0;
}