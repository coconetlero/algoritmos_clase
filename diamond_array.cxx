#include <stdio.h>


int main()
{

    int Size = 0;

    printf("\nEnter the diamond size: ");
    scanf("%i",&Size);
    printf("Your input is: %i \n", Size);
    printf ("My Diamond!! \n \n");
    
    char arr[Size][Size];   //  -->  new  <--    
        
    // fill the array with the upper part of the diamond
    int ren = 0;   //  -->  new  <--
    int upper_half = (Size + 1) / 2;    
    for(int i = 1; i <= upper_half; i++) 
    {                
        // fill wioth the first spaces
        int col = 0;    //  -->  new  <--
        int spaces = upper_half - i;
        for (int j = spaces; j > 0; j--)
        {
            arr[ren][col] = (' ');  //  -->  new  <--
            col++;  //  -->  new  <--
        }    
        // fill with the asterisks
        int asterisk = Size - (2 * spaces);
        for (int j = 0; j < asterisk; j++)
        {
            arr[ren][col] = ('*'); //  -->  change  <--
            col++; //  -->  new  <--
        }
        // fill with the final spaces
        for (;col < Size; col++)    //  -->  new  <--
        {
            arr[ren][col] = (' ');  //  -->  change  <--
        }                                
        ren++;  //  -->  new  <--
    } 
    
    // fill the array with the lower part of the diamond
    int lower_half = upper_half - 1;

    for(int i = 0; i < lower_half; i++) 
    {        
        // fill wioth the first spaces
        int col = 0;    //  -->  new  <--
        int spaces = i + 1;
        for (int j = spaces; j > 0; j--)
        {         
            arr[ren][col] = (' ');  //  -->  change  <--
            col++;  //  -->  new  <--
        }        
        // fill with the asterisks
        int asterisc = Size - (2 * spaces);        
        for (int j = 0; j < asterisc; j++)
        {
            arr[ren][col] = ('*');  //  -->  change <--
            col++;  //  -->  new  <--
        }                        
        // fill with the final spaces
        for (;col < Size; col++)    //  -->  new  <-- 
        {
            arr[ren][col] = (' ');  //  -->  new  <--
        }                                        
        ren++;  //  -->  new  <--
    }      
                         

    //  -->  new  <--                             
                         
    // print the diamond
    for(int i = 0; i < Size; i++) 
    {             
        for (int j = 0; j < Size; j++)
        {
            printf ("%c", arr[i][j]);                
        }
        printf ("\n");
    }
    
    //  -->  new  <--
    
    printf ("\n");
    
    return 0;
}