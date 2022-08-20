// Count the number of Duplicates
// Write a function that will return the count of distinct case-insensitive
// alphabetic characters and numeric digits that occur more than once in the
// input string. The input string can be assumed to contain only alphabets (both
 // uppercase and lowercase) and numeric digits.
//
// Example
// "abcde" -> 0 # no characters repeats more than once
// "aabbcde" -> 2 # 'a' and 'b'
// "aabBcde" -> 2 # 'a' occurs twice and 'b' twice (`b` and `B`)
// "indivisibility" -> 1 # 'i' occurs six times
// "Indivisibilities" -> 2 # 'i' occurs seven times and 's' occurs twice
// "aA11" -> 2 # 'a' and '1'
// "ABBA" -> 2 # 'A' and 'B' each occur twice

#include <stddef.h>

size_t duplicate_count(const char* text)
{
    unsigned long long int seen = 0;
    unsigned long long int duplicate = 0;

    for (int iii = 0; text[iii]; ++iii)
    {
        short bitShift = (text[iii] >= 'a') ? (text[iii] - '0' - ('a' - 'A')) : (text[iii] - '0');
        duplicate |= (seen & (1ULL << bitShift));
        seen |= (1ULL << bitShift);
    }

    return __builtin_popcountll(duplicate);
}
