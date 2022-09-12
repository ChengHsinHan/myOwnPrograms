// Coding 3min : Jumping Dutch act
//
// This is the simple version of Shortest Code series. If you need some
// challenges, please try the challenge version
//
// Task:
// Mr. despair wants to jump off Dutch act, So he came to the top of a building.
//
// Scientific research shows that a man jumped from the top of the roof, when
// the floor more than 6, the person will often die in an instant; When the
// floor is less than or equal to 6, the person will not immediately die, he
// would scream. (without proof)
//
// Input: floor, The height of the building (floor)
//
// Output: a string, The voice of despair(When jumping Dutch act)
//
// Example:
// sc(2) should return "Aa~ Pa! Aa!"
//
// It means:
//
// Mr. despair jumped from the 2 floor, the voice is "Aa~"
// He fell on the ground, the voice is "Pa!"
// He did not die immediately, and the final voice was "Aa!"
// sc(6) should return "Aa~ Aa~ Aa~ Aa~ Aa~ Pa! Aa!"
//
// sc(7) should return "Aa~ Aa~ Aa~ Aa~ Aa~ Aa~ Pa!"
//
// sc(10) should return "Aa~ Aa~ Aa~ Aa~ Aa~ Aa~ Aa~ Aa~ Aa~ Pa!"
//
// if floor<=1, Mr. despair is safe, return ""
//
// The final advice
// Just play in this kata, Don't experiment in real life ;-)
//
// ##Series:
//
// Bug in Apple
// Father and Son
// Jumping Dutch act
// Planting Trees
// Give me the equation
// Find the murderer
// Reading a Book
// Eat watermelon
// Special factor
// Guess the Hat
// Symmetric Sort
// Are they symmetrical?
// Max Value
// Trypophobia
// Virus in Apple
// Balance Attraction
// Remove screws I
// Remove screws II
// Regular expression compression
// Collatz Array(Split or merge)
// Tidy up the room
// Waiting for a Bus

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char* sc(int n)
{
    // early termination for n <= 1
    if (n <= 1)
        return strdup("");

    // each floor contribute at most 4 characters ("Aa~ " or "Pa! "), except the
    // last one, which always contributes 3 characters ("Aa!" or "Pa!")
    // consider when n <= 6, there will be extra voice after "Pa!", we allocate
    // 4 * (n + 1) characters here, which already includes the terminating '\0'
    char* voice = (char*) calloc(4 * (n + 1), sizeof(char));

    for (int floor = 0; floor < n - 1; ++floor)
        voice = strcat(voice, "Aa~ ");
    voice = (n <= 6) ? strcat(voice, "Pa! Aa!") : strcat(voice, "Pa!");

    return voice;
}
