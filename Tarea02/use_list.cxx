#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <list>
#include <iostream>

struct My_data 
{
    int id;
    char* name;
        
};

int main(int argc, char *argv[])
{  
    My_data *d1 = (My_data*)malloc(sizeof(My_data)); 
    assert(d1);    
    
    d1->id = 10022;    
    d1->name = "22 nombre y apellido";

    My_data *d2 = (My_data*)malloc(sizeof(My_data)); 
    assert(d2);    
    
    d2->id = 10056;
    d2->name = "56 nombre y apellido";
    

    
    // creacion de la lista 
    std::list<My_data *> mylist;
            
    // agregar elementos a la lista 
    mylist.push_back(d1);
    mylist.push_back(d2);
        
    // saber el tamaño de la lista     
    std::cout << "list size: " << mylist.size() << std::endl;
    
    // obtener el nodo que esta en la cabeza de la lista
    My_data *node = mylist.front();
    int node_id = node->id;
    char *node_name = node->name;
    std::cout << "head element =  \n id = " << node_id << "\n name = " << node_name << std::endl;
    
    
    // para mostrar el contenido de la lista hay que utilizar un iterador
    std::cout << "my list contains: \n";
    // declaramos un nodo temporal del tipo My_data
    My_data *node_temp;
    // creamos un iterador 
    std::list<My_data *>::iterator it;
    // recorremos la lista desde el principio (mylist.begin()) hasta el final (mylist.end())
    for (it = mylist.begin(); it != mylist.end(); ++it)
    {
        // cada nodo de la lista se almacena en el iterador que convertimos a My_data
        node_temp = (My_data*)*it;
        // desplegamos la información
        std::cout << "head element =  \n id = " << node_temp->id << 
            "\n name = " << node_temp->name << std::endl;
    }
    std::cout << '\n';
    
    return (0);
}