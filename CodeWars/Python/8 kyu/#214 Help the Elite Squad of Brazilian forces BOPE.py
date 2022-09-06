# The BOPE is the squad of special forces of police that usually handles the
# operations in the Favelas in Rio de Janeiro.
#
# In this Kata you have to write a function that determine the number of
# magazines that every soldier has to have in his bag.
#
# You will receive the weapon and the number of streets that they have to cross.
# Considering that every street the officer shoots 3 times. Bellow there is the
# relation of weapons:
#
# PT92 - 17 bullets
# M4A1 - 30 bullets
# M16A2 - 30 bullets
# PSG1 - 5 bullets
#
# Example:
#
# ["PT92", 6] => 2 (6 streets 3 bullets each)
# ["M4A1", 6] => 1
#
# The return Will always be an integer so as the params.

from typing import Tuple

def mag_number(info: Tuple[str, int]) -> int:
    """
    Return the number of magazines a soldier needs given a
    tuple containing the name of a soldier's weapon and
    the number of streets the soldier has to patrol.

    >>> mag_number(("PT92", 6))
    2
    >>> mag_number(("M4A1", 6))
    1
    """
    match info[0]:
        case "PT92":
            return (info[1] * 3 - 1) // 17 + 1
        case "M4A1" | "M16A2":
            return (info[1] * 3 - 1) // 30 + 1
        case "PSG1":
            return (info[1] * 3 - 1) // 5 + 1
