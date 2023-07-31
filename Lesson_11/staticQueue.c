#include <stdio.h>
#include <stdlib.h>

typedef struct Data
{
    int data;
} Data;

typedef struct Queue
{
    Data *arr;
    size_t capacity;
    size_t top;
    size_t bottom;
} Queue;

int enqueue(Queue *queue, Data data);
int dequeue(Queue *queue, Data *data);
void init_static_queue(Queue *queue, size_t max_elem);
void printElements();

// |4| <-top
// |3|
// |2|
// |1| <-bottom

// top
//  |     bottom
//  |     |
// |4|3|2|1| | | |

int main(void)
{
    Queue queue;
    init_static_queue(&queue, 3);
    // for (size_t i = 1; i < 3; i++)
    // {
    //     Data data = {i};
    //     enqueue(&queue, data);
    // }
    Data d = {100};
    enqueue(&queue, d);
    printElements(&queue);
    dequeue(&queue, &d);
    printElements(&queue);
    free(queue.arr);
    return 0;
}

void init_static_queue(Queue *queue, size_t max_elem)
{
    queue->capacity = max_elem;
    queue->arr = malloc((*queue).capacity * sizeof(queue->arr[0]));
    queue->top = 0;
    queue->bottom = -1;
}

int enqueue(Queue *queue, Data data)
{
    if (queue->bottom == -1)
    {
        queue->bottom++;
        *(queue->arr + (queue->bottom % queue->capacity)) = data;
        queue->bottom++;
        return 0;
    }
    if (queue->bottom - queue->top < queue->capacity)
    {
        *(queue->arr + (queue->bottom % queue->capacity)) = data;
        queue->bottom++;
        return 0;
    }
    printf("IndexOutOfRangeException: The queue is full.\n");
    return 1;
}

int dequeue(Queue *queue, Data *data)
{
    if (queue->top < queue->bottom)
    {
        *data = *(queue->arr + (queue->top % queue->capacity));
        queue->top++;
        return 0;
    }
    printf("Cannot pop out of empty queue.\n");
    return 1;
}

void printElements(Queue *queue)
{
    for (size_t i = 0; i < queue->bottom; i++)
    {
        if (i < queue->top || i > queue->bottom)
            printf("_ ");
        else
            printf("%d ", queue->arr[i].data);
    }
    printf("\n");
}