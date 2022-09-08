// Write an algorithm that will identify valid IPv4 addresses in dot-decimal
// format. IPs should be considered valid if they consist of four octets, with
// values between 0 and 255, inclusive.
//
// Valid inputs examples:
// Examples of valid inputs:
// 1.2.3.4
// 123.45.67.89
// Invalid input examples:
// 1.2.3
// 1.2.3.4.5
// 123.456.78.90
// 123.045.067.089
// Notes:
// Leading zeros (e.g. 01.02.03.04) are considered invalid
// Inputs are guaranteed to be a single string

#include <stdio.h>
#include <string.h>

/* Return 1 if addr is a valid IP address, return 0 otherwise */
int is_valid_ip(const char* addr)
{
    unsigned char first;
    unsigned char second;
    unsigned char third;
    unsigned char fourth;

    // copy the four valid numbers from addr into first, second, third and fourth
    // since they are all unsigned chars, whose range is from 0 to 255
    // bigger numbers will always overflow
    sscanf(addr, "%hhu.%hhu.%hhu.%hhu", &first, &second, &third, &fourth);

    // put these four numbers back in the same format as addr and store as transform
    // here we hard-coded its length as 16 because we expect the longest input
    // contains four 3-digit numbers and three dots, which has total length of
    // 4 * 3 + 3 = 15, we add one here for the terminating '\0'
    // for inputs that have more numbers than four, the redundant numbers would be
    // trancated, and those that have less than four numbers would be padded by zeros
    char transform[16];
    snprintf(transform, sizeof(transform), "%hhu.%hhu.%hhu.%hhu", first, second, third, fourth);

    // if the original addr contains non-digit inputs or out-of-range numbers,
    // string transform would be different from addr
    return (strcmp(addr, transform) == 0);
}
