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
float distance(Point *p, Point *q);

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
