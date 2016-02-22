#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Escribir un programa que realice el comportamiento de la función “strcat” , el alumno deberá de implementar su propia función que realice  la concatenación de dos cadenas de caracteres  que recibe como parámetro  y entrega como resultado un apuntador a la nueva cadena.

char * concatena(char *cdn1, char * cdn2);

Consideraciones:
Usar malloc para crear la tercer arreglo
Las cadenas uno y dos no deben ser destruidas

*/

char * strcat(char *str_a, char * str_b);

int main () 
{
    char *str01 = "Clase de ";
    char *str02 = "Algoritmos y Estructuras de datos";
    
    char *output = strcat(str01, str02); 
    
    printf("Cadena out = %s \n", output);
    
    free(output);
}

char * strcat(char *str_a, char * str_b) 
{
    int s1 = strlen(str_a);;
    int s2 = strlen(str_b);
        
    printf("Cadena 01 = %s %d \n", str_a, s1);
    printf("Cadena 02 = %s %d \n", str_b, s2);
    
    
    char *out = (char*)malloc(sizeof(char) * (s1 +s2));
 
    /* forma uno */   
    // for (int i = 0; i < s1; i++)
//     {
//         out[i] = *str_a;
//         str_a++;
//     }
//
//     for (int i = (s1-1); i < (s1+s2); i++)
//     {
//         out[i] = *str_b;
//         str_b++;
//     }
    
    /* forma dos */   
    for (int i = 0; i < (s1 + s2); i++)
    {
        if(i < s1)
        {
            out[i] = *str_a;
            str_a++;
        }
        else {
            out[i] = *str_b;
            str_b++;
        }
    }

    return out;
}
