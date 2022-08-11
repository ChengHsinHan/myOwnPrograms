// Given a string of digits, you should replace any digit below 5 with '0' and
// any digit 5 and above with '1'. Return the resulting string.
//
// Note: input will never be an empty string

#include <string>

std::string fakeBin(std::string str)
{
    for (unsigned int index = 0; index < str.length(); ++index)
        str[index] = (str[index] < '5') ? '0' : '1';
    return str;
}
