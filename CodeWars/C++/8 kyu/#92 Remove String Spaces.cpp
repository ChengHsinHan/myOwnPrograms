// Simple, remove the spaces from the string, then return the resultant string.

#include <string>

std::string no_space(const std::string& x)
{
    std::string outputString = "";
    for (const auto character : x)
        if (character != ' ')
            outputString += character;
    return outputString;
}
