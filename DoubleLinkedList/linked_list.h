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
 * Create one instace of a Linked List and return a pointer to it
 */
Linked_List * create_linked_list();

/**
 * test if this Linked List is empty
 */
bool is_empty(Linked_List *list);

/**
 * Returns the number of elements in this list.
 */
int size(Linked_List *list);

/**
 * Inserts the specified element at the beginning of this list.
 */    
void add_front(Linked_List *list, int _element);

/**
 * Add one element at the end of the list
 */    
void add_back(Linked_List *list, int _element);

/**
 * Inserts the specified element at the specified position in this list.
 */    
void add(Linked_List *list, int index, int _element);

/**
 * Removes and returns the first element from this list.
 */
int remove_front(Linked_List *list);

/**
 * Removes and returns the last element from this list.
 */
int remove_back(Linked_List *list);

/**
 * Removes and returns the element in the index position on the list.
 */
int remove(Linked_List *list, int index);

/**
 * Returns the first element from this list.
 */
int get_front(Linked_List *list);

/**
 * Returns the last element from this list.
 */
int get_back(Linked_List *list);

/**
 * Returns the element in the index position on the list.
 */
int get(Linked_List *list, int index);

/**
 * Returns the index of the first occurrence of the specified element in this list,
 * or -1 if this list does not contain the element.
 */
int index_of(Linked_List *list, int _element);

/**
 * Print the list in the standar output
 */
void print_list(Linked_List *list);


