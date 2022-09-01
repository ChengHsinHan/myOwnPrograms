// Write a function which calculates the average of the numbers in a given list.
//
// Note: Empty arrays should return 0.

double find_average(double* array, int length)
{
    double sum = 0.0;
    for (int index = 0; index < length; ++index)
        sum += array[index];

    return (length != 0) ? (sum / (double)length) : 0.0;
}
