#include <stdio.h>

/*
* Programa que calcula el area de distitos cuerpos geometricos 
*/

int main()
{

    
    int a = 5;
    int b = 10;
    int *p1;
    int *p2; 
    
    p1 = &a; 
    p2 = &b; 
    
    *p1 = 10; 
    p1 = p2; 
    *p1 = 20; 
    
    printf("a = %d\n", a); 
    printf("b = %d\n", b);
 
    int arr[5] = {1,2,3,4,5};
    *p1;
    p1 = &arr[1]; // gets address of this element
    printf("*p1 = %d\n", *p1);
    p1++; // point to the next element
    printf("*p1 = %d\n", *p1);
    
    *p2;
    p1 = &arr[1];
    p2 = p1++;
    printf("*p2 = %d\n", *p2);
    
    
    p1 = &arr[1];
    printf("*p1 = %d\n", *p1);
    p1 = p1+2;
    printf("*p1 = %d\n", *p1);
    
    p1 = &arr[1];
    int dave;
    dave = *(p1+2);
    printf("*p1 = %d\n", *p1);
    printf("dave = %d\n", dave);
    
    int **ramon; 
    int *paul; 
    int melissa = 5; 
    paul = &melissa;
    ramon = &paul; 
    printf("ramon = %d\n", ramon); 
    printf("&paul = %d\n", &paul); 
    printf("*ramon = %d\n", *ramon); 
    printf("&melissa = %d\n", &melissa); 
    printf("**ramon = %d\n", **ramon);
}