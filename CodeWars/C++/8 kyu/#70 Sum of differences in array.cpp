// Your task is to sum the differences between consecutive pairs in the array in
// descending order.
//
// Example
// [2, 1, 10]  -->  9
// In descending order: [10, 2, 1]
//
// Sum: (10 - 2) + (2 - 1) = 8 + 1 = 9
//
// If the array is empty or the array has only one element the result should be
// 0 (Nothing in Haskell, None in Rust).

#include <vector>
int sumOfDifferences(const std::vector<int>& arr)
{
    // early termination for empty array
    if (arr.empty())
        return 0;

    int max = arr[0];
    int min = arr[0];

    for (const auto number : arr)
    {
        if (number > max)
            max = number;

        if (number < min)
            min = number;
    }
    return (max - min);
}
