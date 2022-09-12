// Write a function findNeedle() that takes an array full of junk but containing
// one "needle"
//
// After your function finds the needle it should return a message (as a string)
// that says:
//
// "found the needle at position " plus the index it found the needle, so:
//
// Example(Input --> Output)
//
// ["hay", "junk", "hay", "hay", "moreJunk", "needle", "randomJunk"] --> "found
// the needle at position 5"
// Note: In COBOL, it should return "found the needle at position 6"

#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int getDigits(size_t number)
{
    int digits = 0;
    do
    {
        ++digits;
        number /= 10;
    }
    while (number);
    return digits;
}

char* find_needle(const char** haystack, size_t count)
{
    while (strcmp(haystack[--count], "needle") != 0)
        ;

    // "found the needle at position " has length 30, plus 1 for the terminating '\0'
    char* message = (char*) calloc(31 + getDigits(count), sizeof(char));
    sprintf(message, "found the needle at position %zu", count);
    return message;
}
