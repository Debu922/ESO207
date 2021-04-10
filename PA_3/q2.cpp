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
    int R, C;
    cin >> R >> C;
    int flat_mat[R * C];

    Queue *queue = createQueue(R * C);
    for (int i = 0; i < R * C; i++)
    {
        int x;
        cin >> x;
        flat_mat[i] = x;
        if (x == 2)
            queue->enqueue(i);
    }
    int day_infected[R*C] = {0};
    int largest_day = 0;
    while (!queue->isEmpty()){
        int i = queue->dequeue();
        if (i%R!=0){
            if (flat_mat[i-1]==1){
                queue->enqueue(i-1);
                flat_mat[i-1] = 2;
                day_infected[i-1] = day_infected[i]+1;
                if (day_infected[i-1] > largest_day)
                    largest_day = day_infected[i-1];
            }
        }
        if (i%R!=R-1){
            if (flat_mat[i+1]==1){
                queue->enqueue(i+1);
                flat_mat[i+1] = 2;
                day_infected[i+1] = day_infected[i]+1;
                if (day_infected[i+1] > largest_day)
                    largest_day = day_infected[i+1];
            }
        }
        if (i/R!=0){
            if (flat_mat[i-R]==1){
                queue->enqueue(i-R);
                flat_mat[i-R] = 2;
                day_infected[i-R] = day_infected[i]+1;
                if (day_infected[i-R] > largest_day)
                    largest_day = day_infected[i-R];
            }
        }
        if (i/R!=C-1){
            if (flat_mat[i+R]==1){
                queue->enqueue(i+R);
                flat_mat[i+R] = 2;
                day_infected[i+R] = day_infected[i]+1;
                if (day_infected[i+R] > largest_day)
                    largest_day = day_infected[i+R];
            }
        }
    }
    for (int i = 0; i<R*C; i++){
        if (flat_mat[i] == 1){
            cout<< -1;
            return 0;
        }
    }
    cout<<largest_day;
    return 0;
}