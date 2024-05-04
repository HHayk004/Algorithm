#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

int partitioningEnd(std::vector<int>& vec, int start, int end)
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

int partitioningStart(std::vector<int>& vec, int start, int end)
{
    std::swap(vec[start], vec[end]);

    return partitioningEnd(vec, start, end);
}

int partitioning3Median(std::vector<int>& vec, int start, int end)
{
    int mid = (start + end) / 2;
    if (vec[start] > vec[mid])
    {
        std::swap(vec[start], vec[mid]);
    }

    if (vec[mid] > vec[end])
    {
        std::swap(vec[mid], vec[end]);
    }

    if (vec[start] > vec[mid])
    {
        std::swap(vec[start], vec[mid]);
    }

    return partitioningEnd(vec, start + 1, end);
}

int randomNumberGenerator(int start, int end)
{
    return rand() % (end - start + 1) + start;
}

int partitioningRandom(std::vector<int>& vec, int start, int end)
{
    int random_pivot = randomNumberGenerator(start, end);
    if (random_pivot != end)
    {
        std::swap(vec[random_pivot], vec[end]);
    }

    return partitioningEnd(vec, start, end);
}

void quickSortHelper(std::vector<int>& vec, int start, int end)
{
    if (start < end)
    {
        //int i = partitioningStart(vec, start, end);
        //int i = partitioningEnd(vec, start, end);
        //int i = partitioning3Median(vec, start, end);
        int i = partitioningRandom(vec, start, end);
        
        quickSortHelper(vec, start, i - 1);
        quickSortHelper(vec, i + 1, end);
    }
}

void quickSort(std::vector<int>& vec)
{
    srand(time(nullptr));
    quickSortHelper(vec, 0, vec.size() - 1);
}

int main()
{
    std::vector<int> vec = {1, 1, 9, 9, 0, 0, 2, 1, 3, 0, 9, 8, 1};
    quickSort(vec);

    for (int elem : vec)
    {
        std::cout << elem << ' ';
    }
    std::cout << std::endl;

    return 0;
}