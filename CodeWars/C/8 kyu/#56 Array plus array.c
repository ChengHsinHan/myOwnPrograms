// I'm new to coding and now I want to get the sum of two arrays...actually the
// sum of all their elements. I'll appreciate for your help.
//
// P.S. Each array includes only integer numbers. Output is a number too.

#include <stddef.h>

long arr_plus_arr(const int* a, const int* b, size_t na, size_t nb)
{
    long sum = 0;

    for (size_t index_a = 0; index_a < na; ++index_a)
        sum += a[index_a];
    for (size_t index_b = 0; index_b < nb; ++index_b)
        sum += b[index_b];

    return sum;
}
