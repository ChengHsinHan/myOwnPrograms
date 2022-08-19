// Description:
// Replace all vowel to exclamation mark in the sentence. aeiouAEIOU is vowel.
//
// Examples
// replace("Hi!") === "H!!"
// replace("!Hi! Hi!") === "!H!! H!!"
// replace("aeiou") === "!!!!!"
// replace("ABCDE") === "!BCD!"

#include <string>

using namespace std;

string replace(const string& s)
{
    string replaceString = "";
    string vowels = "aeiouAEIOU";

    for (const auto character : s)
        replaceString += (vowels.find(character) != string::npos) ? '!' : character;
    return replaceString;
}
