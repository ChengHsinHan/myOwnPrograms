// Create a function that finds the integral of the expression passed.
//
// In order to find the integral all you need to do is add one to the exponent
// (the second argument), and divide the coefficient (the first argument) by
// that new number.
//
// For example for 3x^2, the integral would be 1x^3: we added 1 to the exponent,
// and divided the coefficient by that new number).
//
// Notes:
//
// The output should be a string.
// The coefficient and exponent is always a positive integer.
// Examples
//  3, 2  -->  "1x^3"
// 12, 5  -->  "2x^6"
// 20, 1  -->  "10x^2"
// 40, 3  -->  "10x^4"
// 90, 2  -->  "30x^3"

#include <stdlib.h>
#include <stdio.h>

int getDigits(int number)
{
    int digits = 0;
    do
    {
        ++digits;
        number /= 10;
    } while (number);
    return digits;
}

char* integrate(int coefficient, int exponent)
{
    // "x^" has length 2, we add 1 for the possible carry in the exponent, and
    // add another 1 for the terminating '\0'. Combined additional length would be 4
    char* result = (char*) calloc(getDigits(coefficient) + getDigits(exponent) + 4, sizeof(char));
    sprintf(result, "%dx^%d", coefficient / (exponent + 1), exponent + 1);
    return result;
}
