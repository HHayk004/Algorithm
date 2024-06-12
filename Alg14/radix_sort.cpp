#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

std::ostream& operator<<(std::ostream& os, const std::vector<int>& vec);

int getMax(const std::vector<int>& vec);
void radixSort(std::vector<int>& vec);

int main()
{
    std::vector<int> vec = {2, 534, 5, 1, 24, 3, 3, 8, 10, 123, 12, 30};

    radixSort(vec);

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

int getMax(const std::vector<int>& vec)
{
    int max = INT_MIN;

    for (int elem : vec)
    {
        if (elem > max)
        {
            max = elem;
        }
    }

    return max;
}

void radixSort(std::vector<int>& vec)
{
    int max = getMax(vec);

    int exp = 1;
    for (; max / exp > 0; exp *= 10);

    int index = vec.size();
    for (; exp; exp /= 10)
    {
        int new_index = index;
        for (int i = new_index - 1; i >= 0; --i)
        {
            if (vec[i] / exp)
            {
                --new_index;
                std::swap(vec[i], vec[new_index]);
            }
        }

        std::sort(vec.begin() + new_index, vec.begin() + index);
        
        index = new_index;
    }
}