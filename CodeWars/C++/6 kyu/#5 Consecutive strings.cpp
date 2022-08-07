// You are given an array(list) strarr of strings and an integer k. Your task is
// to return the first longest string consisting of k consecutive strings taken
// in the array.
//
// Examples:
// strarr = ["tree", "foling", "trashy", "blue", "abcdef", "uvwxyz"], k = 2
//
// Concatenate the consecutive strings of strarr by 2, we get:
//
// treefoling   (length 10)  concatenation of strarr[0] and strarr[1]
// folingtrashy ("      12)  concatenation of strarr[1] and strarr[2]
// trashyblue   ("      10)  concatenation of strarr[2] and strarr[3]
// blueabcdef   ("      10)  concatenation of strarr[3] and strarr[4]
// abcdefuvwxyz ("      12)  concatenation of strarr[4] and strarr[5]
//
// Two strings are the longest: "folingtrashy" and "abcdefuvwxyz".
// The first that came is "folingtrashy" so
// longest_consec(strarr, 2) should return "folingtrashy".
//
// In the same way:
// longest_consec(["zone", "abigail", "theta", "form", "libe", "zas", "theta",
// "abigail"], 2) --> "abigailtheta"
// n being the length of the string array, if n = 0 or k > n or k <= 0 return ""
// (return Nothing in Elm, "nothing" in Erlang).
//
// Note
// consecutive strings : follow one after another without an interruption

#include <string>
#include <vector>

class LongestConsec
{
public:
    static std::string longestConsec(std::vector<std::string>& strarr, int k)
    {
        if ((strarr.empty()) || (k > strarr.size()) || (k <= 0))
            return "";

        // sum up the length of first k-strings, store it in longestLength
        int longestLength = 0;
        for (int index = 0; index < k; ++index)
            longestLength += strarr.at(index).length();

        // record the starting index of the longest consecutive strings in strarr
        int startingIndex = 0;
        int currentLength = longestLength;
        for (int nextIndex = k; nextIndex < strarr.size(); ++nextIndex)
        {
            // the length of the next consecutive string is currentLength plus
            // that of the next string in strarr and minus that of the first
            // string that constructs the current consecutive string
            currentLength += (strarr.at(nextIndex).length() - strarr.at(nextIndex - k).length());
            if (currentLength > longestLength)
            {
                longestLength = currentLength;
                startingIndex = nextIndex - k + 1;
            }
        }

        std::string result = "";
        for (int count = 0; count < k; ++count)
            result += strarr.at(startingIndex + count);

        return result;
    }
};
