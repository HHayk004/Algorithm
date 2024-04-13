#include <iostream>
#include <chrono>
#include <thread>
#include "InsertionSort.cpp"
#include "MergeSort.cpp"

std::ostream& operator<<(std::ostream& os, std::vector<double>& vec)
{
    for (double& elem : vec)
    {
        std::cout << elem << ' ';
    }
    std::cout << std::endl;

    return os;
}

int main()
{
    std::vector<double> vec{};
    
    using DurationType = std::chrono::nanoseconds;

    DurationType insertion_duration;
    DurationType merge_duration;
    int number = 0;
    do
    {
        vec.insert(vec.begin(), number);
        ++number;
        std::vector<double> tmp_vec = vec;

        auto start = std::chrono::steady_clock::now();
        insertionSort(tmp_vec);
        auto end = std::chrono::steady_clock::now();
        insertion_duration = std::chrono::duration_cast<DurationType>(end - start);

        std::cout << insertion_duration.count() << ' ';

        tmp_vec = vec;
        start = std::chrono::steady_clock::now();
        mergeSort(tmp_vec);
        end = std::chrono::steady_clock::now();
        merge_duration = std::chrono::duration_cast<DurationType>(end - start);

        std::cout << merge_duration.count() << '\n';
    } while (merge_duration > insertion_duration);

    std::cout << vec.size() << std::endl;

    return 0;
}