// Description:
// Remove all exclamation marks from the end of sentence.
//
// Examples
// remove("Hi!") === "Hi"
// remove("Hi!!!") === "Hi"
// remove("!Hi") === "!Hi"
// remove("!Hi!") === "!Hi"
// remove("Hi! Hi!") === "Hi! Hi"
// remove("Hi") === "Hi"

#include <string.h>

char* remove_marks(const char* str_in, char* str_out)
{
    // str_out is as large as str_in
    strcpy(str_out, str_in);
    int index = strlen(str_in) - 1;
    while (str_in[index] == '!')
        str_out[index--] = '\0';
    return str_out;
}
