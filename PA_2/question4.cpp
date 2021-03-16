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
    int depth;
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
        if(root->l == NULL)
        {
            root->l = newNode(x);
            return;
        }
        insert(root->l, x);
        return;
    }
    else
    {
        if(root->r == NULL)
        {
            root->r = newNode(x);
            return;
        }
        insert(root->r, x);
        return;
    }
}

Node *combined_bs(Node *root, int a, int b)
{
    // b > a
    Node *temp = root;
    while (temp != NULL)
    {
        int x = temp->x;
        if (b < x && a < x)
            temp = temp->l;
        else if (a > x && b > x)
            temp = temp->r;
        else
            return temp;
    }
    return NULL;
}

int depth_bs(Node *root, int a)
{
    int depth = 0;
    Node *temp = root;
    while (a != temp->x)
    {
        depth++;
        if (a < temp->x)
            temp = temp->l;
        else
            temp = temp->r;
    }
    return depth;
}

int main()
{
    int N, K;
    cin >> N >> K;
    
    int x;
    cin >> x ;
    Node *root = newNode(0);
    root->x = x;
    for (int i = 1; i < N; i++){
        cin >> x;
        insert(root,x);
    }

    for (int i = 0; i < K; i++)
    {
        int S;
        int E;
        cin >> S >> E;
        int a, b;
        if (S < E)
        {
            a = S;
            b = E;
        }
        else
        {
            b = S;
            a = E;
        }
        Node *temp = combined_bs(root, a, b);
        int d1 = depth_bs(temp, a);
        int d2 = depth_bs(temp, b);
        cout << d1 + d2 + 1 << endl;
    }
    return 0;
}