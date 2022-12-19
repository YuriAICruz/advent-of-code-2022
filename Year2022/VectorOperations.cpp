#include "VectorOperations.h"

int VectorOperations::Sum(std::vector<int> vector)
{
    int sum = 0;
    for (auto element : vector)
    {
        sum += element;
    }

    return sum;
}

