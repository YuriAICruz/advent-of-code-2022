#pragma once

#include "IProgram.h"

template<int size>
class ProgramsCollection
{
public:
    explicit ProgramsCollection(IProgram* programs[size]);
    int getSize();

    IProgram* Programs[size]{};

private:
};

template <int size>
ProgramsCollection<size>::ProgramsCollection(IProgram* programs[size])
{
    for (int i = 0; i < size; ++i)
    {
        Programs[i] = programs[i];
    }
}

template <int size>
int ProgramsCollection<size>::getSize()
{
    return size;
}

