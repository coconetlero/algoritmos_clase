#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Queue {
    int *array;
    int head;
    int tail;
    int max_size;
    int current_size;
};   


// ----------------------------------------------------------------------------        
bool is_full(Queue *queue)
{
    if(queue->max_size == queue->current_size)
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
void enqueue(Queue *queue, int element)
{    
    if(!is_full(queue))
    {        
        queue->array[queue->tail] = element;
        if(queue->max_size-1 == queue->tail)
            queue->tail = 0;
        else
            queue->tail++;

        queue->current_size++;
    }
    else 
    {
        printf("Error - the queue if full \n");     
    }    
}

// ----------------------------------------------------------------------------        
int dequeue(Queue *queue)
{
    if(!is_empty(queue))
    {
        int out = queue->array[queue->head];
        queue->array[queue->head] = 0;
        
        if(queue->max_size-1 == queue->head)
            queue->head = 0;
        else
            queue->head++;

        queue->current_size--;
        return out;
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
    printf("\n");
    
    for (int i = 0; i < queue->max_size; i++)
    {
        printf("%d ", *(queue->array + i));
    }    
        
    printf("\n\n"); 

}


// ----------------------------------------------------------------------------  
int main()
{
    int _max_size = 5;

    int * array = (int *) malloc(sizeof(int) * _max_size); 
    assert(array != NULL);
        
    Queue queue;
    queue.array = array;
    queue.head = 0;
    queue.tail = 0;
    queue.max_size = _max_size;
    
    
    
    print_queue(&queue);
    
    enqueue(&queue, 5);
    printf("Enqueue %d \n", 5);
    enqueue(&queue, 10);
    printf("Enqueue %d \n", 10);
    enqueue(&queue, 7);
    printf("Enqueue %d \n", 7);
    
    int value;
    value = dequeue(&queue);    
    printf("dequeue value is: %d \n", value);
    value = dequeue(&queue);    
    printf("dequeue value is: %d \n", value);
    value = dequeue(&queue);    
    printf("dequeue value is: %d \n", value);
    
    
    
    printf("The list is: \n");
    print_queue(&queue);
    
    printf("Head = %d, Tail = %d \n", queue.head, queue.tail);
    
    enqueue(&queue, 5);
    printf("Enqueue %d \n", 5);
    enqueue(&queue, 10);
    printf("Enqueue %d \n", 10);
    enqueue(&queue, 7);
    printf("Enqueue %d \n", 7);
    
    printf("The list is: \n");
    print_queue(&queue);
    
    
    printf("Head = %d, Tail = %d \n", queue.head, queue.tail);
    
    printf("dequeue value is: %d \n", dequeue(&queue));
    printf("dequeue value is: %d \n", dequeue(&queue));
    printf("Head = %d, Tail = %d \n", queue.head, queue.tail);
    
    print_queue(&queue);
    
    enqueue(&queue, 25);
    printf("Enqueue %d \n", 25);
    enqueue(&queue, 32);
    printf("Enqueue %d \n", 32);
    
    printf("Head = %d, Tail = %d \n", queue.head, queue.tail);
    
    print_queue(&queue);
    
    printf("Enqueue %d \n", 50);
    enqueue(&queue, 50);
    
    print_queue(&queue);
    printf("Head = %d, Tail = %d \n", queue.head, queue.tail);
    
    printf("Enqueue %d \n", 380);
    enqueue(&queue, 380);
    
    print_queue(&queue);
    printf("Head = %d, Tail = %d \n", queue.head, queue.tail);
    
    printf("Enqueue %d \n", 22);
    enqueue(&queue, 22);
    print_queue(&queue);
   
    free(array);
}
