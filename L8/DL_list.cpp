#include <iostream>

using namespace std;

class DLL
{
    class Node
    {
    public:
        int data;
        Node *left;
        Node *right;
    };

public:
    Node *head;
    Node *tail;
    DLL()
    {
        (head) = NULL;
        (tail) = NULL;
    }

    int size = 0;

    void insert(int x, Node *p)
    {
        if (p == NULL)
        {
            cout << "Cannot insert before empty node" << endl;
            return;
        }
        Node *newNode = new Node();
        newNode->data = x;
        newNode->right = p;
        newNode->left = p->left;
        p->left = newNode;
        if (newNode->left != NULL)
        {
            newNode->left->right = newNode;
        }
        else
        {
            (head) = newNode;
        }
        size++;
    }
    void append(int x)
    {
        Node *newNode = new Node();
        newNode->data = x;
        if (tail == NULL)
        {
            newNode->left = NULL;
        }
        else
        {
            newNode->left = tail;
        }
        newNode->right = NULL;
        (tail) = newNode;
        if (newNode->left != NULL)
        {
            newNode->left->right = newNode;
        }
        else
        {
            (head) = newNode;
        }
        size++;
    }
    Node *search(int x)
    {
        Node *currentNode = (head);
        while (currentNode != NULL)
        {
            if (currentNode->data == x)
                return currentNode;
        }
        cout << "Number does not exist in list." << endl;
        return NULL;
    }
    void print()
    {
        cout << "Size: " << size << endl;
        Node *currentNode = (head);
        while (currentNode != NULL)
        {
            cout << currentNode->data << " ";
            currentNode = currentNode->right;
        }
        cout<<endl;
    }
    void makeListEmpty()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    void del(Node *p)
    {
        if (p->left != NULL && p->right != NULL)
        {
            p->left->right = p->right;
            p->right->left = p->left;
            delete (p);
        }
        else if (p->left != NULL && p->right == NULL)
        {
            p->left->right = NULL;
            tail = p->left;
            delete(p);
        }
        else if (p->left == NULL && p->right != NULL)
        {
            p->right->left = NULL;
            head = p->right;
        }
        else
        {
            makeListEmpty();
            delete(p);
        }
        size--;
    }
    bool isEmpty()
    {
        return !size;
    }
};

int main()
{
    DLL list;
    list.append(2);
    list.append(3);
    list.insert(1, list.search(2));
    list.print();
    list.del(list.head);
    list.print();
    list.makeListEmpty();
    list.print();
    return 0;
}
