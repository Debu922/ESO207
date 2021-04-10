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

class Queue
{
public:
    int front, rear, length;
    int size;
    int *array;
    bool isFull()
    {
        return size == length;
    }
    bool isEmpty()
    {
        return length == 0;
    }
    void enqueue(int x)
    {
        if (isFull())
            return;
        rear = (rear + 1) % size;
        array[rear] = x;
        length++;
    }
    int dequeue()
    {
        if (isEmpty())
            return INT32_MIN;
        int x = array[front];
        front = (front + 1) % size;
        length--;
        return x;
    }
};

Queue *createQueue(int size)
{
    Queue *queue = new Queue();
    queue->size = size;
    queue->front = queue->length = 0;

    queue->rear = size - 1;
    queue->array = new int[size];
    return queue;
}

int main()
{
    int m, n;
    cin >> n >> m;
    int flat_mat[m * n];
    int visited[m * n] = {0};

    for (int i = 0; i < m * n; i++)
    {
        int x;
        cin >> x;
        flat_mat[i] = x;
    }

    int current_island = 0;
    Queue *queue = createQueue(m * n);

    for (int i = 0; i < m * n; i++)
    {
        if (flat_mat[i] == 0)
            continue;
        if (visited[i] == 0)
        {
            current_island++;
            queue->enqueue(i);
            visited[i] = current_island;
        }
        while (!queue->isEmpty())
        {
            int i = queue->dequeue();
            if (i % m != 0)
            {
                if (flat_mat[i - 1] == 1 && visited[i - 1] == 0)
                {
                    queue->enqueue(i - 1);
                    visited[i - 1] = current_island;
                }
            }
            if (i % m != m - 1)
            {
                if (flat_mat[i + 1] == 1 && visited[i + 1] == 0)
                {
                    queue->enqueue(i + 1);
                    visited[i + 1] = current_island;
                }
            }
            if (i / m != 0)
            {
                if (flat_mat[i - m] == 1 && visited[i - m] == 0)
                {
                    queue->enqueue(i - m);
                    visited[i - m] = current_island;
                }
            }
            if (i / m != n - 1)
            {
                if (flat_mat[i + m] == 1 && visited[i + m] == 0)
                {
                    queue->enqueue(i + m);
                    visited[i + m] = current_island;
                }
            }
        }
    }
    cout << current_island;
    return 0;
}