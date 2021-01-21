#include <iostream>
#include <time.h>

using namespace std;

int find_min_index(int a, int b, int arr[])
{
    int index = a;
    for (int i = a; i < b; i++)
    {
        if (arr[index] > arr[i])
            index = i;
    }
    return index;
}

void selection_sort(int n, int arr[]) // # n(n-1)/2
{
    for (int i = 0; i < n; i++) 
    {
        int index = find_min_index(i, n, arr); 
        int temp = arr[i];
        arr[i] = arr[index];
        cout << index << " ";
        arr[index] = temp;
    }
}

int main()
{
    int n;
    cout << "Enter number of terms" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int algo = 0;
    cout << "Choose Algorithm: 0-Selection";
    cin >> algo;

    clock_t start, end;

    if (algo == 0)
    {
        start = clock();
        selection_sort(n, arr);
        end = clock();
    }

    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);

    cout << "Output: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Time Taken(s): " << time_taken << endl;
    cout << "Program has ended. \n";

    return 0;
}