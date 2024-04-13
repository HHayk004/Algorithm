#include <vector>
#include <limits>

void merge(std::vector<double>& vec, int start, int mid, int end)
{
    std::vector<double> left(vec.begin() + start, vec.begin() + mid + 1);
    left.push_back(std::numeric_limits<double>::infinity());

    std::vector<double> right(vec.begin() + mid + 1, vec.begin() + end + 1);
    right.push_back(std::numeric_limits<double>::infinity());

    int i = 0;
    int j = 0;
    for (int k = start; k <= end; ++k)
    {
        if (left[i] < right[j])
        {
            vec[k] = left[i];
            ++i;
        }

        else
        {
            vec[k] = right[j];
            ++j;
        }
    }
}

void MergeSortRec(std::vector<double>& vec, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        MergeSortRec(vec, start, mid);
        MergeSortRec(vec, mid + 1, end);
        merge(vec, start, mid, end);
    }
}

void mergeSort(std::vector<double>& vec)
{
    MergeSortRec(vec, 0, vec.size() - 1);
}