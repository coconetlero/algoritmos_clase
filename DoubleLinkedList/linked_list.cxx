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











