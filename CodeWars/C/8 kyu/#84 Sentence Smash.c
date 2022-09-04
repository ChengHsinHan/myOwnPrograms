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
        // +1 for blank space after each word
        sentenceLength += (strlen(words[index]) + 1);

    // although sentenceLength +1 for every word including the last one, we still
    // have to allocate one extra space because the usage of sprintf would exceed
    // sentenceLength for the last word
    char* sentence = (char*) calloc(sentenceLength + 1, sizeof(char));
    char* charPtr = sentence;

    for (size_t index = 0; index < nb_words; ++index)
        charPtr += sprintf(charPtr, "%s ", words[index]);
    sentence[sentenceLength - 1] = '\0';

    return sentence;
}
