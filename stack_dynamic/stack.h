/**
 * estructura nodo almacena un elemento y apunta hacia otro Nodo
 */
struct Node 
{
    int element;
    struct Node * next;    
};

/**
 * implementa la funcionalidad basica de una pila
 */
struct Stack {    
    Node *top;    
};   

/**
 * push a new value onto top of stack 
 */    
void push(Stack *stack, int element);

/**
 */
int pop(Stack *stack);

/**
 * test if the stack is empty
 */
bool is_empty(Stack *stack);

/**
 */
// void print_stack(Stack *stack);