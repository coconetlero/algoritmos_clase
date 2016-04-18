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
    Node *current;   
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
    list->current = NULL;
    
    return list;
}

// ----------------------------------------------------------------------------
/**
 * test if the Linked List is empty
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
        while(current->next != list->head)
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
        node->next = node;
        node->prev = node;
        list->current = node;
    }
    else { 
        Node *current = list->head;
        int counter = 0;
        while(counter < index && current->next != list->head)
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
        node->prev = node;
        node->next = node;
        list->current = node;
    }
    else {           
        node->prev = list->tail;
        node->next = list->head;        
        list->head->prev = node;        
        list->tail->next = node; 
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
        node->prev = node;
        node->next = node;
        list->current = node;
    }
    else {    
        node->prev = list->tail;
        node->next = list->head;        
        list->head->prev = node;        
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

        if (list->head != list->tail) 
        {
            list->head = list->head->next;
            list->head->prev = list->tail;
            list->tail->next = list->head;
        }
        else {
            list->head = NULL;
            list->tail = NULL;
            list->current = NULL;
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
        int counter = 0;
        Node *current = list->head;
        while(current->data != _element)
        {               
            if (current->next == list->head)
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
    if (is_empty(list))
    {
        printf("[ ]\n");
    }
    else {
        Node *current = list->head;
        printf("[");
        do {
            printf("%d", current->data);   
            current = current->next;
                        
            if (current != list->head)
            {
                printf(", ");    
            }
        }
        while(current != list->head);
        printf("]\n");
    }        
}

// ----------------------------------------------------------------------------
/*
 * Regresa el contenido del nodo al que apunta current
 */  
int at(Linked_List *list) 
{
    return list->current->data;    
}

// ----------------------------------------------------------------------------
/*
 * Incrementa una posición en la lista la referencia de current
 */
 void fwd(Linked_List *list) 
 {
     list->current = list->current->next;
 }
 
 // ----------------------------------------------------------------------------
/*
 * Decrementa una posición en la lista la referencia de current
 */
 void bwd(Linked_List *list)
{
    list->current = list->current->prev;    
}     

// ----------------------------------------------------------------------------
// --------------------------------- Main -------------------------------------
// ----------------------------------------------------------------------------

int main(int argc, char **argv)
{
    Linked_List *list = create_linked_list();
    
    // test add_last, add_first, add
    
    int element;
    
    element = 5;
    printf("Add last %d \n", element);
    add_last(list, element);

    element = 7;
    printf("Add last %d \n", element);
    add_last(list, element);

    element = 21;
    printf("Add first %d \n", element);
    add_first(list, element);
    
    element = 11;
    printf("Add %d in the thirth position \n", element);
    add(list, 2, element);
    printf("list size = %d \n", size(list));


    // test print list

    printf("\n");
    printf("list = ");
    print_list(list);
    printf("\n");
    
    // test at, fwd, bwd   

    printf("print current \n");
    //go forward
    printf("go forward \n");
    for(int i = 0; i < size(list); i++) 
    {
        printf("%d ", at(list));
        fwd(list);    
    }
    printf("\n\n");
    
    // go backwards
    printf("go backwards \n");
    for(int i = 0; i < size(list); i++) 
    {
        printf("%d ", at(list));
        bwd(list);    
    }
    printf("\n\n");
    
    
    // test remove_first, is_empty
    
    element = 21;
    printf("index of %d = %d \n", element, index_of(list, element));
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
    
    free(list);
    
}








