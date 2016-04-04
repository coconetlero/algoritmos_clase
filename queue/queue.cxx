#include <stdio.h>
#include <stdlib.h>
#include <queue.h>

     

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
    if(!is_empty(queue))
    {
        for (int i = 0; i < queue->max_size; i++)
            {
                printf("%d ", *(queue->array + i));
            }    
        
        printf("\n\n"); 
    }
    else
    {
        printf("\n");
        printf("> The queue is empty");   
        printf("\n\n");
    }
         
}


