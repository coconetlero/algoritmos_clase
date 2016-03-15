#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stack.h>

// ----------------------------------------------------------------------------
void push(Stack *stack, int value)
{    
    Node *node = (Node*)malloc(sizeof(Node)); 
    assert(node);
    
    node->element = value;
    node->next = stack->top;
    stack->top = node;    
}

// ----------------------------------------------------------------------------
int pop(Stack *stack)
{
    if (!is_empty(stack)) 
    {
        Node *node = stack->top;
        int element = node->element;
        stack->top = node->next;
        
        free(node);
        return element;
    }
    else {
        printf("Error the stack is empty \n");    
        return NULL;
    }
    
}

// ----------------------------------------------------------------------------
bool is_empty(Stack *stack)
{
    if(stack->top == NULL)
        return true;
    else
        return false;
}