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

long long int get_leq_product(int M, int B[], int A_i, long long int x)
{
    int l = 0;
    int r = M - 1;
    long long int product = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (A_i * B[mid] < x)
        {
            product = mid + 1;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return product;
}

long long int check(int N, int M, int A[], int B[], long long int x)
{
    long long int product = 0;
    for (int i = 0; i < N; i++)
        product += get_leq_product(M, B, A[i], x);
    return product;
}

long long int get_k_product(int N, int M, int A[], int B[], int l, int r, long long int k)
{
    long long int product = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        long long int k_1 = check(N, M, A, B, mid);
        long long int k_2 = check(N, M, A, B, mid + 1);
        long long int count = k_2 - k_1;
        if (k_1 < k)
        {
            if (k_1 + count >= k)
            {
                product = mid;
                return product;
            }
            else
            {
                l = mid + 1;
            }
        }
        else
        {
            product = mid;
            r = mid - 1;
        }
    }
    return product;
}

int main()
{
    int N, M;
    long long int k;
    cin >> N >> M;
    int A[N];
    int B[M];
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < M; i++)
        cin >> B[i];
    cin >> k;
    int l = 1;
    int r = 10e8;
    int product = get_k_product(N, M, A, B, l, r, k);
    cout << product;
    return 0;
}