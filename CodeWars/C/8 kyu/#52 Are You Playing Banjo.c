// Create a function which answers the question "Are you playing banjo?".
// If your name starts with the letter "R" or lower case "r", you are playing
// banjo!
//
// The function takes a name as its only argument, and returns one of the
// following strings:
//
// name + " plays banjo"
// name + " does not play banjo"
// Names given are always valid strings.

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* are_you_playing_banjo(const char* name)
{
    char* answer = (char*) calloc(strlen(name) + 21, sizeof(char));
    if ((*name == 'r') || (*name == 'R'))
        sprintf(answer, "%s plays banjo", name);
    else
        sprintf(answer, "%s does not play banjo", name);
    return answer;
}
