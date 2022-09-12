// Description:
// Remove n exclamation marks in the sentence from left to right. n is positive
// integer.
//
// Examples
// remove("Hi!",1) === "Hi"
// remove("Hi!",100) === "Hi"
// remove("Hi!!!",1) === "Hi!!"
// remove("Hi!!!",100) === "Hi"
// remove("!Hi",1) === "Hi"
// remove("!Hi!",1) === "Hi!"
// remove("!Hi!",100) === "Hi"
// remove("!!!Hi !!hi!!! !hi",1) === "!!Hi !!hi!!! !hi"
// remove("!!!Hi !!hi!!! !hi",3) === "Hi !!hi!!! !hi"
// remove("!!!Hi !!hi!!! !hi",5) === "Hi hi!!! !hi"
// remove("!!!Hi !!hi!!! !hi",100) === "Hi hi hi"

#include <stdlib.h>
#include <string.h>

char* remove(const char* str_in, int n)
{
    char* str_out = (char*) calloc(strlen(str_in) + 1, sizeof(char));
    char* outputPtr = str_out;
    for (const char* inputPtr = str_in; *inputPtr; ++inputPtr)
    {
        if ((*inputPtr == '!') && (n > 0))
            --n;
        else
            *(outputPtr++) = *inputPtr;
    }
    return str_out;
}
