#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void add_number_1(int *arr, int num, int size);

void add_number_2(int *arr, int num, int size);

/**
 * Funcion principal
 */
int main(int argc, char *argv[])
{   
    
    int A[] = {12, 13, 14, 21, 43, 63, 87, 102, 207, 500};             
    int size = sizeof(A) / sizeof(A[0]);
    
    int * array = (int *) malloc(sizeof(int) * size);
    assert(array != NULL);
    
    // copy the array
    memcpy(array, A, size * sizeof(A[0]));
    
    int num = 509;

    add_number(array, num, size);    
    //add_number_2(array, num, size);
    
    printf("New Array \n");
    for(int i = 0; i < size + 1; i++)
    {
        printf("%d ", *(array + i));
    }
            
    printf("\n");
        
    free(array);
    
    return 0;
}

// ----------------------------------------------------------------------------
void add_number_1(int * arr, int num, int size)
{
    assert(realloc(arr, sizeof(int)) != NULL);
    
    int idx = 0;
    while((*(arr + idx) < num) && (idx <= size)) idx++;
    
    if (size > idx) { 
        for(int i = size; i > idx; i--) 
        {
            *(arr + i) = *(arr + i - 1);     
        }
    
        *(arr + idx) = num;    
    }
    else
    {
        *(arr + idx-1) = num;
    }
}

// ----------------------------------------------------------------------------
void add_number_2(int * arr, int num, int size)
{
    assert(realloc(arr, sizeof(int)) != NULL);
    
    int idx = 0;
    while((*(arr + idx) < num) && (idx <= size)) idx++;
        
    if (size > idx) { 
        int tmp_1, tmp_2;    
        tmp_1 = *(arr + idx);
        tmp_2 = *(arr + idx+1);
    
        for (int i = idx+1; i <= size; i++)
        {
            *(arr + i) = tmp_1;
            tmp_1 = tmp_2;
            tmp_2 = *(arr + i+1);
        }        
        *(arr + idx) = num;
    } 
    else {
        *(arr + idx-1) = num;
    }        
}