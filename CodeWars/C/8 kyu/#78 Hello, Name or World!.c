// Define a method hello that returns "Hello, Name!" to a given name, or says
// Hello, World! if name is not given (or passed as an empty String).
//
// Assuming that name is a String and it checks for user typos to return a name
// with a first capital letter (Xxxx).
//
// Examples:
//
// * With `name` = "john"  => return "Hello, John!"
// * With `name` = "aliCE" => return "Hello, Alice!"
// * With `name` not given
//   or `name` = ""        => return "Hello, World!"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* hello(const char* name)
{
    // early termination for empty strings
    if (strcmp(name, "") == 0)
        return strdup("Hello, World!");

    // "Hello, " and "!" combined length is 8, add 1 for terminating '\0'
    char* say = (char*) calloc(9 + strlen(name), sizeof(char));
    char* sayPosition = say;

    sayPosition += sprintf(sayPosition, "Hello, ");
    for (unsigned int index = 0; index < strlen(name); ++index)
    {
        if (index == 0)
            *(sayPosition++) = toupper(name[index]);
        else
            *(sayPosition++) = tolower(name[index]);
    }
    *sayPosition = '!';
    return say;
}
