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
    int out_index = 0;
    for (int index = 0; str_in[index]; ++index)
    {
        if ((str_in[index] == '!') && (n > 0))
            --n;
        else
            str_out[out_index++] = str_in[index];
    }
    return str_out;
}
