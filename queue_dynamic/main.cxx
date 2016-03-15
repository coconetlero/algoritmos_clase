#include <stdio.h>
#include <assert.h>
#include <queue.h>

int main(int argc, char **argv)
{
    printf("Create the queue \n");
    
    Queue queue;
    queue.head = NULL;
    queue.tail = NULL;
    
    printf("Add element = 3 \n");
    enqueue(&queue, 3);
    
    printf("Add element = 5 \n");
    enqueue(&queue, 5);
    
    printf("Add element = 10 \n");
    enqueue(&queue, 10);
    
    int elem = dequeue(&queue);
    assert(elem);
    printf("Dequeue element = %d \n", elem);
    
    elem = dequeue(&queue);
    assert(elem);
    printf("Dequeue element = %d \n", elem);
    
    elem = dequeue(&queue);
    assert(elem);
    printf("Dequeue element = %d \n", elem);
    
    elem = dequeue(&queue);
    assert(elem);
    printf("Dequeue element = %d \n", elem);
}
