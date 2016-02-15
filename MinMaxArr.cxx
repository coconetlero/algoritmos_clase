#include <stdio.h>

/**
 * Encuentra el maximo y minimo del arreglo dado. 
 * @return Un arreglo de tamaño dos con el valor del minimo y el maximo 
 */  
int * min_max(int *a, int tamanio);


/**
 * Funcion principal
 */
int main(int argc, char *argv[])
{        
    int arreglo[] = {12, 52, 12, 74, 14, 463, 12, 8, -12, 5, 43, 6, -23, 63};        
    int *salida = min_max(arreglo, 14);

    printf("El minimo es: %d \n", salida[0]);
    printf("El maximo es: %d \n", salida[1]);

    return 0;
}

// ---------------------------------------------------------
int * min_max(int *a, int tamanio)
{    
    int min = a[0];
    int max = a[0];
    
    for(int i = 0; i < tamanio; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
        }
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    
    static int out[2] = {min, max};
    return out;
}