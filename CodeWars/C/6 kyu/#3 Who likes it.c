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
     // " likes this" has length 11, +1 for '\0'
    int messageLength = 12;
    char* message;
    switch (n)
    {
    case 0:
        // "no one" has length 6
        messageLength += 6;
        message = (char*) malloc(messageLength * sizeof(char));
        sprintf(message, "no one likes this");
        return message;
    case 1:
        messageLength += strlen(names[0]);
        message = (char*) malloc(messageLength * sizeof(char));
        sprintf(message, "%s likes this", names[0]);
        return message;
    case 2:
        // " and " has length 5, also, we cancel the 's' at the end of "likes"
        // combining +5 and -1 we get +4 at the end
        messageLength += (strlen(names[0]) + strlen(names[1]) + 4);
        message = (char*) malloc(messageLength * sizeof(char));
        sprintf(message, "%s and %s like this", names[0], names[1]);
        return message;
    case 3:
        // ", " and " and " have length 2 and 5, combined length would be 7
        // cancel the 's' at the end of "likes", so +7 and -1 combined would +6
        messageLength += (strlen(names[0]) + strlen(names[1]) + strlen(names[2]) + 6);
        message = (char*) malloc(messageLength * sizeof(char));
        sprintf(message, "%s, %s and %s like this", names[0], names[1], names[2]);
        return message;
    default:
        // ", " and " and %d others" have length 2 and 12 + getDigits(n - 2)
        // combined length would be 14 + getDigits(n - 2)
        // cancel the 's' at the end of "likes", combined length would be
        // 13 + getDigits(n - 2)
        messageLength += (strlen(names[0]) + strlen(names[1]) + 13 + getDigits(n - 2));
        message = (char*) malloc(messageLength * sizeof(char));
        sprintf(message, "%s, %s and %d others like this", names[0], names[1], n - 2);
        return message;
    }
}
