# In JavaScript, if..else is the most basic condition statement, it consists of
# three parts:condition, statement1, statement2, like this:
#
# if condition: statementa
# else:         statementb
# It means that if the condition is true, then execute the statementa, otherwise
# execute the statementb.If the statementa or statementb more than one line, you
# need to add { and } at the head and tail of statement in JS, to keep the same
# indentation on Python and to put a end in Ruby where it indeed ends.
#
# An example, if we want to judge whether a number is odd or even, we can write
# code like this:
#
# def odd_even(n):
#     if n%2: return "odd number"
#     else:   return "even number"
# If there is more than one condition to judge, we can use the compound
# if...else statement. an example:
#
# def old_young(age):
#     if age<16:        return "children"
#     elif (age<50): return "young man" #use "else if" if needed
#     else:             return "old man"
# This function returns a different value depending on the parameter age.
#
# Looks very complicated? Well, JS and Ruby also support the ternary operator
# and Python has something similar too:
#
# statementa if condition else statementb
# Condition and statement separated by "?", different statement separated by ":"
# in both Ruby and JS; in Python you put the condition in the middle of two
# alternatives. The two examples above can be simplified with ternary operator:
#
# def odd_even(n):
#     return "odd number" if n%2 else "even number"
# def old_young(age):
#     return "children" if age<16 else "young man" if age<50 else "old man"
# Task:
# Complete function saleHotdogs/SaleHotDogs/sale_hotdogs, function accept 1
# parameters:n, n is the number of customers to buy hotdogs, different numbers
# have different prices (refer to the following table), return a number that the
# customer need to pay how much money.
#
# numbers               price (cents)
# n < 5                     100
# n >= 5 and n < 10          95
# n >= 10                    90
# You can use if..else or ternary operator to complete it.
#
# When you have finished the work, click "Run Tests" to see if your code is
# working properly.
#
# In the end, click "Submit" to submit your code pass this kata.
# Series:
# ( ↑↑↑ Click the link above can get my newest kata list, Please add it to your
# favorites)
#
# #1: create your first JS function helloWorld
# #2: Basic data types--Number
# #3: Basic data types--String
# #4: Basic data types--Array
# #5: Basic data types--Object
# #6: Basic data types--Boolean and conditional statements if..else
# #7: if..else and ternary operator
# #8: Conditional statement--switch
# #9: loop statement --while and do..while
# #10: loop statement --for
# #11: loop statement --break,continue
# #12: loop statement --for..in and for..of
# #13: Number object and its properties
# #14: Methods of Number object--toString() and toLocaleString()
# #15: Methods of Number object--toFixed(), toExponential() and toPrecision()
# #16: Methods of String object--slice(), substring() and substr()
# #17: Methods of String object--indexOf(), lastIndexOf() and search()
# #18: Methods of String object--concat() split() and its good friend join()
# #19: Methods of String object--toUpperCase() toLowerCase() and replace()
# #20: Methods of String object--charAt() charCodeAt() and fromCharCode()
# #21: Methods of String object--trim() and the string template
# #22: Unlock new skills--Arrow function,spread operator and deconstruction
# #23: methods of arrayObject---push(), pop(), shift() and unshift()
# #24: methods of arrayObject---splice() and slice()
# #25: methods of arrayObject---reverse() and sort()
# #26: methods of arrayObject---map()
# #27: methods of arrayObject---filter()
# #28: methods of arrayObject---every() and some()
# #29: methods of arrayObject---concat() and join()
# #30: methods of arrayObject---reduce() and reduceRight()
# #31: methods of arrayObject---isArray() indexOf() and toString()
# #32: methods of Math---round() ceil() and floor()
# #33: methods of Math---max() min() and abs()
# #34: methods of Math---pow() sqrt() and cbrt()
# #35: methods of Math---log() and its family
# #36: methods of Math---kata author's lover:random()
# #37: Unlock new weapon---RegExp Object
# #38: Regular Expression--"^","$", "." and test()
# #39: Regular Expression--"?", "*", "+" and "{}"
# #40: Regular Expression--"|", "[]" and "()"
# #41: Regular Expression--""
# #42: Regular Expression--(?:), (?=) and (?!)

def sale_hotdogs(n):
    if n < 5:
        return n * 100
    elif n >= 5 and n < 10:
        return n * 95
    else:
        return n * 90
