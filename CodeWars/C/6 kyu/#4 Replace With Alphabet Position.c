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
#include <stdio.h>

// returned string has to be dynamically allocated and will be freed by the
// caller
char* alphabet_position(const char* text)
{
    // each letter would consume up to 3 chars (two digits and a space)
    int positionStringLength = strlen(text) * 3 + 1;
    char* positionString = (char*) malloc(positionStringLength * sizeof(char));

    int insertIndex = 0;
    for (int textIndex = 0; text[textIndex]; ++textIndex)
    {
        if ((text[textIndex] >= 'A' && text[textIndex] <= 'Z') ||
            (text[textIndex] >= 'a' && text[textIndex] <= 'z'))
        {
            // '`' and '@' are right before 'a' and 'A' in ASCII table
            short alphabetOrder = (text[textIndex] >= 'a') ? (text[textIndex] - '`') : (text[textIndex] - '@');
            if (textIndex == 0)
            {
                sprintf(positionString + insertIndex, "%d", alphabetOrder);
                insertIndex += (alphabetOrder >= 10) ? 2 : 1;
            }
            else
            {
                sprintf(positionString + insertIndex, " %d", alphabetOrder);
                insertIndex += (alphabetOrder >= 10) ? 3 : 2;
            }
        }
    }
    // if there is no English alphabet, insertIndex should remain intact
    return (insertIndex == 0) ? strdup("") : positionString;
}
