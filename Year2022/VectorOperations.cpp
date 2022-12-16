#include "VectorOperations.h"

template <typename T>
int VectorOperations::Sum(std::vector<T> vector, int(T::* function)(T* a))
{
    int sum = 0;
    for (auto element : vector)
    {
        sum += function(element);
    }

    return sum;
}

int VectorOperations::Sum(std::vector<int> vector)
{
    int sum = 0;
    for (auto element : vector)
    {
        sum += element;
    }

    return sum;
}
