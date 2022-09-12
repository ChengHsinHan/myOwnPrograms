// SpeedCode #2 - Array Madness
// Objective
// Given two integer arrays a, b, both of length >= 1, create a program that
// returns true if the sum of the squares of each element in a is strictly
// greater than the sum of the cubes of each element in b.
//
// E.g.
//
// array_madness(3, {4, 5, 6}, 3, {1, 2, 3}) == true;
// // because 4 ** 2 + 5 ** 2 + 6 ** 2 > 1 ** 3 + 2 ** 3 + 3 ** 3
// Get your timer out. Are you ready? Ready, get set, GO!!!

#include <stdbool.h>
#include <stddef.h>

bool array_madness(size_t n1, const int arr1[n1], size_t n2, const int arr2[n2])
{
    int difference = 0;

    for (size_t index = 0; index < n1; ++index)
        difference += arr1[index] * arr1[index];

    for (size_t index = 0; index < n2; ++index)
        difference -= arr2[index] * arr2[index] * arr2[index];

    return (difference > 0);
}
