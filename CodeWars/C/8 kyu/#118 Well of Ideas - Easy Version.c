// For every good kata idea there seem to be quite a few bad ones!
//
// In this kata you need to check the provided array (x) for good ideas 'good'
// and bad ideas 'bad'. If there are one or two good ideas, return 'Publish!',
// if there are more than 2 return 'I smell a series!'. If there are no good
// ideas, as is often the case, return 'Fail!'.
//
// For C: do not dynamically allocate memory, instead return a string literal

#include <stddef.h>
#include <string.h>

const char* well(size_t n, const char* ideas[n])
{
    int good_idea_count = 0;
    for (size_t index = 0; index < n; ++index)
        if (strcmp(ideas[index], "good") == 0)
            ++good_idea_count;

    switch (good_idea_count)
    {
    case 0:
        return "Fail!";
    case 1:
    case 2:
        return "Publish!";
    default:
        return "I smell a series!";
    }
}
