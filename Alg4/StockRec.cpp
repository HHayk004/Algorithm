#include <iostream>
#include <vector>

void stockMerge(const std::vector<int>& vec, int start, int mid, int end, int& answer_start, int& answer_end)
{
    int min = start;
    for (int i = start + 1; i <= mid; ++i)
    {
        if (vec[i] < vec[min])
        {
            min = i;
        }
    }

    int max = mid + 1;
    for (int i = mid + 2; i <= end; ++i)
    {
        if (vec[i] > vec[max])
        {
            max = i;
        }
    }

    if (vec[max] - vec[min] > vec[answer_start] - vec[answer_end])
    {
        answer_start = min;
        answer_end = max;
    }
}

void stockRec(const std::vector<int>& vec, int start, int end, int& answer_start, int& answer_end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        stockRec(vec, start, mid, answer_start, answer_end);
        stockRec(vec, mid + 1, end, answer_start, answer_end);
        stockMerge(vec, start, mid, end, answer_start, answer_end);
    }
}

void stock(const std::vector<int>& vec, int& answer_start, int& answer_end)
{
    stockRec(vec, 0, vec.size() - 1, answer_start, answer_end);
}

int main()
{
    std::vector<int> vec = {2, 3, 1, 5, 2, 7};
    int start = 0;
    int end = 0;
    stock(vec, start, end);

    std::cout << start << ' ' << end << ' ' << vec[end] - vec[start] << std::endl;

    return 0;
}