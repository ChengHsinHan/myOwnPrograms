# When provided with a letter, return its position in the alphabet.
#
# Input :: "a"
#
# Ouput :: "Position of alphabet: 1"

def position(alphabet):
    # '`' is right before 'a' in ASCII table
    return f"Position of alphabet: {ord(alphabet) - ord('`')}"
