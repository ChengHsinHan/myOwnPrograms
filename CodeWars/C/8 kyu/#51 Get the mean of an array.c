// It's the academic year's end, fateful moment of your school report. The
// averages must be calculated. All the students come to you and entreat you to
// calculate their average for them. Easy ! You just need to write a script.
//
// Return the average of the given array rounded down to its nearest integer.
//
// The array will never be empty.

#include <stddef.h>

int get_average(const int* marks, size_t count)
{
    int sum = 0;
    for (size_t index = 0; index < count; ++index)
        sum += marks[index];
    return sum / count;
}
