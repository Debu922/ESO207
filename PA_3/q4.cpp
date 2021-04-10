#/* 
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
    Node *l;
    Node *r;
};

class Stack
{
public:
    int top;
    int size;
    Node **array;
    bool isFull()
    {
        return top == size - 1;
    }
    bool isEmpty()
    {
        return top == -1;
    }
    void push(Node *node)
    {
        if (isFull())
            return;
        array[++top] = node;
    }
    Node *pop()
    {
        if (isEmpty())
            return NULL;
        return array[top--];
    }
    Node *peek()
    {
        return array[top];
    }
} stack;

Node *newNode(int x)
{
    Node *temp = new Node();
    temp->x = x;
    temp->l = NULL;
    temp->r = NULL;
    return temp;
}

Stack *create_stack(int size)
{
    Stack *stack = new Stack();
    stack->top = -1;
    stack->size = size;
    stack->array = new Node *[stack->size * sizeof(Node *)];
    return stack;
}

Node *construct_bst(int N)
{
    Stack *stack = create_stack(N);
    int x;
    cin >> x;
    Node *root = newNode(x);

    stack->push(root);

    Node *temp;

    for (int i = 1; i < N; i++)
    {
        cin >> x;
        temp = NULL;

        while (!stack->isEmpty() && x > stack->peek()->x)
            temp = stack->pop();

        if (temp != NULL)
        {
            temp->r = newNode(x);
            stack->push(temp->r);
        }

        else
        {
            stack->peek()->l = newNode(x);
            stack->push(stack->peek()->l);
        }
    }

    return root;
}

void print_preorder(Node *node)
{
    if (node == NULL)
        return;
    cout << node->x << " ";
    print_preorder(node->l);
    print_preorder(node->r);
}

bool bs(Node *root, int x)
{
    if (root == NULL)
        return false;
    if (root->x == x){
        return true;
    }
    if (root->x > x)
    {
        return bs(root->l, x);
    }
    else
    {
        return bs(root->r, x);
    }
}

void dfs(Node *root1, Node *root2, int k, int *count)
{
    if (root1 == NULL)
        return;
    *count += bs(root2, k - root1->x);
    dfs(root1->l, root2, k, count);
    dfs(root1->r, root2, k, count);
}

int main()
{
    int n1, n2, k;
    cin >> n1;
    Node *root1 = construct_bst(n1);
    cin >> n2;
    Node *root2 = construct_bst(n2);
    cin >> k;
    int count = 0;
    dfs(root1, root2, k, &count);
    cout<<count;
    return 0;
}