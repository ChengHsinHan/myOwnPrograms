# Your task is simply to count the total number of lowercase letters in a
# string.
#
# Examples
# lowercaseCount("abc"); ===> 3
#
# lowercaseCount("abcABC123"); ===> 3
#
# lowercaseCount("abcABC123!@€£#$%^&*()_-+=}{[]|\':;?/>.<,~"); ===> 3
#
# lowercaseCount(""); ===> 0;
#
# lowercaseCount("ABC123!@€£#$%^&*()_-+=}{[]|\':;?/>.<,~"); ===> 0
#
# lowercaseCount("abcdefghijklmnopqrstuvwxyz"); ===> 26

def lowercase_count(strng):
    return sum(character.islower() for character in strng)
