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
            current = current->next;
            counter++;
        }            
        current->next = node;           
        node->next = NULL;
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
void split(Linked_List *list, int index, Linked_List *l1, Linked_List *l2) 
{

    if (!is_empty(list))
    {
        int counter = 0;                
        while(counter < index)
        {
            add_last(l1, get_first(list));
            counter++;
        }
        
        while(!is_empty(list))
        {
            add_last(l2, get_first(list));
        }
    }
    else {
        printf("Error: the list is empty \n");    
    }
}

// ----------------------------------------------------------------------------
void merge(Linked_List *list, Linked_List *l1, Linked_List *l2)
{
    while (!is_empty(l1))
    {
        add_last(list, get_first(l1));
    }
    while (!is_empty(l2))
    {
        add_last(list, get_first(l2));
    }
}

// ----------------------------------------------------------------------------
void add(Linked_List *list, int index, int _element)
{
    Linked_List *l1 = new Linked_List;
    l1->head == NULL;
    
    Linked_List *l2 = new Linked_List;
    l2->head == NULL;

    split(list, index, l1, l2);
    add_last(l1, _element);
    merge(list, l1, l2);
    
    free(l1);
    free(l2);
}
// ----------------------------------------------------------------------------
// -------------------------------  Main  -------------------------------------
// ----------------------------------------------------------------------------
int main(int argc, char **argv)
{
    Linked_List list;
    list.head = NULL;
    
    printf("\n");
    
    add_last(&list, 5);    
    add_last(&list, 7);
    add_last(&list, 21);
    add_last(&list, 58);
    add_last(&list, 73);
    add_last(&list, 81);
    
    printf("list = "); 
    print_list(&list);
    
    printf("\n");

    // prueba ejercicio 1
    printf("prueba ejercicio #1 split list \n");
    Linked_List l1;
    l1.head = NULL;
    
    Linked_List l2;
    l2.head = NULL;
    
    split(&list, 3, &l1, &l2);

    printf("list l1 = "); 
    print_list(&l1);
    
    printf("list l2 = "); 
    print_list(&l2);
    
    // prueba ejercicio 2
    printf("\n");
    printf("prueba ejercicio #2 merge lists \n");
    
    merge(&list, &l1, &l2);

    printf("list = "); 
    print_list(&list);

    // prueba ejercicio 3
    printf("\n");
    printf("prueba ejercicio #3 add element 36 \n");    
    
    add(&list, 3, 36);
    
    printf("list = "); 
    print_list(&list);
    printf("\n");
}