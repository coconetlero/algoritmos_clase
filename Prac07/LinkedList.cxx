#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/**
 * estructura nodo almacena un elemento y apunta hacia otro Nodo
 */
struct Node 
{
    int element;
    struct Node * next;    
};

/**
 * Implements the functionality of a dynamic List 
 */
struct Linked_List { 
    Node *head;   
};

// ----------------------------------------------------------------------------
// ---------------------------------------------------------------------------- 

bool is_empty(Linked_List *list)
{
    if (list->head == NULL)
        return true;
    else
        return false;
}

// ----------------------------------------------------------------------------
int size(Linked_List *list) 
{
    Node *current = list->head;
    if(is_empty(list))
    {
        return 0;
    }
    else {
        int counter = 1;
        while(current->next != NULL)
        {
            counter++;
            current = current->next;
        }
        return counter;                
    }    
}

// ----------------------------------------------------------------------------
void add_last(Linked_List *list, int _element)
{
    Node *node = (Node*)malloc(sizeof(Node)); 
    assert(node);
    
    node->element = _element;
    
    if (is_empty(list))
    {
        list->head = node;        
        node->next = NULL;
    }
    else {    
        Node *current = list->head;
        int counter = 1;
        while(current->next != NULL)
        {   
            counter++;
            current = current->next;
        }            
        current->next = node;           
        node->next == NULL;
    }   
}

// ----------------------------------------------------------------------------
int get_first(Linked_List *list) 
{
    if (!is_empty(list))
    {
        Node *node = list->head;
        int out = node->element;
        list->head = node->next;
        free(node);
        
        return out;            
    }
    else {
        printf("Error: the list is empty \n");    
        return NULL;
    }
}

void print_list(Linked_List *list)
{
    Node *current = list->head;
    printf("[");
    while(current != NULL)
    {
        int data = current->element;
        if (current ->next == NULL)
            printf("%d", data);
        else    
            printf("%d, ", data);
        
        current = current->next;
    }
    printf("]\n");
}

// ----------------------------------------------------------------------------
// -------------------------------  Main  -------------------------------------
// ----------------------------------------------------------------------------
int main(int argc, char **argv)
{
    Linked_List list;
    list.head = NULL;
    
    printf("Add %d \n", 5);
    add_last(&list, 5);
    
    printf("Add %d \n", 7);
    add_last(&list, 7);
    
    printf("Add %d \n", 21);
    add_last(&list, 21);
    
    printf("list = "); 
    print_list(&list);
    
    printf("\n");
    

    int elem = get_first(&list);
    assert(elem);
    printf("get head element = %d \n", elem);
    printf("list = "); 
    print_list(&list);
    
    elem = get_first(&list);
    assert(elem);
    printf("get head element = %d \n", elem);
    printf("list = "); 
    print_list(&list);
    
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