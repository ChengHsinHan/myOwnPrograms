// Take an array and remove every second element from the array. Always keep the
// first element and start removing with the next element.
//
// Example:
// size_t length = 5;
// remove_every_other(&length, {1, 2, 3, 4, 5});
// // -->  {1, 3, 5}
// None of the arrays will be empty, so you don't have to worry about that!

#include <stddef.h>

void remove_every_other(size_t* length, int array[*length])
{
    // mutate the array in-place
    size_t originalLength = *length;
    *length = 0;
    for (size_t index = 0; index < originalLength; ++index)
        if (index % 2 == 0)
            array[(*length)++] = array[index];
}
