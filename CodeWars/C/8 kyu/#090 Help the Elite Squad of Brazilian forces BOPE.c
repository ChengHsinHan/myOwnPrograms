// The BOPE is the squad of special forces of police that usually handles the
// operations in the Favelas in Rio de Janeiro.
//
// In this Kata you have to write a function that determine the number of
// magazines that every soldier has to have in his bag.
//
// You will receive the weapon and the number of streets that they have to
// cross. Considering that every street the officer shoots 3 times. Bellow there
// is the relation of weapons:
//
// PT92 - 17 bullets
// M4A1 - 30 bullets
// M16A2 - 30 bullets
// PSG1 - 5 bullets
//
// Example:
//
// ["PT92", 6] => 2 (6 streets 3 bullets each)
// ["M4A1", 6] => 1
//
// The return Will always be an integer so as the params.
//
// NOTE: In C the weapon and number of streets are passed in as two separate
// arguments (the first one a string, the second an integer) instead of a single
// array.

#include <stddef.h>
#include <string.h>

size_t mag_number(const char* weapon_name, size_t streets)
{
    if (strcmp(weapon_name, "PT92") == 0)
        return (streets * 3 - 1) / 17 + 1;
    else if ((strcmp(weapon_name, "M4A1") == 0) || (strcmp(weapon_name, "M16A2") == 0))
        return (streets * 3 - 1) / 30 + 1;
    else if (strcmp(weapon_name, "PSG1") == 0)
        return (streets * 3 - 1) / 5 + 1;
}
