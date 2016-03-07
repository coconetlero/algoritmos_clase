/**
 * Hacer un programa que pida un número variable de flotantes y que imprima los
 * numeros pedidos y el cuadrado de cada uno de los numeros pedidos.
 * Los numeros dados se deben de guardar en localidades de memoria pedida 
 * dinámicamente. Los cuadrados de los numeros dados tambien se deben de guardar
 * en localidades de memoria pedida dinamicamente
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main ()
{
    int size;
    
    printf("¿Cuantos elementos tiene el conjunto?\n");
    scanf("%d",&size);
    
    // se declaran dos apuntadores
    float *array;
    float *square_array;
    
    // se reserva la memoria para guardar los valores dados y sus cuadrados
    array = (float*) malloc(sizeof(float) * size);
    square_array = (float*) malloc(sizeof(float) * size);
    
    
    int cont;
    
    // guardamos los valores dados por el usuario
    for (cont = 0; cont < size; cont++)
    {
        printf("Inserte el elemento %d del conjunto.\n",cont+1);
        scanf("%f",(array+cont));
    }
        
    printf("\n");    
    printf("Vector insertado:\n\t[");
    for (cont=0 ; cont < size; cont++)
    { 
        printf("\t %0.01f", *(array+cont));
    }
    printf("\t]\n");
    
        
    for (cont=0 ; cont < size; cont++)
    { 
        float data = *(array+cont);
        *(square_array+cont) = data * data; 
    }        
    printf("\n");    
    
    // eleveamos al cuadrado los datos dados
    printf("Vector al cuadrado:\n\t[");
    for (cont=0 ; cont < size; cont++)
    { 
        printf("\t %0.01f", *(square_array+cont));
    }
    printf("\t]\n");
    printf("\n");

    
    // liberamos memoria
    free(array);
    free(square_array);    
    
    return 0;
}