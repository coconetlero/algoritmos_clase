#include <stdio.h>
#include <stdlib.h>

/**
 * Calcula los primeros n numeros de la sucesion de Fibbonanci
 */
int * Fibonancci(int n);


/**
 * Imprime un arreglo de enteros, separando cada numero con una coma y un espacio.
 * Despues del ultimo elemento ya no se imprime nada
 */
void print_array(int *array, int size);


//-----------------------------------------------------------------------------
int main(int argc, char const *argv[]) {
  int fib_size = 0;
  printf("\nEnter size of the Fibonancci sequence: ");
  scanf("%i",&fib_size);

  int * fib = Fibonancci(fib_size);
  //int size = sizeof(arr) / sizeof(int);

  print_array(fib, fib_size);

  return 0;
}

//-----------------------------------------------------------------------------
int * Fibonancci(int n)
{
  int * array = (int *)malloc(sizeof(int) * n);

  if (n == 1) {
    array[0] = 0;
    return array;
  }
  if (n == 2) {
    array[0] = 0;
    array[1] = 1;
    return array;
  }

  array[0] = 0;
  array[1] = 1;
  for (int i = 2; i < n; i++) {
    array[i] = array[i-1] + array[i-2];
  }

  return array;
}

//-----------------------------------------------------------------------------
void print_array(int * array, int size)
{
  for(int i = 0; i < size; i++)
  {
    int temp = *(array + i);
    if (i+1 != size)
    {
      printf("%d, ", temp);
    }
    else
      printf("%d", temp);
  }
  printf("\n");
}
