// Write a function which converts the input string to uppercase.

#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* makeUpperCase(char* string)
{
    // we add 1 for the terminating '\0'
    char* result = (char*) calloc(strlen(string) + 1, sizeof(char));
    for (unsigned int index = 0; string[index]; ++index)
        result[index] = toupper(string[index]);
    return result;
}
