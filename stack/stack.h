
struct Stack {
    int *array;
    int top;
    int max_size;
};   


/**
 * Create an instace of a Stack and points to it.
 */
Stack * create_stack(int size);

/**
 * Frees the memory occupied by the stack
 */
void destroy_stack(Stack *stack);

/**
 * Add one element to the top of the stack
 */    
void push(Stack *stack, int element);

/**
 * Return and remove the element at the top of the stack
 */
int pop(Stack *stack);

/**
 * Print the given stack
 */
void print_stack(Stack *stack);