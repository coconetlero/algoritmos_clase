#include<stdio.h>
/*
Se imprimen 3 valores de un arreglo a través
de aritmética de direcciones.
*/
int main () 
{
    printf("\n -----------  Ejercicio 01 ------------ \n\n");
    
    short arr[5] = {91,28,73,46,55};
    short *apArr;
    apArr = arr;
    // apunta al inicio del arreglo
    printf("*apArr = %i\n",*apArr);
    
    // suma una localidad al inicio del arreglo e imprime su valor
    printf("*(apArr+1) = %i\n",*(apArr+1));
    
    // suma dos localidades al inicio del arreglo e imprime su valor
    printf("*(apArr+2) = %i\n",*(apArr+2));


    printf("\n -----------  Ejercicio 02 ------------ \n\n");
    
    int *ap;
    int indice;
    
    int nums[3][3] = {{99,88,77}, {66,55,44}, {33,22,11}};
    ap = nums;
    for (indice = 0; indice < 9 ; indice++)
    {
        if ((indice%3)==0)
            printf("\n");
        
        printf("%x\t",(ap+indice));
    }
    
    
    return 0;
}
