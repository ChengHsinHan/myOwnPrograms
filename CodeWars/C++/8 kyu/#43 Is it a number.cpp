// Given a string s, write a method (function) that will return true if its a
// valid single integer or floating number or false if its not.
//
// Valid examples, should return true:
//
// isDigit("3")
// isDigit("  3  ")
// isDigit("-3.23")
// should return false:
//
// isDigit("3-4")
// isDigit("  3   5")
// isDigit("3 5")
// isDigit("zero")

#include <string>
#include <sstream>

bool is_digit(std::string s)
{
    // early termination for blank spaces strings
    if (s.find_first_not_of(' ') == std::string::npos)
        return false;

    std::istringstream iss(s);
    double value;
    std::string remain;

    // trim leading blank spaces and put the first numeral into value, if any
    // then put the remaining parts into remain, with leading blank spaces trimmed
    iss >> value >> remain;

    // if there's only one numeral, then remain should catch nothing and iss shall
    // reach the end of the file
    return ((remain == "") && iss.eof());
}
