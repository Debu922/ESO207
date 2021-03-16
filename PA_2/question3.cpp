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

class Box
{
public:
    int index;
    int value;
};

void merge_and_count_inversions(Box A[], int i, int mid, int k, Box C[], int counts[])
{
    int p = i;
    int j = mid + 1;
    int r = 0;
    while (p <= mid && j <= k)
    {
        if (A[p].value < A[j].value)
        {
            C[r] = A[p];
            r++;
            p++;
        }
        else
        {
            C[r] = A[j];
            counts[A[j].index] += mid - p + 1;
            j++;
            r++;
        }
    }
    while (p <= mid)
    {
        C[r] = A[p];
        r++;
        p++;
    }
    while (j <= k)
    {
        C[r] = A[j];
        r++;
        j++;
    }
    for (int x = 0; x < k-i+1;x++){
        A[i+x] = C[x];
    }
}

void sort_and_count_inversions(Box A[], int i, int k, int counts[])
{
    if (i == k)
    {
        return;
    }
    else
    {
        int mid = (i + k) / 2;
        sort_and_count_inversions(A, i, mid, counts);
        sort_and_count_inversions(A, mid+1, k, counts);
        Box C[k - i + 1];
        merge_and_count_inversions(A, i, mid, k, C, counts);
    }
}

int main()
{
    int N;
    cin >> N;
    Box A[N];
    int counts[N] = {0};
    for (int i = 0; i < N; i++)
    {
        cin >> A[i].value;
        A[i].index = i;
    }
    sort_and_count_inversions(A, 0, N - 1, counts);
    for (int i = 0; i < N; i++)
    {
        cout << counts[i] << " ";
    }
    return 0;
}