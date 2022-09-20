# This series of katas will introduce you to basics of doing geometry with
# computers.
#
# Point objects have x and y attributes (X and Y in C#) attributes.
#
# Write a function calculating distance between Point a and Point b.
#
# Tests round answers to 6 decimal places.

import math

def distance_between_points(a, b):
    return round(math.dist([a.x, a.y], [b.x, b.y]), 6)
