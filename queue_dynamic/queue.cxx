#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <queue.h>

// ----------------------------------------------------------------------------
bool is_empty(Queue *queue) 
{
    if (queue->head == NULL)
        return true;
    else
        return false;
}

// ----------------------------------------------------------------------------
void enqueue(Queue *queue, int _element)
{
    Node *node = (Node*)malloc(sizeof(Node)); 
    assert(node);
    
    node->element = _element;
    
    if (is_empty(queue))
    {
        queue->head = node;
        queue->tail = node;
        node->next = NULL;
    }
    else {        
        node->next = NULL;
        queue->tail->next = node;
        queue->tail = node;
    }    
}

// ----------------------------------------------------------------------------
int dequeue(Queue *queue)
{
    if (!is_empty(queue))
    {
        Node *node = queue->head;
        int element = node->element;
        queue->head = node->next;
        
        free(node);
        return element;
    }
    else {
        printf("Error: the queue is empty \n");    
        return NULL;
    }
}