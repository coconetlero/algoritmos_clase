
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