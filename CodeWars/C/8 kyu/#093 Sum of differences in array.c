// Your task is to sum the differences between consecutive pairs in the array in
// descending order.
//
// Example
// [2, 1, 10]  -->  9
// In descending order: [10, 2, 1]
//
// Sum: (10 - 2) + (2 - 1) = 8 + 1 = 9
//
// If the array is empty or the array has only one element the result should be
// 0 (Nothing in Haskell, None in Rust).

#include <stddef.h>

int diffsum(const int* arr, size_t n)
{
    int max = arr[0];
    int min = arr[0];
    for (size_t index = 0; index < n; ++index)
    {
        if (arr[index] > max)
            max = arr[index];

        if (arr[index] < min)
            min = arr[index];
    }
    return (max - min);
}
