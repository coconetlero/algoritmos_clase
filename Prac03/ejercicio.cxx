/**
 * Implentar un TDA para un paralelogramo el cual queda definido como:
 * por el numero de puntos y un arreglo de Puntos donde el orden define la conectividad
 * de los mismos.
 * Crear las funciones es_cuadrado, es_rectangulo, es_triangulo.
 * Hint: implemente el TDA para definir un Punto en 2D
 */

#include <stdio.h>
#include <math.h>

// struct paralelogram {
//
// }

// void constructor(int num_points, Point *points);
//
// void is_triangle?(paralelogram *p);
//
// void is_square?(paralelogram *p);
//
// void is_rectangle?(paralelogram *p);
  
  
  
// --------------------------------------------------------------------------
// --------------------------------------------------------------------------    


struct Point
{
    /** X coordinate */
    float x; 
    
    /** Y coordinate */
    float y;
};

/**
 * Computes the euclidean distance between two points 
 */
float distance(Point p, Point q);

/**
 * Moves a point the desired delta (dx,dy)
 */
void move(Point *p, float dx, float dy);

/**
 * Computes the dot product between two points
 */ 
float dot_product(Point *p, Point *q);

/**
 * Prints the point
 */
void print(Point *p);

float distance(Point a, Point b)
{
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

// --------------------------------------------------------------------------

void move(Point *p, float dx, float dy)
{
    p->x += dx;
    p->y += dy;
}

// --------------------------------------------------------------------------
float dot_product(Point *p, Point *q)
{
    float x = p->x * q->x;
    float y = p->y * q->y;
    return x + y;
}

// --------------------------------------------------------------------------
void print(Point *p)
{
    printf("(%0.2f, %0.2f) \n", p->x, p->y);
}



// --------------------------------------------------------------------------
// --------------------------------  Main  ----------------------------------
// --------------------------------------------------------------------------
int main()
{
    Point p1; p1.x = 0; p1.y = 0;
    Point p2; p2.x = 5; p2.y = 0;
    Point p3; p3.x = 5; p3.y = 5;
    Point p4; p4.x = 0; p4.y = 5;
    
    Point p[] = {p1, p2, p3, p4};

    for(int i = 0; i < 4; i++)
        print(&(p[i]));

  return 0;      
    
}