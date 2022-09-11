// Complete the function that calculates the area of the red square, when the
// length of the circular arc A is given as the input. Return the result rounded
// to two decimals.
//
// Note: use the π value provided in your language (Math::PI, M_PI, math.pi,
// etc)

#include <cmath>

double square_area(double A)
{
    return round((A * A) / (M_PI_2 * M_PI_2) * 100) / 100;
}
