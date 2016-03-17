#include <stdio.h>
#include <linked_list.h>
#include <assert.h>


int main(int argc, char **argv)
{
    Linked_List list;
    list.head = NULL;
    
    printf("Add %d \n", 5);
    add_last(&list, 5);
    printf("list size = %d \n", size(&list));
    
    printf("Add %d \n", 7);
    add_last(&list, 7);
    printf("list size = %d \n", size(&list));
    
    printf("Add %d \n", 21);
    add_last(&list, 21);
    printf("list size = %d \n", size(&list));
    
    printf("Add %d in the rigth position \n", 11 );
    add(&list, 2, 11);
    printf("list size = %d \n", size(&list));
    
    printf("\n\n");
    
    int elem = get_first(&list);
    assert(elem);
    printf("get head element = %d \n", elem);
    
    elem = get_first(&list);
    assert(elem);
    printf("get head element = %d \n", elem);
    
    elem = get_first(&list);
    assert(elem);
    printf("get head element = %d \n", elem);
    
    elem = get_first(&list);
    assert(elem);
    printf("get head element = %d \n", elem);
    
    elem = get_first(&list);
    assert(elem);
    printf("get head element = %d \n", elem);
    
}