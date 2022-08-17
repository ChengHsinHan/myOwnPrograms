// Write a function revR which reverses a given list. Try not to cheat and
// provide a recursive solution.

int* revR(int* array, int n)
{
    if (n == 0)
        return array;

    for (int index = 0; index < n - 1; ++index)
    {
        int temp = array[index];
        array[index] = array[index + 1];
        array[index + 1] = temp;
    }
    return revR(array, n - 1);
}
