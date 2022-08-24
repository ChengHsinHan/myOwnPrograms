// Task Overview
// Given a non-negative integer n, write a function to_binary/ToBinary which
// returns that number in a binary format.
//
// Example:
//
// to_binary(1)  /* should return 1 */
// to_binary(5)  /* should return 101 */
// to_binary(11) /* should return 1011 */

unsigned long long to_binary(unsigned short num)
{
    unsigned long long binary = 0;
    for (unsigned long long bit = 1; num != 0; bit *= 10, num >>= 1)
        if (num & 1)
            binary += bit;
    return binary;
}
