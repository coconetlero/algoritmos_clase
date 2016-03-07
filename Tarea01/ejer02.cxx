#include <stdio.h>

/**
 * Imprime un arreglo de enteros, separando cada numero con una coma y un espacio.
 * Despues del ultimo elemento ya no se imprime nada
 */
void print_array(int *array, int size);

/**
 * Invierte el orden de los elementos del arreglo dado,
 */
void reverse(int *array, int size);

//-----------------------------------------------------------------------------
int main(int argc, char const *argv[]) {
  int arr[] = {0, 2, 4, 6, 8, 10, 12, 14, 16};
  int size = sizeof(arr) / sizeof(int);

  print_array(arr, size);
  reverse(arr, size);
  print_array(arr, size);

  return 0;
}

//-----------------------------------------------------------------------------
void reverse(int * array, int size)
{
  int temp_array[size];
  int idx = 0;
  for(int i = size - 1; i >= 0; i--)
  {
      temp_array[idx] = *(array + i);
      idx++;
  }
  for(int i = 0; i < size; i++)
  {
      *(array + i) = temp_array[i];
  }
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
