// This method, which is supposed to return the result of dividing its first
// argument by its second, isn't always returning correct values. Fix it.

float divide_nums(int x, int y)
{
    return (y != 0) ? (float)(x) / (float)(y) : 0.0;
}
