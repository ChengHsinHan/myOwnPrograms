// Create a method none? (JS none) that accepts an array and a block (JS: a
// function), and returns true if the block (/function) returns true for none of
// the items in the array. An empty list should return true.

#include <stdbool.h>
#include <stddef.h>

typedef bool (*Predicate)(int);

bool none(const int* arr, size_t size, Predicate fun)
{
    for (size_t index = 0; index < size; ++index)
        if (fun(arr[index]))
            return false;
    return true;
}
