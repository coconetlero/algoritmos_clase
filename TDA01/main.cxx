#include <stdio.h>
#include <point.h>

int main(int argc, char **argv)
{
    Point r;
    r.x = 5;
    r.y = 5;

    Point s;
    s.x = 4;
    s.y = 6;
        

        
    printf("Point r = (%0.1f, %0.1f)\n", r.x, r.y);
    printf("Point s = (%0.1f, %0.1f)\n", s.x, s.y);

    float d = distance(r, s); 
    printf("Distance from r to s is = %0.1f \n", d);
    
    float dot = dot_product(&r, &s);
    printf("dot product = %0.1f\n", dot);
    
    float dx = 12.4f;
    float dy = 9.2f;
    
    move(&r, dx, dy);
    
    printf("Point r = (%0.1f, %0.1f)\n", r.x, r.y);
    
    d = distance(r, s);
    printf("New distance from r to s is = %0.1f \n", d);
        
    
    return 0;

    
}