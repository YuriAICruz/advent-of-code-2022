#pragma once

#include "IProgram.h"

template <int size>
class ProgramsCollection
{
public:
    explicit ProgramsCollection(IProgram* programs[size]);
    int getSize();
    std::string OptionValues();

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

template <int size>
std::string ProgramsCollection<size>::OptionValues()
{
    std::string values;

    for (int i = 0; i < size; ++i)
    {
        if (i > 0)
        {
            values += "\n";
        }

        values += std::to_string(i + 1);
        values += " - ";
        values += Programs[i]->GetDescription();
    }

    return values;
}
