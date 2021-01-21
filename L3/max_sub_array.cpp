#include <iostream>
#include <time.h>

using namespace std;

int sum_sub_array(int a, int b, int arr[])
{
    int output = 0;
    for (int i = a; i < b; i++)
    {
        output += arr[i];
    }
    return output;
}

void brute(int n, int arr[], int output[])
{
    int largest_sum = 0;
    output[0] = 0;
    output[1] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int current_sum = sum_sub_array(i, j, arr);
            if (largest_sum < current_sum)
            {
                largest_sum = current_sum;
                output[0] = i;
                output[1] = j;
            }
        }
    }
}

int main()
{
    freopen("max_sub_array_i.txt", "r", stdin);
    freopen("max_sub_array_o.txt", "w", stdout);

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int algo;
    cin >> algo;
    clock_t start, end;
    int output[2] = {0};
    if (algo == 0)
    {
        start = clock();
        brute(n, arr, output);
        end = clock();
    }
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout<< "Largest sub array with sum " << sum_sub_array(output[0],output[1],arr)<<endl;
    for (int i = output[0]; i < output[1]; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Time Taken(s): " << time_taken << endl;
    cout << "Program has ended. \n";

        return 0;
}