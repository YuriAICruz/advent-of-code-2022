#pragma once
#include <vector>

class VectorOperations
{
public:
    template<typename T>
    static int Sum(std::vector<T> vector, int(T::* function)(T* a));
    static int Sum(std::vector<int> vector);
};
