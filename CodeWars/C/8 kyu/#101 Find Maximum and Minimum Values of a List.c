// Your task is to make two functions ( max and min, or maximum and minimum,
// etc., depending on the language ) that receive a list of integers as input,
// and return the largest and lowest number in that list, respectively.
//
// Examples (Input -> Output)
// * [4,6,2,1,9,63,-134,566]         -> max = 566, min = -134
// * [-52, 56, 30, 29, -54, 0, -110] -> min = -110, max = 56
// * [42, 54, 65, 87, 0]             -> min = 0, max = 87
// * [5]                             -> min = 5, max = 5
// Notes
// You may consider that there will not be any empty arrays/vectors.

int min(int* array, int arrayLength)
{
    int minimum = array[0];
    for (int index = 1; index < arrayLength; ++index)
        if (array[index] < minimum)
            minimum = array[index];
    return minimum;
}

int max(int* array, int arrayLength)
{
    int maximum = array[0];
    for (int index = 1; index < arrayLength; ++index)
        if (array[index] > maximum)
            maximum = array[index];
    return maximum;
}
