#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <polygon.h>

int main(int argc, char const *argv[]) {

  Point p1;  p1.x = 0;  p1.y = 0;
  Point p2;  p2.x = 5;  p2.y = 1;
  Point p3;  p3.x = 1;  p3.y = 6;

  printf("Point p1 = ");
  print(&p1);
  printf("Point p2 = ");
  print(&p2);
  printf("Point p3 = ");
  print(&p3);

  Point * vertex = (Point *)malloc(sizeof(Point) * 3);
  assert(vertex != NULL);

  vertex[0] = p1;
  vertex[1] = p2;
  vertex[2] = p3;

  Polygon poly;
  poly.num_points = 3;
  poly.vertex = vertex;

  float p = perimeter(&poly);
  printf("Perimeter = %0.001f \n", p);

  float a = area(&poly);
  printf("Area = %0.001f \n", a);

  Point * m = centroid(&poly);
  printf("Centroide = "); print(m);

  free(m);
  free(vertex);
  return 0;
}
