// Unfinished Loop - Bug Fixing #1
// Oh no, Timmy's created an infinite loop! Help Timmy find and fix the bug in
// his unfinished for loop!

#include <vector>

std::vector<int> createVector(const int n)
{
    std::vector<int> res;

    for (int i = 1; i <= n; ++i)
    {
        res.push_back(i);
    }

    return res;
}
