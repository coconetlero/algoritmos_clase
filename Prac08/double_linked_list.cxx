#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/**
 * estructura nodo almacena un elemento y apunta hacia otro Nodo
 */
struct Node 
{
    int data;
    struct Node * next;
    struct Node * prev;    
};

/**
 * Implements the functionality of a dynamic list
 */
struct Linked_List { 
    Node *head;
    Node *tail;   
};  

// ----------------------------------------------------------------------------
// ------------------------------- Implementation -----------------------------
// ----------------------------------------------------------------------------
/**
 * Create one instace of a Linked List and return a pointer to it
 */
Linked_List * create_linked_list()
{
    Linked_List *list = new Linked_List;
    list->head = NULL;
    list->tail = NULL;
    
    return list;
}

// ----------------------------------------------------------------------------
/**
 * test if the Queue is empty
 */
bool is_empty(Linked_List *list)
{
    if (list->head == NULL && list->tail == NULL)
        return true;
    else
        return false;
}

// ----------------------------------------------------------------------------
/**
 * Returns the number of elements in this list.
 */
int size(Linked_List *list) 
{    
    if (is_empty(list))
    {
        return 0;
    }
    else {
        Node *current = list->head;
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
/**
 * Inserts the specified element at the specified position in this list.
 */
void add(Linked_List *list, int index, int _element)
{
    Node *node = (Node*)malloc(sizeof(Node)); 
    assert(node);
    
    node->data = _element;
    
    if (is_empty(list))
    {
        list->head = node;        
        list->tail = node;        
        node->next = NULL;
        node->prev = NULL;
    }
    else { 
        Node *current = list->head;
        int counter = 0;
        while(counter < index && current != NULL)
        {               
            current = current->next;
            counter++;
        }    
        
        node->prev = current->prev;
        node->next = current;
        current->prev->next = node;
        current->prev = node;
    }    
}

// ---------------------------------------------------------------------------- 
/**
 * Inserts the specified element at the beginning of this list.
 */ 
void add_first(Linked_List *list, int _element) 
{
    Node *node = (Node*)malloc(sizeof(Node)); 
    assert(node);
    
    node->data = _element;
    
    if (is_empty(list))
    {
        list->head = node;        
        list->tail = node;        
        node->prev = NULL;
        node->next = NULL;
    }
    else {    
        node->prev = NULL;
        node->next = list->head;
        list->head->prev = node;
        list->head = node;
    }      
}

// ----------------------------------------------------------------------------
/**
 * Add one element at the end of the list
 */
void add_last(Linked_List *list, int _element)
{
    Node *node = (Node*)malloc(sizeof(Node)); 
    assert(node);
    
    node->data = _element;
    
    if (is_empty(list))
    {
        list->head = node;        
        list->tail = node;        
        node->prev = NULL;
        node->next = NULL;
    }
    else {    
        node->prev = list->tail;
        node->next = NULL;
        list->tail->next = node;
        list->tail = node;
    }   
}

// ----------------------------------------------------------------------------
/**
 * Removes and returns the first element from this list.
 */
int remove_first(Linked_List *list) 
{
    if (!is_empty(list))
    {
        Node *node = list->head;
        int out = node->data;

        if (list->head->next != NULL) 
        {
            list->head = list->head->next;
            list->head->prev = NULL;
        }
        else {
            list->head = NULL;
            list->tail = NULL;
        }
        
        free(node);        
        return out;            
    }
    else {
        printf("Error: the list is empty \n");    
        return NULL;
    }
}

// ----------------------------------------------------------------------------
/**
 * Returns the index of the first occurrence of the specified element in this list,
 * or -1 if this list does not contain the element.
 */
int index_of(Linked_List *list, int _element)
{
    if (!is_empty(list))
    {
        Node *current = list->head;
        
        int counter = 0;
        while(current->data != _element)
        {               
            if (current->next == NULL)
            {
                return -1;
            }
            else {
                current = current->next;
                counter++;
            }
        }       
        return counter;
    }
    else {
        printf("Error: the list is empty \n");    
        return NULL;
    }
}

// ----------------------------------------------------------------------------
/**
 * Print the list in the standar output
 */
void print_list(Linked_List *list)
{
    if (!is_empty(list))
    {
        printf("[");
        Node *current = list->head;
        while(current != NULL)
        {           
            printf("%d", current->data);    
            if (current->next != NULL)
            {
                printf(", ");
            }
            current = current->next;
        }       
        printf("]\n");
    }
    else {
        printf("Error: the list is empty \n");    
    }
}

// ----------------------------------------------------------------------------
// --------------------------------- Main -------------------------------------
// ----------------------------------------------------------------------------

int main(int argc, char **argv)
{
    Linked_List *list = create_linked_list();
    
    int element;
    
    element = 5;
    printf("Add %d \n", element);
    add_last(list, element);
    printf("list size = %d \n", size(list));
    
    element = 7;
    printf("Add %d \n", element);
    add_last(list, element);
    printf("list size = %d \n", size(list));
    
    element = 21;
    printf("Add %d \n", element);
    add_last(list, element);
    printf("list size = %d \n", size(list));
    
    element = 11;    
    printf("Add %d in the thirth position \n", element);
    add(list, 2, element);
    printf("list size = %d \n", size(list));
    
    
    printf("\n");
    printf("list = ");
    print_list(list);
    printf("\n");
    
    element = remove_first(list);
    assert(element);
    printf("get head element = %d \n", element);
    
    
    element = remove_first(list);
    assert(element);
    printf("get head element = %d \n", element);
    
    printf("list = ");
    print_list(list);
    
    element = remove_first(list);
    assert(element);
    printf("get head element = %d \n", element);
    
    
    element = remove_first(list);
    assert(element);
    printf("get head element = %d \n", element);
    
    
    element = remove_first(list);
    assert(element);
    printf("get head element = %d \n", element);
    
}








