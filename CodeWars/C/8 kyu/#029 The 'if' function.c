// Create a function called _if which takes 3 arguments: a boolean value bool
// and 2 functions (which do not take any parameters): func1 and func2
//
// When bool is truth-ish, func1 should be called, otherwise call the func2.
//
// Example:
// void the_true() { printf("true"); }
// void the_false() { printf("false"); }
// _if(true, the_true, the_false);
// /* Logs "true" to the console */

#include <stdbool.h>

void _if(bool value, void (*func1)(), void (*func2)())
{
    (value) ? func1() : func2();
}
