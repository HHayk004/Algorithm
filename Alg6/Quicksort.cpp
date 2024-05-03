#include <iostream>
#include <vector>

int partitioning(std::vector<int>& vec, int start, int end)
{
    int j = start - 1;
    for (int i = start; i <= end; ++i)
    {
        if (vec[i] <= vec[end])
        {
            ++j;
            std::swap(vec[i], vec[j]);
        }
    }

    return j;
}

void quickSortHelper(std::vector<int>& vec, int start, int end)
{
    if (start < end)
    {
        int i = partitioning(vec, start, end);
        quickSortHelper(vec, start, i - 1);
        quickSortHelper(vec, i + 1, end);
    }
}

void quickSort(std::vector<int>& vec)
{
    quickSortHelper(vec, 0, vec.size() - 1);
}

int main()
{
    std::vector<int> vec = {2, 1, 3, 0, 9, 8};
    quickSort(vec);

    for (int elem : vec)
    {
        std::cout << elem << ' ';
    }
    std::cout << std::endl;
}