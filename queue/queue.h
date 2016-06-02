struct Queue {
    int *array;
    int head;
    int tail;
    int max_size;
    int current_size;
};

/**
*/
Queue * create_queue(int size);

/**
*/
void clear_queue(Queue *queue);

/**
 */
bool is_full(Queue *queue);

/**
 */
bool is_empty(Queue *queue);

/**
 * Inserts the specified element into this queue, if the capacity allows this
 * operation. By definition the data is appended to the queue.
 */
int enqueue(Queue *queue, int element);

/**
 * Retrieves the head of this Queue.
 */
int dequeue(Queue *queue);

/**
 */
void print_queue(Queue *queue);
