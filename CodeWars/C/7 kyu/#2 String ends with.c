// Complete the solution so that it returns true if the first argument(string)
// passed in ends with the 2nd argument (also a string).
//
// Examples:
//
// solution('abc', 'bc') // returns true
// solution('abc', 'd') // returns false

#include <stdbool.h>
#include <string.h>

bool solution(const char* string, const char* ending)
{
    int endingStartIndex = strlen(string) - strlen(ending);
    return (endingStartIndex < 0) ? false : (strcmp(string + endingStartIndex, ending) == 0);
}
