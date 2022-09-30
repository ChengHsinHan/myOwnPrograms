// Write a function that accepts an integer n and a string s as parameters, and
// returns a string of s repeated exactly n times.
//
// Examples (input -> output)
// 6, "I"     -> "IIIIII"
// 5, "Hello" -> "HelloHelloHelloHelloHello"

#include <string.h>
#include <stdlib.h>

char* repeat_str(size_t count, const char* src)
{
    char* repeat_string = (char*) calloc(count * strlen(src) + 1, sizeof(char));
    for (size_t value = 0; value < count; ++value)
        strcat(repeat_string, src);
    return repeat_string;
}
