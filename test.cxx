#include<stdio.h>
//#include<conio.h>

void printArray(int *p);

main()
{
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int *p=a;
	
    printArray(p);
  //  getch();
}

void printArray(int *p)
{
    int b;
    for	(int i=0; i<10; i++){
        b=*(p+i);
        printf("%i", b);
        if(i!=9){
            printf(", ");
        }
    }
}
