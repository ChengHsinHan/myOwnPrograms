// Implement a function named generateRange(min, max, step), which takes three
// arguments and generates a range of integers from min to max, with the step.
// The first integer is the minimum value, the second is the maximum of the
// range and the third is the step. (min < max)
//
// Task
// Implement a function named
//
// generate_range(2, 10, 2, *n) # returns {2, 4, 6, 8, 10}, sets n to 5
// generate_range(1, 10, 3, *n) # returns    {1, 4, 7, 10}, sets n to 4
// Note
// min < max
// step > 0
// the range does not HAVE to include max (depending on the step)

// 1) dynamically allocate memory for the return array
// 2) assign the size of this array to the pointer *sz

#include <stdlib.h>

int* generate_range(int min, int max, int step, size_t* sz)
{
    *sz = 0;
    int* range = (int*) calloc((max - min) / step + 1, sizeof(int));
    for (int value = min; value <= max; value += step)
        range[(*sz)++] = value;
    return range;
}
