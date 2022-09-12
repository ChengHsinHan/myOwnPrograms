// Sentence Smash
// Write a function that takes an array of words and smashes them together into
// a sentence and returns the sentence. You can ignore any need to sanitize
// words or add punctuation, but you should add spaces between each word. Be
// careful, there shouldn't be a space at the beginning or the end of the
// sentence!
//
// Example
// ['hello', 'world', 'this', 'is', 'great']  =>  'hello world this is great'

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* smash(const char* words[], size_t nb_words)
{
    // allocate a string on the heap, memory will be freed
    int sentenceLength = 0;
    for (size_t index = 0; index < nb_words; ++index)
        // +1 for blank space or terminating '\0' after each word
        sentenceLength += (strlen(words[index]) + 1);

    char* sentence = (char*) calloc(sentenceLength, sizeof(char));
    char* charPtr = sentence;

    for (size_t index = 0; index < nb_words; ++index)
        charPtr += (index != nb_words - 1) ? sprintf(charPtr, "%s ", words[index]) : sprintf(charPtr, "%s", words[index]);

    return sentence;
}
