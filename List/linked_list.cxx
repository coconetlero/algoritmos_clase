#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <linked_list.h>

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
void add(Linked_List *list, int index, int _element)
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
        while(counter < index && current->next != NULL)
        {   
            counter++;
            current = current->next;
        }    
        
        node->next = current->next;
        current->next = node;
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


