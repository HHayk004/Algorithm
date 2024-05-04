#include <iostream>
#include <vector>

int deltaMaxMin(const std::vector<int>& vec, int& min)
{
    int max = vec[0];
    for (int i = 0; i < vec.size(); ++i)
    {
        if (vec[i] < min)
        {
            min = vec[i];
        }

        else if (vec[i] > max)
        {
            max = vec[i];
        }
    }

    return max - min + 1;
}

void countingSortStandart(std::vector<int>& vec)
{
    if (vec.empty())
    {
        return;
    }

    int min = vec[0];
    std::vector<int> count(deltaMaxMin(vec, min));
    for (int elem : vec)
    {
        ++count[elem - min];
    }

    int index = 0;
    for (int i = 0; i < count.size(); ++i)
    {
        for (int j = 0; j < count[i]; ++j)
        {
            vec[index] = i;
            ++index;
        }
    }
}

void countingSortUpgrade(std::vector<int>& vec)
{
    if (vec.empty())
    {
        return;
    }

    int min = vec[0];
    std::vector<int> count(deltaMaxMin(vec, min));
    for (int elem : vec)
    {
        ++count[elem - min];
    }
    
    for (int i = 1; i < count.size(); ++i)
    {
        count[i] += count[i - 1];
    }

    std::vector<int> tmp_answer(vec.size());

    for (int elem : vec)
    {
        tmp_answer[count[elem - min] - 1] = elem;
        --count[elem - min];
    }

    vec = std::move(tmp_answer);
}

int main()
{
    std::vector<int> vec = {1, 9, 1, 9, 0, 0, 2, 1, 3, 0, 9, 8, 1};

    countingSortUpgrade(vec);

    for (int elem : vec)
    {
        std::cout << elem << ' ';
    }
    std::cout << std::endl;

    return 0;
}