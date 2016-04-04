#include <stdio.h>
#include <assert.h>
#include <queue.h>


int main(int argc, char **argv)
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
    
    
    print_queue(&queue);
    printf("Head = %d, Tail = %d \n", queue.head, queue.tail);
    
    printf("given value is: %d \n", dequeue(&queue));
    printf("given value is: %d \n", dequeue(&queue));
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
    printf("Head = %d, Tail = %d \n", queue.head, queue.tail);
    
    printf("dequeue given value is: %d \n", dequeue(&queue));
    printf("dequeue given value is: %d \n", dequeue(&queue));
    printf("Head = %d, Tail = %d \n", queue.head, queue.tail);
    
    printf("dequeue given value is: %d \n", dequeue(&queue));
    printf("dequeue given value is: %d \n", dequeue(&queue));
    printf("Head = %d, Tail = %d \n", queue.head, queue.tail);
    
    free(array);
}