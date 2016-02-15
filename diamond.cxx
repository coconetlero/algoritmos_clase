#include <stdio.h>

using namespace std;

int main()
{

    int Size = 0;

    printf("\nEnter the diamond size: ");
    scanf("%i",&Size);
    printf("Your input is: %i \n", Size);
    printf ("My Diamond!! \n \n");

    // print the upper part of the diamond
    int upper_half = (Size + 1) / 2;    
    for(int i = 1; i <= upper_half; i++) 
    {        
        int spaces = upper_half - i;
        for (int j = spaces; j > 0; j--)
        {
            printf (" ");
        }    
        int asterisc = Size - (2 * spaces);
        for (int j = 0; j < asterisc; j++)
        {
            printf ("*");
        }                        
        printf ("\n");
    } 
    
    // print the lower part of the diamond
    int lower_half = upper_half - 1;

    for(int i = 0; i < lower_half; i++) 
    {        
        int spaces = i + 1;
        for (int j = spaces; j > 0; j--)
        {
            printf (" ");
        }        
        int asterisc = Size - (2 * spaces);        
        for (int j = 0; j < asterisc; j++)
        {
            printf ("*");
        }                        
        printf ("\n");
    }      
    printf ("\n");                
    return 0;
}