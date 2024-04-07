#include <iostream>
#include <vector>

void insertionSort (std::vector<int>& vec)
{
    int n = vec.size();
    for (int i = 1; i < n; ++i) // n - 1
    {
        int key = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > key) // i - 1
        {
            vec[j + 1] = vec[j];
            --j;
        }
        vec[j + 1] = key;   
    } // total n * (n - 1) / 2;
}

int binarySearchRecursive(const std::vector<int>& vec, int target, int start, int end)
{
    if (start <= end)
    {
        int mid = (start + end) / 2;
        if (vec[mid] > target)
        {
            return binarySearchRecursive(vec, target, start, mid - 1);
        }

        else if (vec[mid] < target)
        {
            return binarySearchRecursive(vec, target, mid + 1, end);
        }

        else
        {
            return mid;
        }
    }

    return -1;
}

int binarySearch (const std::vector<int>& vec, int target)
{
    int start = 0;
    int end = vec.size() - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (vec[mid] > target)
        {
            end = mid - 1;
        }

        else if (vec[mid] < target)
        {
            start = mid + 1;
        }

        else
        {
            return mid;
        }
    }

    return -1;
}

int main()
{
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7};

    std::cout << binarySearchRecursive(vec, 7, 0, vec.size() - 1) << std::endl;

//    insertionSort(vec);

/*
    for (int i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
*/
    return 0;
}
