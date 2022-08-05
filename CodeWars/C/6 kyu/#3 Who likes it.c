// You probably know the "like" system from Facebook and other pages. People can
// "like" blog posts, pictures or other items. We want to create the text that
// should be displayed next to such an item.
//
// Implement the function which takes an array containing the names of people
// that like an item. It must return the display text as shown in the examples:
//
// []                                -->  "no one likes this"
// ["Peter"]                         -->  "Peter likes this"
// ["Jacob", "Alex"]                 -->  "Jacob and Alex like this"
// ["Max", "John", "Mark"]           -->  "Max, John and Mark like this"
// ["Alex", "Jacob", "Mark", "Max"]  -->  "Alex, Jacob and 2 others like this"
// return must be an allocated string
// do not mutate input
// Note: For 4 or more names, the number in "and 2 others" simply increases.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

size_t getDigits(size_t n)
{
    size_t digits = 0;
    while (n)
    {
        digits += 1;
        n /= 10;
    }
    return digits;
}

// result string must be a heap-allocated, nul-terminated string
// to be freed by the tests suite

char* likes(size_t n, const char* const names[n])
{
    int messageLength = 12; // " likes this" has length 11, +1 for '\0'
    char* message;
    switch (n)
    {
    case 0:
        messageLength += 6; // "no one" has length 6
        message = (char*) calloc(messageLength, 1);
        sprintf(message, "no one likes this");
        break;
    case 1:
        messageLength += strlen(names[0]);
        message = (char*) calloc(messageLength, 1);
        sprintf(message, "%s likes this", names[0]);
        break;
    case 2:
        messageLength += strlen(names[0]) + 5 + strlen(names[1]); // " and " has length 5
        message = (char*) calloc(messageLength, 1);
        sprintf(message, "%s and %s like this", names[0], names[1]);
        break;
    case 3:
        messageLength += strlen(names[0]) + 2 + strlen(names[1]) + 5 + strlen(names[2]); // ", " and " and " have length 2 and 5
        message = (char*) calloc(messageLength, 1);
        sprintf(message, "%s, %s and %s like this", names[0], names[1], names[2]);
        break;
    default:
        messageLength += strlen(names[0]) + 2 + strlen(names[1]) + 12 + getDigits(n - 2); // ", " and " and %d others " hav length 2 and 5 + getDigits(n-2)
        message = (char*) calloc(messageLength, 1);
        sprintf(message, "%s, %s and %d others like this", names[0], names[1], n - 2);
        break;
    }
    return message;
}
