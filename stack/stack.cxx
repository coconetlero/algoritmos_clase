#include <stack.h>
#include <stdio.h>
#include <stdlib.h>


     

// ----------------------------------------------------------------------------        
bool is_full(Stack *stack)
{
    // si el último elemento esta la ultima posición del array
    if (stack->top == stack->max_size)
        return true;
    else
        return false;        
}        

// ----------------------------------------------------------------------------
void push(Stack *stack, int element)
{
    if(is_full(stack)) 
    { 
        stack->max_size *= 2; 
        stack->array = (int*)realloc(stack->array, sizeof(int) * stack->max_size);
    } 
    else 
    {        
        stack->array[stack->top++] = element;    
    }
}

// ----------------------------------------------------------------------------
int pop(Stack *stack)
{
    if (stack->top != 0)
    {
        stack->top--;
        return stack->array[stack->top];
    }
    return NULL;
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

