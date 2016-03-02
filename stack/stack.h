
struct Stack {
    int *array;
    int top;
    int max_size;
};   

/**
 */
bool is_full(Stack *stack);

/**
 */    
void push(Stack *stack, int element);

/**
 */
int pop(Stack *stack);

/**
 */
void print_stack(Stack *stack);