#include <stdio.h>
#include <stack.h>
#include <assert.h>


int main(int argc, char **argv)
{
    int * array = (int *) malloc(sizeof(int) * 10); 
    assert(array != NULL);

    Stack stack;
    stack.array = array;
    stack.top = 0;
    stack.max_size = 10;
    
    print_stack(&stack);
    
    push(&stack, 10);
    printf("push %d \n", 10);
    print_stack(&stack);
    
    push(&stack, 145);
    printf("push %d \n", 145);
    print_stack(&stack);
    
    push(&stack,38);
    printf("push %d \n", 38);
    print_stack(&stack);
    
    
    printf("given value is: %d \n", pop(&stack));
    print_stack(&stack);
    
    
    printf("given value is: %d \n", pop(&stack));
    print_stack(&stack);    
    
    
    printf("given value is: %d \n", pop(&stack));
    printf("given value is: %d \n", pop(&stack));
    printf("given value is: %d \n", pop(&stack));
    printf("given value is: %d \n", pop(&stack));
    print_stack(&stack);    
    
        
    push(&stack, 123);
    printf("push %d \n", 123);
    print_stack(&stack);    
    
    push(&stack, 215);
    printf("push %d \n", 215);
    print_stack(&stack);
        
    printf("given value is: %d \n", pop(&stack));
    printf("given value is: %d \n", pop(&stack));
        
    free(array);    
    return 0;    
}