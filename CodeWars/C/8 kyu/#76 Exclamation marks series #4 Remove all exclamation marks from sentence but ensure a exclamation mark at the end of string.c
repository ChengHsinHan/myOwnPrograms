// Description:
// Remove all exclamation marks from sentence but ensure a exclamation mark at
// the end of string. For a beginner kata, you can assume that the input data is
// always a non empty string, no need to verify it.
//
// Examples
// remove("Hi!") === "Hi!"
// remove("Hi!!!") === "Hi!"
// remove("!Hi") === "Hi!"
// remove("!Hi!") === "Hi!"
// remove("Hi! Hi!") === "Hi Hi!"
// remove("Hi") === "Hi!"

#include <stdlib.h>
#include <string.h>

char* remove_bang_ptr(const char* string)
{
    // allocate a new string on the heap; memory will be freed
    // +2 for "!" and terminating '\0'
    char* result = (char*) calloc(strlen(string) + 2, sizeof(char));
    char* outputPositionPtr = result;

    for (const char* charPtr = string; *charPtr; ++charPtr)
        if (*charPtr != '!')
            *(outputPositionPtr++) = *charPtr;
    *outputPositionPtr = '!';

    return result;
}
