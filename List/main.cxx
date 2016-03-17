#include <stdio.h>
#include <linked_list.h>
#include <assert.h>


int main(int argc, char **argv)
{
    Linked_List list;
    list.head = NULL;
    
    add_last(&list, 5);
    add_last(&list, 7);
    add_last(&list, 21);
    
    printf("list size = %d \n", size(&list));
}