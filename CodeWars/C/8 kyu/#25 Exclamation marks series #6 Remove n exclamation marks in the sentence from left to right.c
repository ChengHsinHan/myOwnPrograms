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
    for (const char* charPtr = str_in; *charPtr; ++charPtr)
    {
        if ((*charPtr == '!') && (n > 0))
            --n;
        else
            strncat(str_out, charPtr, 1);
    }
    return str_out;
}
