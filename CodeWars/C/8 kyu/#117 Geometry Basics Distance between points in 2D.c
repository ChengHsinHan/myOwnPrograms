// This series of katas will introduce you to basics of doing geometry with
// computers.
//
// Point objects have x and y attributes (X and Y in C#) attributes.
//
// Write a function calculating distance between Point a and Point b.
//
// Tests round answers to 6 decimal places.

#include <math.h>

typedef struct Point
{
    double x;
    double y;
} point;

double distance_between_points(point a, point b)
{
    return hypot(a.x - b.x, a.y - b.y);
}
