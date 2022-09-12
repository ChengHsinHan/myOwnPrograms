// Triple Trouble
// Create a function that will return a string that combines all of the letters
// of the three inputed strings in groups. Taking the first letter of all of the
// inputs and grouping them next to each other. Do this for every letter, see
// example below!
//
// E.g. Input: "aa", "bb" , "cc" => Output: "abcabc"
//
// Note: You can expect all of the inputs to be the same length.

#include <stdlib.h>
#include <string.h>

char* triple_trouble(const char* one, const char* two, const char* three)
{
    char* combined = (char*) calloc(strlen(one) * 3 + 1, sizeof(char));
    for (unsigned int index = 0; index < strlen(one); ++index)
    {
        combined[3 * index]     = one[index];
        combined[3 * index + 1] = two[index];
        combined[3 * index + 2] = three[index];
    }
    return combined;
}
