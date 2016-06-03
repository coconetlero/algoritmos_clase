#include <stdio.h>
#include <linked_list.h>
#include <assert.h>


int main(int argc, char **argv)
{
    Linked_List *list = create_linked_list();
    
    printf("Add %d \n", 5);
    add_back(list, 5);
    printf("list size = %d \n", size(list));
    
    
    printf("Add %d \n", 7);
    add_back(list, 7);
    printf("list size = %d \n", size(list));
    
    
    printf("Add %d \n", 21);
    add_back(list, 21);
    printf("list size = %d \n", size(list));
    
    
    printf("Add %d in the thirth position \n", 11 );
    add(list, 2, 11);
    printf("list size = %d \n", size(list));
    
    printf("list = ");
    print_list(list);

    int elem = remove_front(list);
    assert(elem);
    printf("get head element = %d \n", elem);
    
    
    elem = remove_back(list);
    assert(elem);
    printf("get back element = %d \n", elem);
    
    printf("Add %d \n", 45);
    add_back(list, 45);
    
    printf("Add %d \n", 98);
    add_back(list, 98);
    
    print_list(list);       
    
    elem = remove(list, 2);
    assert(elem);
    printf("get 3rd element = %d \n", elem);
    
    elem = remove_front(list);
    assert(elem);
    printf("get head element = %d \n", elem);
           
    elem = remove_front(list);
    assert(elem);
    printf("get head element = %d \n", elem);
    
    print_list(list);       
    
    elem = remove_back(list);
    assert(elem);
    printf("get tail element = %d \n", elem);
    
    print_list(list);      
    
    free(list);
}