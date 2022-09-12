// Description:
// Replace all vowel to exclamation mark in the sentence. aeiouAEIOU is vowel.
//
// Examples
// replace("Hi!") === "H!!"
// replace("!Hi! Hi!") === "!H!! H!!"
// replace("aeiou") === "!!!!!"
// replace("ABCDE") === "!BCD!"

#include <string.h>

char* replace(const char* s)
{
    char* replaceString = strdup(s);
    for (char* charPtr = replaceString; *charPtr; ++charPtr)
        if ((*charPtr == 'a') || (*charPtr == 'e') || (*charPtr == 'i') || (*charPtr == 'o') || (*charPtr == 'u') ||
            (*charPtr == 'A') || (*charPtr == 'E') || (*charPtr == 'I') || (*charPtr == 'O') || (*charPtr == 'U'))
            *charPtr = '!';
    return replaceString;
}
