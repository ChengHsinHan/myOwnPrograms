// Welcome.
//
// In this kata you are required to, given a string, replace every letter with
// its position in the alphabet.
//
// If anything in the text isn't a letter, ignore it and don't return it.
//
// "a" = 1, "b" = 2, etc.
//
// Example
// alphabet_position("The sunset sets at twelve o' clock.")
// Should return "20 8 5 19 21 14 19 5 20 19 5 20 19 1 20 20 23 5 12 22 5 15 3
// 12 15 3 11" ( as a string )

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

// returned string has to be dynamically allocated and will be freed by the
// caller
char* alphabet_position(const char* text)
{
    // each letter would consume up to 3 chars (two digits and a space)
    char* positionString = (char*) calloc(3 * strlen(text) + 1, sizeof(char));

    // charPtr is used to add the desired alphabet order in positionString
    char* charPtr = positionString;

    for (unsigned int textIndex = 0; text[textIndex]; ++textIndex)
    {
        if (isalpha(text[textIndex]))
        {
            // '`' and '@' are right before 'a' and 'A' in ASCII table
            short alphabetOrder = (text[textIndex] >= 'a') ? (text[textIndex] - '`') : (text[textIndex] - '@');

            // sprintf returns how many characters were put in charPtr
            // so we can make use the return value to move charPtr forward
            charPtr += (textIndex == 0) ? sprintf(charPtr, "%d", alphabetOrder) : sprintf(charPtr, " %d", alphabetOrder);
        }
    }
    // if there is no English alphabet, charPtr should remain pointing at the same position of positionString
    return (charPtr == positionString) ? strdup("") : positionString;
}
