/**
 * estructura nodo almacena un elemento y apunta hacia otro Nodo
 */
struct Node 
{
    int element;
    struct Node * next;    
};

/**
 * Implements the functionality of a dynamic Queue 
 */
struct Linked_List { 
    Node *head;   
};   

/**
 * test if the Queue is empty
 */
bool is_empty(Linked_List *list);

/**
 * Returns the number of elements in this list.
 */
int size(Linked_List *list);

/**
 * Add one element to the list
 */    
void add(Linked_List *list, int index, int _element);

/**
 * Add one element at the end of the list
 */    
void add_last(Linked_List *list, int _element);

/**
 * Remove one element to the list
 */
int getFirst(Linked_List *list);