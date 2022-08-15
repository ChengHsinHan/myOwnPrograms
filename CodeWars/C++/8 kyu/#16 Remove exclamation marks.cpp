// Write function RemoveExclamationMarks which removes all exclamation marks
// from a given string.

#include <string>

std::string removeExclamationMarks(std::string str)
{
    str.erase(std::remove(str.begin(), str.end(), '!'), str.end());
    return str;
}
