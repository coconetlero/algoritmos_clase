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
    // the square
    Point s1; s1.x = 0; s1.y = 0;
    Point s2; s2.x = 5; s2.y = 0;
    Point s3; s3.x = 5; s3.y = 5;
    Point s4; s4.x = 0; s4.y = 5;
    
    Point S[] = {s1, s2, s3, s4};

    printf(" --- El cuadrado --- \n");
    for(int i = 0; i < 4; i++)
        print(&(S[i]));
    
    // the rectangle
    Point r1; r1.x = 0; r1.y = 0;
    Point r2; r2.x = 10; r2.y = 0;
    Point r3; r3.x = 10; r3.y = 5;
    Point r4; r4.x = 0; r4.y = 5;
    
    Point R[] = {r1, r2, r3, r4};

    printf(" --- El rectangulo --- \n");
    for(int i = 0; i < 4; i++)
        print(&(R[i]));
    
    // the diamod
    Point d1; d1.x = 0; d1.y = 0;
    Point d2; d2.x = 5; d2.y = 2.5;
    Point d3; d3.x = 0; d3.y = 5;
    Point d4; d4.x = -5; d4.y = 2.5;
    
    Point D[] = {d1, d2, d3, d4};

    printf(" --- El rombo --- \n");
    for(int i = 0; i < 4; i++)
        print(&(D[i]));

  return 0;      
    
}