#include <stdio.h>
#include <linked_list.h>
#include <assert.h>


int main(int argc, char **argv)
{
    Linked_List *list = create_linked_list();
    
    printf("Add %d \n", 5);
    add_last(list, 5);
    printf("list size = %d \n", size(list));
    
    
    printf("Add %d \n", 7);
    add_last(list, 7);
    printf("list size = %d \n", size(list));
    
    
    printf("Add %d \n", 21);
    add_last(list, 21);
    printf("list size = %d \n", size(list));
    
    
    printf("Add %d in the thirth position \n", 11 );
    add(list, 2, 11);
    printf("list size = %d \n", size(list));
    
    
    printf("\n");
    printf("list = ");
    print_list(list);
    printf("\n");
    
    int elem = remove_first(list);
    assert(elem);
    printf("get head element = %d \n", elem);
    
    
    elem = remove_first(list);
    assert(elem);
    printf("get head element = %d \n", elem);
    
    
    elem = remove_first(list);
    assert(elem);
    printf("get head element = %d \n", elem);
    
    
    elem = remove_first(list);
    assert(elem);
    printf("get head element = %d \n", elem);
    
    
    elem = remove_first(list);
    assert(elem);
    printf("get head element = %d \n", elem);
    
}