/**
 * estructura nodo almacena un elemento y apunta hacia otro Nodo
 */
struct Node 
{
    int element;
    struct Node * next;    
};

/**
 * Implements the functionality of a dynamic Queue 
 */
struct Queue { 
    Node *head;   
    Node *tail;
};   

/**
 * test if the Queue is empty
 */
bool is_empty(Queue *queue);

/**
 * Enqueue one element to the queue
 */    
void enqueue(Queue *queue, int _element);

/**
 * Dequeue one element to the queue
 */
int dequeue(Queue *queue);