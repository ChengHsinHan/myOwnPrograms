// When provided with a letter, return its position in the alphabet.
//
// Input :: "a"
//
// Ouput :: "Position of alphabet: 1"

#include <stdlib.h>
#include <stdio.h>

char* position(char alphabet)
{
    // "Position of alphabet: " has length 22, we add 2 for possible two digits
    // and add 1 for terminating '\0'
    char* output = (char*) calloc(25, sizeof(char));
    sprintf(output, "Position of alphabet: %d", alphabet - '`');
    return output;
}
