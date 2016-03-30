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

/**
 * test if the Queue is empty
 */
bool is_empty(Linked_List *list);

/**
 * Returns the number of elements in this list.
 */
int size(Linked_List *list);

/**
 * Inserts the specified element at the beginning of this list.
 */    
void add_first(Linked_List *list, int _element);

/**
 * Add one element at the end of the list
 */    
void add_last(Linked_List *list, int _element);

/**
 * Inserts the specified element at the specified position in this list.
 */    
void add(Linked_List *list, int index, int _element);

/**
 * Removes and returns the first element from this list.
 */
int remove_first(Linked_List *list);

/**
 * Returns the index of the first occurrence of the specified element in this list,
 * or -1 if this list does not contain the element.
 */
int index_of(Linked_List *list, int _element);

void print(Linked_List *list);