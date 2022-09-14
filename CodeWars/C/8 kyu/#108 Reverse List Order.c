// In this kata you will create a function that takes in a list and returns a
// list with the reverse order.
//
// Examples (Input -> Output)
// * [1, 2, 3, 4]  -> [4, 3, 2, 1]
// * [9, 2, 0, 7]  -> [7, 0, 2, 9]

#include <stdlib.h>

int* reverse_list(const int* array, size_t length)
{
    int* reverse = (int*) calloc(length, sizeof(int));
    for (size_t index = 0; index < length; ++index)
        reverse[index] = array[length - index - 1];
    return reverse;
}
