/**
 * estructura nodo para un arbol binario
 */
struct Node 
{
    int data;
    struct Node * father;
    struct Node * left_child;
    struct Node * right_child;    
};

/**
 * Implements the functionality of a dynamic list
 */
struct Binary_Tree { 
    Node *root;
};   

/**
 * Create one instace of a Binary_Tree and return a pointer to it
 */
Binary_Tree * create_binary_tree();