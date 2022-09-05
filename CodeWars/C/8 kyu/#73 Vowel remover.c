// Create a function called shortcut to remove the lowercase vowels (a, e, i, o,
// u ) in a given string.
//
// Examples
// "hello"     -->  "hll"
// "codewars"  -->  "cdwrs"
// "goodbye"   -->  "gdby"
// "HELLO"     -->  "HELLO"
// don't worry about uppercase vowels
// y is not considered a vowel for this kata

char* shortcut(char* str_out, const char* str_in)
{
    char* outPtr = str_out;
    for (const char* inPtr = str_in; *inPtr; ++inPtr)
        if ((*inPtr != 'a') && (*inPtr != 'e') && (*inPtr != 'i') && (*inPtr != 'o') && (*inPtr != 'u'))
            *(outPtr++) = *inPtr;
    *outPtr = '\0';
    return str_out;
}
