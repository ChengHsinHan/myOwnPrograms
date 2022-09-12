// In this kata, your job is to return the two distinct highest values in a
// list. If there're less than 2 unique values, return as many of them, as
// possible.
//
// The result should also be ordered from highest to lowest.
//
// Examples:
//
// [4, 10, 10, 9]  =>  [10, 9]
// [1, 1, 1]  =>  [1]
// []  =>  []

#include <stddef.h>
#include <limits.h>
#include <stdbool.h>

size_t two_highest(size_t length, const long long array[length], long long result[2])
{
    // early termination for length 0
    if (length == 0)
        return 0;

    // result[0] is always holding the largest number
    result[0] = LLONG_MIN;
    long long secondLargest = LLONG_MIN;
    bool isMinInArray = false;
    for (size_t index = 0; index < length; ++index)
    {
        if (array[index] == LLONG_MIN)
            isMinInArray = true;
        else if (array[index] > result[0])
        {
            secondLargest = result[0];
            result[0] = array[index];
        }
        else if ((array[index] < result[0]) && (array[index] > secondLargest))
            secondLargest = array[index];
    }

    // if largest == LLONG_MIN, all the elements in array must be LLONG_MIN
    // and if secondLargest == LLONG_MIN **not due to** existence of LLONG_MIN in
    // array, it must imply that all the elements in array are the same
    if ((result[0] == LLONG_MIN) || ((secondLargest == LLONG_MIN) && !isMinInArray))
        return 1;
    else
    {
        result[1] = secondLargest;
        return 2;
    }
}
