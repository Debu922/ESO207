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

class Node
{
public:
    int x;
    Node *l, *r;
};

Node *newNode(int value)
{
    Node *temp = new Node();
    temp->x = value;
    temp->l = NULL;
    temp->r = NULL;
    return temp;
}

void insert(Node *root, int x)
{
    if (root->x > x)
    {
        if (root->l == NULL)
        {
            root->l = newNode(x);
            return;
        }
        insert(root->l, x);
        return;
    }
    else
    {
        if (root->r == NULL)
        {
            root->r = newNode(x);
            return;
        }
        insert(root->r, x);
        return;
    }
}

int findLargestLessThan(Node *root, int x)
{
    Node *temp = root, *ans = NULL;
    while (temp != NULL)
    {
        if (temp->x < x)
        {
            ans = temp;
            temp = temp->r;
        }
        else
            temp = temp->l;
    }
    if (ans != NULL)
        return ans->x;
    return -1;
}

int main()
{
    int N;
    cin >> N;
    int A[N];
    int cumsum[N];
    int index[N] = {0};
    cin >> A[0];
    cumsum[0] = A[0];
    for (int i = 1; i < N; i++)
    {
        index[i] = i;
        cin >> A[i];
        cumsum[i] = cumsum[i - 1] + A[i];
    }

    int k;
    cin >> k;
    Node *root = newNode(cumsum[0]);
    int min = INT32_MAX;
    bool flag = true;
    for (int i = 1; i < N; i++)
    {
        int a = findLargestLessThan(root, cumsum[i] - k);
        insert(root, cumsum[i]);
        if (a != -1)
        {
            flag = false;
            int val = cumsum[i] - a;
            if (min > val)
                min = val;
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (cumsum[i] > k && cumsum[i] < min)
        {
            min = cumsum[i];
            flag = false;
        }
    }
    if (flag)
    {
        cout << -1;
        return 0;
    }
    cout << min;
    return 0;
}
