// Given a non-empty array of integers, return the result of multiplying the
// values together in order. Example:
//
// [1, 2, 3, 4] => 1 * 2 * 3 * 4 = 24

#include <vector>
int grow(std::vector<int> nums)
{
    int result = 1;
    for (const auto num : nums)
        result *= num;
    return result;
}
