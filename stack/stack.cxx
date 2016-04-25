#include <stack.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// ----------------------------------------------------------------------------      
Stack * create_stack(int size)
{
    int * array = (int *) malloc(sizeof(int) * size); 
    assert(array != NULL);

    Stack *stack = new Stack;
    stack->array = array;
    stack->top = -1;
    stack->max_size = size;
    
    return stack;
}
     
// ---------------------------------------------------------------------------- 
void destroy_stack(Stack *stack)
{
    stack->top = NULL;
    stack->max_size = NULL;
    free(stack->array);    
}

// ----------------------------------------------------------------------------
void push(Stack *stack, int element)
{
    // if the stack is full, then grow it to the double 
    if (stack->top == (stack->max_size - 1))
    { 
        stack->max_size *= 2; 
        stack->array = (int*)realloc(stack->array, sizeof(int) * stack->max_size);
        stack->top++;
        stack->array[++stack->top] = element;  

    } 
    else 
    {        
        stack->top++;
        stack->array[stack->top] = element;    
    }
}

// ----------------------------------------------------------------------------
int pop(Stack *stack)
{
    // if the stack is not empty, then return the value at the top
    if (stack->top >= 0)
    {
        int data = stack->array[stack->top];
        stack->top--;
        return data;
    }
    else {
        printf("Error the stack is empty \n");
        return NULL;
    }
    
}

// ----------------------------------------------------------------------------
void print_stack(Stack *stack)
{
    for (int i = 0; i < stack->max_size; i++)
        {
            printf("%d ", *(stack->array + i));
        }    
        
    printf("\n");    
}

