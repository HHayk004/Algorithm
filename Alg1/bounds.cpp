#include <iostream>
#include <vector>
#include <utility>

int upper_bound(const std::vector<int>& vec, int target);
int lower_bound(const std::vector<int>& vec, int target);
std::pair<int, int> equal_range(const std::vector<int>& vec, int target);

int main()
{
    std::vector<int> vec = {1, 1, 1, 2, 3, 4, 6, 7, 8, 8, 8, 8, 9};

    std::pair<int, int> range = equal_range(vec, 8);

    std::cout << range.first << ' ' << range.second << std::endl;

    return 0;
}

int upper_bound(const std::vector<int>& vec, int target)
{
    int start = 0;
    int end = vec.size() - 1;
    while (start < end)
    {
        int mid = (start + end + 1) / 2;
        if (vec[mid] <= target)
        {
            start = mid + 1;
        }

        else
        {
            end = mid - 1;
        }
    }

    return start;
}

int lower_bound(const std::vector<int>& vec, int target)
{
    int start = 0;
    int end = vec.size() - 1;
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (vec[mid] < target)
        {
            start = mid + 1;
        }

        else
        {
            end = mid - 1;
        }
    }

    return start;
}

std::pair<int, int> equal_range(const std::vector<int>& vec, int target)
{
    return {lower_bound(vec, target), upper_bound(vec, target)};
}