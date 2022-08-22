// At the annual family gathering, the family likes to find the oldest living
// family member’s age and the youngest family member’s age and calculate the
// difference between them.
//
// You will be given an array of all the family members' ages, in any order. The
// ages will be given in whole numbers, so a baby of 5 months, will have an
// ascribed ‘age’ of 0. Return a new array (a tuple in Python) with [youngest
// age, oldest age, difference between the youngest and oldest age].

#include <stdlib.h>

int* difference_in_ages(size_t a, const int ages[a])
{
    int* difference = (int*) calloc(3, sizeof(int));
    difference[0] = ages[0];
    difference[1] = ages[0];
    for (size_t index = 0; index < a; ++index)
    {
        if (ages[index] < difference[0])
            difference[0] = ages[index];

        if (ages[index] > difference[1])
            difference[1] = ages[index];
    }
    difference[2] = difference[1] - difference[0];
    return difference;
}
