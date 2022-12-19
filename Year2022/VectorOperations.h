#pragma once
#include <vector>

class VectorOperations
{
public:
    template<typename T>
    static int Sum(std::vector<T> vector, int(T a));
    static int Sum(std::vector<int> vector);
};

template <typename T>
int VectorOperations::Sum(std::vector<T> vector, int(* function)(T a))
{
    int sum = 0;
    for (auto element : vector)
    {
        sum += function(element);
    }

    return sum;
}