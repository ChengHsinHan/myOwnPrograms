# Create a method partition that accepts a list and a method/block. It should
# return two arrays: the first, with all the elements for which the given block
# returned true, and the second for the remaining elements.
#
# Here's a simple Ruby example:
#
# animals = ["cat", "dog", "duck", "cow", "donkey"]
# partition(animals){|animal| animal.size == 3}
#     #=> [["cat", "dog", "cow"], ["duck", "donkey"]]
# The equivalent in Python would be:
#
# animals = ['cat', 'dog', 'duck', 'cow', 'donkey']
# partition(animals, lambda x: len(x) == 3)
#     # (['cat', 'dog', 'cow'], ['duck', 'donkey'])
# If you need help, here's a reference:
#
# http://www.rubycuts.com/enum-partition

def partition(arr, classifier_method):
    true_list, false_list = [], []
    for element in arr:
        (true_list if classifier_method(element) else false_list).append(element)
    return (true_list, false_list)
