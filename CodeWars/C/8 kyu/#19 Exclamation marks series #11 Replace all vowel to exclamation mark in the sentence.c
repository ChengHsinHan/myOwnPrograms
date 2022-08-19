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
    const char vowels[] = "aeiouAEIOU";
    for (char* charPtr = replaceString; *charPtr; ++charPtr)
        if (strchr(vowels, *charPtr))
            *charPtr = '!';
    return replaceString;
}
