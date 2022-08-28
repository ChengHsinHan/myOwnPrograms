// Define a function that removes duplicates from an array of numbers and
// returns it as a result.
//
// The order of the sequence has to stay the same.

#include <stdlib.h>

int* distinct(const int* values, size_t count, size_t* pResultCount)
{
    // Please make sure you store the number of distinct values
    // in the memory pointed to by pResultCount. If values == NULL
    // or count == 0, then *pResultCount == 0.
    int max = values[0];
    for (size_t index = 1; index < count; ++index)
        if (values[index] > max)
            max = values[index];

    // seen is used as a "bit mask", which makes use of the fact that calloc
    // initializes the array to zeros, or '\0' in char*
    char* seen = (char*) calloc(max + 1, sizeof(char));
    int* result = (int*) calloc(count, sizeof(int));
    *pResultCount = 0;
    for (size_t index = 0; index < count; ++index)
        if (!seen[values[index]])
        {
            seen[values[index]] = 's'; // s stands for "seen"
            result[(*pResultCount)++] = values[index];
        }
    return result;
}
