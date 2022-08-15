// Task:
// Your task is to write a function which returns the sum of following series
// upto nth term(parameter).
//
// Series: 1 + 1/4 + 1/7 + 1/10 + 1/13 + 1/16 +...
// Rules:
// You need to round the answer to 2 decimal places and return it as String.
//
// If the given value is 0 then it should return 0.00
//
// You will only be given Natural Numbers as arguments.
//
// Examples:(Input --> Output)
// 1 --> 1 --> "1.00"
// 2 --> 1 + 1/4 --> "1.25"
// 5 --> 1 + 1/4 + 1/7 + 1/10 + 1/13 --> "1.57"

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

char* series_sum(const size_t n)
{
    double sum = 0.0;

    // the series 1/(3n-2) diverges, but even with the largest size_t input (2**64)
    // would only yields a value less than 16
    // Thus, we declare the string as length 6, 2 for the integer part, 2 for the floating points,
    // 1 for the decimal point, and the last one for the terminating '\0'
    char* string_sum = (char*) calloc(6, sizeof(char));

    for (size_t index = 1; index <= n; ++index)
        sum += 1.0 / (3 * index - 2);

    sprintf(string_sum, "%.2f", sum);
    return string_sum;
}
