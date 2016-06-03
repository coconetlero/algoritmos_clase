#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <linked_list.h>

// ----------------------------------------------------------------------------
Linked_List * create_linked_list()
{
    Linked_List *list = new Linked_List;
    list->head = NULL;
    list->tail = NULL;
    
    return list;
}

// ----------------------------------------------------------------------------
bool is_empty(Linked_List *list)
{
    if (list->head == NULL && list->tail == NULL)
        return true;
    else
        return false;
}

// ----------------------------------------------------------------------------
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
void add_front(Linked_List *list, int _element) 
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
void add_back(Linked_List *list, int _element)
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
int remove(Linked_List *list, int index)
{
    if (!is_empty(list))
    {
        Node *current = list->head;
        
        int counter = 0;
        while(counter != index)
        {               
            if (current->next == NULL)
            {
                printf("Error: the index is out of list bounds \n");
                return NULL;
            }
            else {
                current = current->next;
                counter++;
            }
        }       
        int out = current->data;
        current->prev->next = current->next;
        current->next->prev = current->prev;
        free(current);
        return out;
    }
    else {
        printf("Error: the list is empty \n");    
        return NULL;
    }    
}

// ----------------------------------------------------------------------------
int remove_front(Linked_List *list) 
{
    if (!is_empty(list))
    {
        Node *node = list->head;
        int out = node->data;

        if (list->head != list->tail) 
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
int remove_back(Linked_List *list) 
{
    if (!is_empty(list))
    {
        Node *node = list->tail;
        int out = node->data;

        if (list->head != list->tail) 
        {
            list->tail = list->tail->prev;
            list->tail->next = NULL;
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
int get(Linked_List *list, int index)
{
    if (!is_empty(list))
    {
        Node *current = list->head;
        
        int counter = 0;
        while(counter != index)
        {               
            if (current->next == NULL)
            {
                printf("Error: the index is out of list bounds \n");
                return NULL;
            }
            else {
                current = current->next;
                counter++;
            }
        }       
        return current->data;
    }
    else {
        printf("Error: the list is empty \n");    
        return NULL;
    }    
}

// ----------------------------------------------------------------------------
int get_front(Linked_List *list) 
{
    if (!is_empty(list))
    {
        return list->head->data;        
    }
    else {
        printf("Error: the list is empty \n");    
        return NULL;
    }
}

// ----------------------------------------------------------------------------
int get_back(Linked_List *list) 
{
    if (!is_empty(list))
    {
        return list->tail->data;
    }
    else {
        printf("Error: the list is empty \n");    
        return NULL;
    }
}

// ----------------------------------------------------------------------------
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
                printf("Error: the serched element is not in the list")
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
void print_list(Linked_List *list)
{
    printf("List => [");
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











