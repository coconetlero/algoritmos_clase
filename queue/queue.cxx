#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <queue.h>


// ----------------------------------------------------------------------------
Queue * create_queue(int size)
{
    int * array = (int *) malloc(sizeof(int) * size);
    assert(array != NULL);

    Queue *queue = new Queue;
    queue->array = array;
    queue->head = 0;
    queue->tail = 0;
    queue->max_size = size;
    queue->current_size = 0;

    return queue;
}

// ----------------------------------------------------------------------------
void clear_queue(Queue *queue)
{
    free(queue->array);
}

// ----------------------------------------------------------------------------
bool is_full(Queue *queue)
{
    if (queue->max_size == queue->current_size)
        return true;
    else
        return false;
}

// ----------------------------------------------------------------------------
bool is_empty(Queue *queue)
{
    if(queue->current_size == 0)
        return true;
    else
        return false;
}

// ----------------------------------------------------------------------------
int enqueue(Queue *queue, int data)
{
    if (!is_full(queue))
    {
        queue->array[queue->tail] = data;
        queue->tail++;
        queue->current_size++;

        if (queue->tail == queue->max_size)
        {
            queue->tail = 0;
        }
        return 1;
    }
    else
    {
        printf("Error - the queue if full \n");
        return NULL;
    }
}

// ----------------------------------------------------------------------------
int dequeue(Queue *queue)
{
    if(!is_empty(queue))
    {
        int data = queue->array[queue->head];
        queue->head++;
        queue->current_size--;

        if (queue->head == queue->max_size)
        {
            queue->head = 0;
        }
        return data;
    }
    else
    {
        printf("Error - the queue is empty \n");
        return NULL;
    }
}

// ----------------------------------------------------------------------------
void print_queue(Queue *queue)
{
    printf("Queue => [");
    for (int i = 0; i < queue->max_size - 1; i++)
    {
        printf("%d, ", *(queue->array + i));
    }
    printf("%d]", *(queue->array + queue->max_size - 1));
    printf("\n");
}
