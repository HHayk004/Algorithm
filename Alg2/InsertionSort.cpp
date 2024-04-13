#include <vector>
void insertionSort (std::vector<double>& vec)
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
    }
}