// Complete the function that calculates the area of the red square, when the
// length of the circular arc A is given as the input. Return the result rounded
// to two decimals.
//
// Note: use the π value provided in your language (Math::PI, M_PI, math.pi,
// etc)

#include <math.h>

extern const double PI;

float square_area(double arc)
{
    return round((4 * arc * arc) / (PI * PI) * 100) / 100;
}
