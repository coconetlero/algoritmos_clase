
#include <math.h>
#include <point.h>

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

