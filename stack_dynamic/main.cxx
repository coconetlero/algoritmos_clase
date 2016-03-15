#include <stdio.h>
#include <assert.h>
#include <stack.h>

int main(int argc, char **argv)
{
    printf("Create stack \n");
    
    Stack stack;
    stack.top = NULL;
    
    printf("Add element = 5 \n");
    push(&stack, 5);
    
    printf("Add element = 6 \n");
    push(&stack, 6);
    
    int elem = pop(&stack);
    assert(elem);
    printf("Pop element = %d \n", elem);
    
    elem = pop(&stack);
    assert(elem);
    printf("Pop element = %d \n", elem);
    
    elem = pop(&stack);
    assert(elem);
    printf("Pop element = %d \n", elem);    
}
