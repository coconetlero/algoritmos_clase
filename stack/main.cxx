#include <stdio.h>
#include <stack.h>



int main(int argc, char **argv)
{
    Stack * stack = create_stack(10);
    
    print_stack(stack);
    
    push(stack, 10);
    printf("push %d \n", 10);
    print_stack(stack);
    
    push(stack, 145);
    printf("push %d \n", 145);
    print_stack(stack);
    
    push(stack,38);
    printf("push %d \n", 38);
    print_stack(stack);
    
    printf("Pop \n");
    printf("given value is: %d \n", pop(stack));
    
    printf("Pop \n");
    printf("given value is: %d \n", pop(stack));
    
    printf("Pop \n");
    printf("given value is: %d \n", pop(stack));
    
    printf("Pop \n");    
    printf("given value is: %d \n", pop(stack));
    
    print_stack(stack);        
        
    push(stack, 123);
    printf("push %d \n", 123);
    print_stack(stack);    
    
    push(stack, 215);
    printf("push %d \n", 215);
    print_stack(stack);

    printf("Pop \n");
    printf("given value is: %d \n", pop(stack));
    printf("Pop \n");
    printf("given value is: %d \n", pop(stack));
        
    destroy_stack(stack);  
    return 0;    
}