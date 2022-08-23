// Write function parseFloat which takes an input and returns a number or
// Nothing if conversion is not possible.

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct maybe_double
{
    bool value_exists;
    double value;
};

struct maybe_double parse_float(const char* input)
{
    struct maybe_double out;

    // rest is used to store the next char pointer after converting characters to double
    char* rest;

    out.value = strtod(input, &rest);

    // if rest has reached the end of the string, it should be '\0'
    // check whether input is an empty string is also added
    out.value_exists = ((*rest == '\0') && (strlen(input) != 0));
    return out;
}
