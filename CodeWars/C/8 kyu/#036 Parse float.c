// Write function parseFloat which takes an input and returns a number or
// Nothing if conversion is not possible.

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

struct maybe_double
{
    bool value_exists;
    double value;
};

struct maybe_double parse_float(const char* input)
{
    struct maybe_double out;

    // position is used to record how many characters are transformed into double
    int position;

    // %n will do nothing but store how many characters have been used, which we store it in position
    // sccanf would return how many number of C-style formatted string has successfully transferred
    // in this case, we want it to be 1. Also we want to make sure we made use all of input, so we check
    // whether position has the same length as input
    out.value_exists = ((sscanf(input, "%lf%n", &out.value, &position) == 1) && (position == strlen(input)));
    return out;
}
