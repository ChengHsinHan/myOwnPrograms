// An isogram is a word that has no repeating letters, consecutive or
// non-consecutive. Implement a function that determines whether a string that
// contains only letters is an isogram. Assume the empty string is an isogram.
// Ignore letter case.
//
// Example: (Input --> Output)
//
// "Dermatoglyphics" --> true
// "aba" --> false
// "moOse" --> false (ignore letter case)

#include <string>

bool is_isogram(std::string str)
{
    unsigned long long int seen = 0;
    for (const auto letter: str)
    {
        short bitShift = (letter > 'a') ? (letter - 'a') : (letter - 'A');
        if (seen & (1ULL << bitShift))
            return false;
        seen |= (1ULL << bitShift);
    }
    return true;
}
