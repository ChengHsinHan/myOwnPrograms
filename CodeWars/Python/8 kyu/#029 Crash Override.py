# Every budding hacker needs an alias! The Phantom Phreak, Acid Burn, Zero Cool
# and Crash Override are some notable examples from the film Hackers.
#
# Your task is to create a function that, given a proper first and last name,
# will return the correct alias.
#
# Two objects that return a one word name in response to the first letter of the
# first name and one for the first letter of the surname are already given.
#
# If the first character of either of the names given to the function is not a
# letter from A - Z, you should return "Your name must start with a letter from
# A - Z."
#
# Sometimes people might forget to capitalize the first letter of their name so
# your function should accommodate for these grammatical errors.
#
# FIRST_NAME = {'A': 'Alpha', 'B': 'Beta', 'C': 'Cache', ...}
# SURNAME = {'A': 'Analogue', 'B': 'Bomb', 'C': 'Catalyst' ...}
#
# alias_gen('Larry', 'Brentwood') == 'Logic Bomb'
# alias_gen('123abc', 'Petrovic') == 'Your name must start with a letter from A
# - Z.'
# Happy hacking!

def alias_gen(f_name, l_name):
    return f"{FIRST_NAME[f_name[0].upper()]} {SURNAME[l_name[0].upper()]}" if (f_name[0].isalpha() and l_name[0].isalpha()) else "Your name must start with a letter from A - Z."
