struct Queue {
    int *array;
    int head;
    int tail;
    int max_size;
    int current_size;
};   

/**
 */
bool is_full(Queue *queue);

/**
 */
bool is_empty(Queue *queue);

/**
 */    
void enqueue(Queue *queue, int element);

/**
 */
int dequeue(Queue *queue);

/**
 */
void print_queue(Queue *queue);