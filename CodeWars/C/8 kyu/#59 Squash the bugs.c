// Simple challenge - eliminate all bugs from the supplied code so that the code
// runs and outputs the expected value. Output should be the length of the
// longest word, as a number.
//
// There will only be one 'longest' word.

#include <stddef.h>
#include <ctype.h>

size_t find_longest(const char* words)
{
    size_t length = 0, max_length = 0;
    const char* pchar = words;

    char c;
    while ((c = *pchar++))
    {
        if (isspace(c))
        {
            if (length > max_length)
            {
                max_length = length;
            }
            length = 0;
        }
        else
        {
            length++;
        }
    }
    return (max_length > length) ? max_length : length;
}
