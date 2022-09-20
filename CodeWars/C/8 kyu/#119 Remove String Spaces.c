// Simple, remove the spaces from the string, then return the resultant string.
//
// For C and Nasm, you must return a new dynamically allocated string.

#include <stdlib.h>
#include <string.h>

char* no_space(const char* str_in)
{
    char* str_out = (char*) calloc(strlen(str_in) + 1, sizeof(char));
    char* outputPtr = str_out;
    for (unsigned int index = 0; str_in[index]; ++index)
        if (str_in[index] != ' ')
            *(outputPtr++) = str_in[index];
    return str_out;
}
