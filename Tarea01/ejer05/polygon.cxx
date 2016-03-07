#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#include <polygon.h>

// ----------------------------------------------------------------------------
float perimeter(Polygon *polygon)
{
  float length = 0;
  for (int i = 1; i <= polygon->num_points; i++)
  {
    if (i != polygon->num_points)
    {
      Point * p = &polygon->vertex[i-1];
      Point * q = &polygon->vertex[i];
      length += distance(p, q);
    }
    else
    {
      Point * p = &polygon->vertex[i-1];
      Point * q = &polygon->vertex[0];
      length += distance(p, q);
    }
  }
  return length;
}

// ----------------------------------------------------------------------------
float area(Polygon *polygon)
{
  float t1 = 0;
  for (int i = 1; i <= polygon->num_points; i++)
  {
    if (i != polygon->num_points)
    {
      Point * p = &polygon->vertex[i-1];
      Point * q = &polygon->vertex[i];
      t1 += (p->x * q->y);
    }
    else
    {
      Point * p = &polygon->vertex[i-1];
      Point * q = &polygon->vertex[0];
      t1 += (p->x * q->y);
    }
  }

  float t2 = 0;
  for (int i = 1; i <= polygon->num_points; i++)
  {
    if (i != polygon->num_points)
    {
      Point * p = &polygon->vertex[i-1];
      Point * q = &polygon->vertex[i];
      t2 -= (q->x * p->y);
    }
    else
    {
      Point * p = &polygon->vertex[i-1];
      Point * q = &polygon->vertex[0];
      t2 -= (q->x * p->y);
    }
  }

  return fabs(t1 - t2) / 2;
}

// ----------------------------------------------------------------------------
Point * centroid(Polygon *polygon)
{
  float dx = 0;
  float dy = 0;

  for (size_t i = 0; i < polygon->num_points; i++) {
    Point * temp = &polygon->vertex[i];
    dx += temp->x;
    dy += temp->y;
  }

  dx /= polygon->num_points;
  dy /= polygon->num_points;

  Point *p = (Point *)malloc(sizeof(Point));
  p->x = dx;
  p->y = dy;

  return p;
}
