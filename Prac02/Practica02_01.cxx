#include <stdio.h>

int main(int argc, char **argv)
{
    
    printf("\n -----------  Ejercicio 01 ------------ \n\n");
        
    char c;
    char *ap; 
    c = 'x'; 
    ap = &c;

    // imprime el carácter de la localidad a la que apunta
    printf("Carácter: %c\n",*ap);

    // imprime el código ASCII de la localidad a la que apunta
    printf("Código ASCII: %d\n",*ap);
    
    // imprime la dirección de memoria de la localidad a la que apunta
    printf("Dirección de memoria: %p \n",ap);


    printf("\n -----------  Ejercicio 02 ------------ \n\n");

    short a = 5;
    short b = 10;
    short *apEnt;
    apEnt = &a;

    // imprime el valor entero de a
    printf("a = %i\n", a);
    b= *apEnt; //b=5

    // imprime el valor de lo que apunta apEnt
    printf("b = %i //*apEnt\n", b);
    b = *apEnt+1; //b=6

    // imprime el valor de lo que apunta apEnt + 1
    printf("b = %i //*apEnt+1\n", b);
    *apEnt = 0; //a=0

    // le asigna el valor de 0 a la variable al que apunta apEnt
    printf("a = %i //*apEnt = 0\n", a);
    
    
    printf("\n -----------  Ejercicio 03 ------------ \n\n");
    /*
     * Este programa crea un apuntador de tipo entero
     * que apunta al inicio de un arreglo.
     */
    short arr[5], *apArr;
    apArr = &arr[0];
   
    // imprime la dirección de memoria del arreglo en la posición [0]
    printf("Dirección del arreglo en la primera posición: %p \n",&arr[0]);
   
    // imprime la dirección de memoria del arreglo
    // (el nombre del arreglo es un apuntador)
    printf("Dirección del arreglo: %p \n",&arr);
   
    // imprime la dirección de memoria del apuntador apArr
    printf("Dirección del apuntador: %p \n",apArr);
    
    
    
    
    return 0;
    
}