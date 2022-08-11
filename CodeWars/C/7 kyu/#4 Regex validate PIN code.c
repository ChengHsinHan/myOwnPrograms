// ATM machines allow 4 or 6 digit PIN codes and PIN codes cannot contain
// anything but exactly 4 digits or exactly 6 digits.
//
// If the function is passed a valid PIN string, return true, else return false.
//
// Examples (Input --> Output)
// "1234"   -->  true
// "12345"  -->  false
// "a234"   -->  false

#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool validate_pin(const char* pin)
{
    for (unsigned int index = 0; pin[index]; ++index)
        if (!isdigit(pin[index]))
            return false;
    return ((strlen(pin) == 4) || (strlen(pin) == 6)) ? true : false;
}
