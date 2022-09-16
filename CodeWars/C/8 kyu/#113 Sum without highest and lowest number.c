// Task
// Sum all the numbers of a given array ( cq. list ), except the highest and the
// lowest element ( by value, not by index! ).
//
// The highest or lowest element respectively is a single element at each edge,
// even if there are more than one with the same value.
//
// Mind the input validation.
//
// Example
// { 6, 2, 1, 8, 10 } => 16
// { 1, 1, 11, 2, 3 } => 6
// Input validation
// If an empty value ( null, None, Nothing etc. ) is given instead of an array,
// or the given array is an empty list or a list with only 1 element, return 0.

int sum(int* numbers, int numbersCount)
{
    // early termination for small-size array. sum of array with size 2 is doomed to be 0
    if (numbersCount <= 2)
        return 0;

    int max = numbers[0];
    int min = numbers[0];
    int sum = 0;
    for (int index = 0; index < numbersCount; ++index)
    {
        if (numbers[index] > max)
            max = numbers[index];
        if (numbers[index] < min)
            min = numbers[index];

        sum += numbers[index];
    }
    return (sum - max - min);
}
