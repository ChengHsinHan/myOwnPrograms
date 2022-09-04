// Write a function that checks if a given string (case insensitive) is a
// palindrome.

#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool is_palindrome(const char* str_in)
{
    for (unsigned int index = 0; index < strlen(str_in); ++index)
        if (tolower(str_in[index]) != tolower(str_in[strlen(str_in) - index - 1]))
            return false;
    return true;
}
