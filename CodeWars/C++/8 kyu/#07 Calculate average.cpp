// Write a function which calculates the average of the numbers in a given list.
//
// Note: Empty arrays should return 0.

#include <vector>
#include <numeric>

double calcAverage(const std::vector<int>& values)
{
    return static_cast<double>(std::accumulate(values.begin(), values.end(), 0)) / static_cast<double>(values.size());
}
