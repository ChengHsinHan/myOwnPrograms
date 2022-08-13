// Complete the function that accepts a string parameter, and reverses each word
// in the string. All spaces in the string should be retained.
//
// Examples
// "This is an example!" ==> "sihT si na !elpmaxe"
// "double  spaces"      ==> "elbuod  secaps"

#include <string>

std::string reverse_words(std::string str)
{
    // result is used to store the final string
    std::string result;

    // word is used to store every single reversed word
    std::string word;
    for (char character : str)
    {
        if (character == ' ')
        {
            result += (word + character);
            word = "";
            continue;
        }
        word = character + word;
    }
    // don't forget to add the final reversed word to result
    result += word;
    
    return result;
}
