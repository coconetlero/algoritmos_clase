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
// ----------------------------------------------------------------------------        
void enqueue(Queue *queue, int element)
{    
    if (!is_full(queue))
    {        
        if (is_empty(queue)) 
        {
            queue->tail = 0;
            queue->head = 0;    
            queue->array[queue->tail] = element;            
        } 
        else {
            if (queue->max_size-1 == queue->tail)
                 queue->tail = 0;
            else
                queue->tail++;

            queue->array[queue->tail] = element;
        }
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
void ejer01(Queue *queue)
{
    printf("\n");
    for (int j = 0; j < 12; j++)
    {
        for(int i = 0; i < 4; i++)
        {
            printf("%d ", *(queue->array + ((queue->head + i) % queue->max_size)));
        }
        enqueue(queue, dequeue(queue));
        printf("\n");             
    }    
        
    printf("\n\n");     
    
}

// ----------------------------------------------------------------------------  
void head_enqueue(Queue *queue, int element)
{
    if (!is_full(queue))
    {        
        if (is_empty(queue)) 
        {
            queue->tail = 0;
            queue->head = 0;    
            queue->array[queue->head] = element;            
        } 
        else {
            if (queue->head == 0)
                 queue->head = queue->max_size-1;
            else
                queue->head--;

            queue->array[queue->head] = element;
        }
        queue->current_size++;
    }
    else 
    {
        printf("Error - the queue if full \n");     
    }   
}

// ----------------------------------------------------------------------------  
int tail_dequeue(Queue *queue)
{
    if(!is_empty(queue))
    {
        int out = queue->array[queue->tail];
        queue->array[queue->tail] = 0;
        
        if(queue->tail == 0)
            queue->tail = queue->max_size-1;
        else
            queue->tail--;

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
int main()
{
    int _max_size = 12;

    int * array = (int *) malloc(sizeof(int) * _max_size); 
    assert(array != NULL);
        
    Queue queue;
    queue.array = array;
    queue.head = NULL;
    queue.tail = NULL;
    queue.max_size = _max_size;
    
    print_queue(&queue);
    
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    enqueue(&queue, 4);
    enqueue(&queue, 5);
    enqueue(&queue, 6);
    enqueue(&queue, 7);
    enqueue(&queue, 8);
    
    print_queue(&queue);
    
    printf("Letrero luminiso \n");
    
    // comprobacion ejercicio #1
    ejer01(&queue);
    
    // comprobacion ejercicio #2
    printf("Encolar por la cabeza \n");
    printf("Head = %d, Tail = %d \n", queue.head, queue.tail);
    print_queue(&queue);

    head_enqueue(&queue, 20);
    head_enqueue(&queue, 21);
    
    printf("Head = %d, Tail = %d \n", queue.head, queue.tail);
    print_queue(&queue);
    
    // comprobacion ejercicio #3
    printf("desencolar por la cola \n");
    printf("Head = %d, Tail = %d \n", queue.head, queue.tail);
    print_queue(&queue);

    int data;
    data = tail_dequeue(&queue);
    printf("dequeue value is: %d \n", data);
    
    data = tail_dequeue(&queue);
    printf("dequeue value is: %d \n", data);
    
    data = tail_dequeue(&queue);
    printf("dequeue value is: %d \n", data);
    
    printf("\n");
    printf("Head = %d, Tail = %d \n", queue.head, queue.tail);
    print_queue(&queue);
    
    
    
    free(array);
}
