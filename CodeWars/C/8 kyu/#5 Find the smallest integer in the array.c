// Given an array of integers your solution should find the smallest integer.
//
// For example:
//
// Given [34, 15, 88, 2] your solution will return 2
// Given [34, -345, -1, 100] your solution will return -345
// You can assume, for the purpose of this kata, that the supplied array will
// not be empty.

#include <stddef.h>

int find_smallest_int(int* vec, size_t len)
{
    int smallest = vec[0];
    for (size_t index = 1; index < len; ++index)
        if (vec[index] < smallest)
            smallest = vec[index];
    return smallest;
}
