# Complete the function, which calculates how much you need to tip based on the
# total amount of the bill and the service.
#
# You need to consider the following ratings:
#
# Terrible: tip 0%
# Poor: tip 5%
# Good: tip 10%
# Great: tip 15%
# Excellent: tip 20%
# The rating is case insensitive (so "great" = "GREAT"). If an unrecognised
# rating is received, then you need to return:
#
# "Rating not recognised" in Javascript, Python and Ruby...
# ...or null in Java
# ...or -1 in C#
# Because you're a nice person, you always round up the tip, regardless of the
# service.

import math

def calculate_tip(amount, rating):
    return {"terrible" : math.ceil(amount * 0),
            "poor"     : math.ceil(amount * 0.05),
            "good"     : math.ceil(amount * 0.1),
            "great"    : math.ceil(amount * 0.15),
            "excellent": math.ceil(amount * 0.2)}.get(rating.lower(), "Rating not recognised")