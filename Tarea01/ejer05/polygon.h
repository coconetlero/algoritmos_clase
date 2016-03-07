#include <point.h>

struct Polygon
{
  int num_points;
  Point *vertex;
};

/**
* Encuentra el perimetro del poligono dado
*/
float perimeter(Polygon *polygon);

/**
* Encuentra el area del poligono dado
*/
float area(Polygon *polygon);

/**
* Encuentra el centroide del poligono dado
*/
Point * centroid(Polygon *polygon);
