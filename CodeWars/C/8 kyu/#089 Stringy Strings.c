// write me a function stringy that takes a size and returns a string of
// alternating '1s' and '0s'.
//
// the string should start with a 1.
//
// a string with size 6 should return :'101010'.
//
// with size 4 should return : '1010'.
//
// with size 12 should return : '101010101010'.
//
// The size will always be positive and will only use whole numbers.

#include <stdlib.h>

char* stringy(size_t size)
{
    // return a malloced string, memory will be freed
    char* string = (char*) calloc(size + 1, sizeof(char));
    for (size_t count = 0; count < size; ++count)
        string[count] = '1' - (count % 2);
    return string;
}
