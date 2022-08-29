// our goal is to return multiplication table for number that is always an
// integer from 1 to 10.
//
// For example, a multiplication table (string) for number == 5 looks like
// below:
//
// 1 * 5 = 5
// 2 * 5 = 10
// 3 * 5 = 15
// 4 * 5 = 20
// 5 * 5 = 25
// 6 * 5 = 30
// 7 * 5 = 35
// 8 * 5 = 40
// 9 * 5 = 45
// 10 * 5 = 50
// P. S. You can use \n in string to jump to the next line.
//
// Note: newlines should be added between rows, but there should be no trailing
// newline at the end. If you're unsure about the format, look at the sample
// tests.

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int getDigits(int number)
{
    int digits = 0;
    do
    {
        ++digits;
        number /= 10;
    }
    while (number);
    return digits;
}

char* multi_table(int num)
{
    // there are total 81 fixed characters (including '\n' and '\0')
    // for a certain num, there is at most one carry starting from the second line
    // so from that line on, there are at most 3 * digits of num, ending up having
    // at most 29 * digits of num in length
    char* table = (char*) calloc(81 + 29 * getDigits(num), sizeof(char));
    int currentIndex = 0;
    for (int count = 1; count < 10; ++count)
        currentIndex += sprintf(table + currentIndex, "%d * %d = %d\n", count, num, count * num);
    sprintf(table + currentIndex, "%d * %d = %d", 10, num, 10 * num);
    return table;
}
