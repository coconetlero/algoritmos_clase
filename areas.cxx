#include <stdio.h>
#include <math.h>

/*
* Programa que calcula el area de distitos cuerpos geometricos 
*/

float areaTriangulo(float base, float altura);
float areaCirculo(float radio);

int main()
{
    int opcion = 0;
    while (1)
    {        
        printf("\n¿Qué área deseas calcular?\n");
        printf("1) Calcular el área de un triangulo.\n");
        printf("2) Calcular el área de un circulo.\n");
        printf("3) Salir.\n");
        scanf("%d", &opcion);
        
        switch(opcion)
        {
            case 1:
            {
                float _base = 0;
                float _altura = 0;
                printf("Base del traingulo: ");
                scanf("%f", &_base);
                printf("Altura del traingulo: ");
                scanf("%f", &_altura);
                
                float area = areaTriangulo(_base, _altura);
                printf("El area del triangulo es: %f \n", area);
                
                break;
            }
            case 2:
            {
                float _radio = 0;
                printf("Radio del circulo: ");
                scanf("%f", &_radio);
                
                float area = areaCirculo(_radio);
                printf("El area del circulo es: %f \n", area);
                
                break;           
            }                
            case 3:
                return 0;
        
            default:
                printf("Opción no válida.\n");
        }
    }
    return 0;
}

/**
 * Calcula el area de un triangulo. El area de un triangulo es: (b*h)/2
 */
float areaTriangulo(float base, float altura)
{
    float area = (base * altura) / 2;
    return area;
}

/**
 * Calcula el area de un circulo. El area de un circulo es: PI*r^2
 */
float areaCirculo(float radio)
{
    float area = M_PI * radio *radio;
    return area;
}
