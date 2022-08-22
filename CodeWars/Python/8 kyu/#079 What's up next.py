# Given a sequence of items and a specific item in that sequence, return the
# item immediately following the item specified. If the item occurs more than
# once in a sequence, return the item after the first occurence. This should
# work for a sequence of any type.
#
# When the item isn't present or nothing follows it, the function should return
# nil in Clojure and Elixir, Nothing in Haskell, undefined in JavaScript, None
# in Python.
#
# next_item([1, 2, 3, 4, 5, 6, 7], 3) # => 4
# next_item(['Joe', 'Bob', 'Sally'], 'Bob') # => "Sally"

def next_item(xs, item):
    # iterator object must be explicitly declared for the next() method
    iterator = iter(xs)

    # once the in operator is called, the next function would return the next
    # item in iterator
    return next(iterator, None) if item in iterator else None
