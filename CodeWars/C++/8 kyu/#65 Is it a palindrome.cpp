// Write a function that checks if a given string (case insensitive) is a
// palindrome.

#include <string>

bool isPalindrom(const std::string& str)
{
    for (unsigned int index = 0; index < str.length() / 2; ++index)
        if (tolower(str[index]) != tolower(str[str.length() - index - 1]))
            return false;
    return true;
}
