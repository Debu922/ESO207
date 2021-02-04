#include <iostream>

using namespace std;

struct arrayList
{
    int size;
    int *arr;
    arrayList(int n)
    {
        size = n;
        if (size)
        {
            arr = (int *)malloc(sizeof(int) * n);
            for (int i = 0; i < size; i++)
            {
                arr[i] = 0;
            }
        }
        else
        {
            arr = NULL;
        }
    }
    void insert(int x, int p)
    {
        size++;
        int *temp_arr = (int *)malloc(sizeof(int) * size);
        if (size == 1)
        {
            arr = temp_arr;
            arr[0] = x;
            return;
        }
        for (int i = 0; i < p; i++)
        {
            temp_arr[i] = arr[i];
        }
        temp_arr[p] = x;
        for (int i = p + 1; i < size; i++)
        {
            temp_arr[i] = arr[i - 1];
        }

        free(arr);
        arr = temp_arr;
    }
    void del(int p)
    {
        size--;
        if (size == 0)
        {
            free(arr);
            arr = NULL;
            return;
        }

        int *temp_arr = (int *)malloc(sizeof(int) * size);
        for (int i = 0; i < p; i++)
        {
            temp_arr[i] = arr[i];
        }
        for (int i = p; i < size; i++)
        {
            temp_arr[i] = arr[i + 1];
        }
        free(arr);
        arr = temp_arr;
    }
    void append(int x)
    {
        insert(x, size);
    }
    void makeListEmpty(){
        free(arr);
        arr = NULL;
        size = 0;
    }
    bool isEmpty(){
        return !size;
    }
    int successor(int p){
        return arr[p+1];
    }
    int predecessor(int p){
        return arr[p-1];
    }
    void print()
    {
        cout << "Size: " << size << endl;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    int search(int x){
        bool found = false;
        int index = 0;
        while (index < size){
            if (arr[index] == x)
            return index;
            index++;
        }
        cout<<"No such entry"<<endl;
        return -1;
    }
};

int main()
{
    freopen("array_list_i.txt", "r", stdin);
    freopen("array_list_o.txt", "w", stdout);
    arrayList list(0);
    int input;
    cin >> input;
    while (input != -1)
    {
        list.append(input);
        cin >> input;
    }
    list.print();
    list.del(2);
    list.print();
    list.insert(100,4);
    list.print();
    cout<<list.search(100)<<endl;
    cout<<list.search(20);
    list.makeListEmpty();
    list.print();
    return 0;
}