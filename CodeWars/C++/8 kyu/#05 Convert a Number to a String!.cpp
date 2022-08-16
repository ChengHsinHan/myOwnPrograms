// We need a function that can transform a number (integer) into a string.
//
// What ways of achieving this do you know?
//
// In C, return a dynamically allocated string that will be freed by the test
// suite.
//
// Examples (input --> output):
// 123  --> "123"
// 999  --> "999"
// -100 --> "-100"

#include <string>

std::string number_to_string(int num)
{
    return std::to_string(num);
}
