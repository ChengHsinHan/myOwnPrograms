// You take your son to the forest to see the monkeys. You know that there are a
// certain number there (n), but your son is too young to just appreciate the
// full number, he has to start counting them from 1.
//
// As a good parent, you will sit and count with him. Given the number (n),
// populate an array with all numbers up to and including that number, but
// excluding zero.
//
// For example(Input --> Output):
//
// 10 --> [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
//  1 --> [1]

#include <stddef.h>
#include <stdlib.h>

size_t* monkey_count(size_t n, size_t* pResultCount)
{
    // Please make sure you store the number of values
    // in the array you are returning from the function
    // in the memory pointed to by the pResultCount
    // pointer.
    size_t* result = (size_t*) calloc(n + 1, sizeof(size_t));
    for (*pResultCount = 0; *pResultCount < n; ++(*pResultCount))
        result[*pResultCount] = *pResultCount + 1;
    return result;
}
