#include <stdio.h>
#include <math.h>
#include <point.h>

float distance(Point * a, Point * b)
{
    float dx = a->x - b->x;
    float dy = a->y - b->y;
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
