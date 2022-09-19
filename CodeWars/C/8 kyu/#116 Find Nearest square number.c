// Your task is to find the nearest square number, nearest_sq(n), of a positive
// integer n.
//
// Goodluck :)
//
// Check my other katas:
//
// Alphabetically ordered
//
// Case-sensitive!
//
// Not prime numbers

#include <math.h>

int nearest_sq(int n)
{
    int square_root = round(sqrt(n));
    return square_root * square_root;
}
