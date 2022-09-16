// Task
// Give you two strings: s1 and s2. If they are opposite, return true;
// otherwise, return false. Note: The result should be a boolean value, instead
// of a string.
//
// The opposite means: All letters of the two strings are the same, but the case
// is opposite. you can assume that the string only contains letters or it's a
// empty string. Also take note of the edge case - if both strings are empty
// then you should return false/False.
//
// Examples (input -> output)
// "ab","AB"     -> true
// "aB","Ab"     -> true
// "aBcd","AbCD" -> true
// "AB","Ab"     -> false
// "",""         -> false

#include <string>

bool isOpposite(const std::string& s1, const std::string& s2)
{
    // early termination for empty strings, if one of them is empty, always return false
    if (s1.length() == 0)
        return false;

    for (unsigned int index = 0; index < s1.length(); ++index)
        // the difference of ASCII value of uppercase and lowercase is 32 for a
        // specific letter, and also because 32 is a power of 2, thus ^ 32 would
        // swap from lowercase to uppercase and vice versa
        if ((s1[index] ^ 32) != s2[index])
            return false;

    // deal with cases when s2 is longer than s1
    return (s1.length() == s2.length());
}
