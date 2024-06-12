#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <climits>

std::ostream& operator<<(std::ostream& os, const std::vector<int>& vec);

std::tuple<int, int> getMinMax(const std::vector<int>& vec);

void bucketSort(std::vector<int>& vec);

int main()
{
    std::vector<int> vec = {1, 2, 1, 2, 2, 1, 2, 1, 2};

    bucketSort(vec);

    std::cout << vec << std::endl;

    return 0;
}

std::ostream& operator<<(std::ostream& os, const std::vector<int>& vec)
{
    for (int elem : vec)
    {
        os << elem << ' ';
    }

    return os;
}

std::tuple<int, int> getMinMax(const std::vector<int>& vec)
{
    std::tuple<int, int> min_max{INT_MAX, INT_MIN};

    for (int elem : vec)
    {
        if (elem < std::get<0>(min_max))
        {
            std::get<0>(min_max) = elem;
        }

        else if (elem > std::get<1>(min_max))
        {
            std::get<1>(min_max) = elem;
        }
    }

    return min_max;
}

void bucketSort(std::vector<int>& vec)
{
    std::tuple<int, int> min_max = getMinMax(vec);

    int delta = std::get<1>(min_max) - std::get<0>(min_max);
    int bucket_count = vec.size();

    int interval = delta / bucket_count + 1;

    std::vector<std::vector<int>> buckets(bucket_count, std::vector<int>());
    for (int elem : vec)
    {
        buckets[(elem - std::get<0>(min_max)) / interval].push_back(elem);
    }

    int index = 0;
    for (auto bucket : buckets)
    {
        std::sort(bucket.begin(), bucket.end());
        for (int elem : bucket)
        {
            vec[index] = elem;
            ++index;
        }
    }
}