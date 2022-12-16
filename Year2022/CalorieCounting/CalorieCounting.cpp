#include "CalorieCounting.h"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Elf.h"
#include "../VectorOperations.h"

void CalorieCounting::Execute()
{
    std::cout << "Please input all lines of calories ($ to end)";
    std::string line;

    _elfs.clear();

    Elf* _currentElf = nullptr;

    while (std::getline(std::cin, line))
    {
        if (line.empty() || _currentElf == nullptr)
        {
            _currentElf = new Elf();
            _elfs.push_back(_currentElf);
            continue;
        }
        if(line == "$")
        {
            break;
        }

        std::stringstream stream;
        stream << line;

        int calories;
        stream >> calories;
        _currentElf->addCalorie(calories);
        _rawData.push_back(line);
    }

    auto max = GetMax();
    std::cout << "max: ";
    std::cout << max << std::endl;
}

int CalorieCounting::GetMax()
{
    int max = -1;
    int index = 0;
    int maxIndex = 0;
    for (auto elf : _elfs)
    {
        int sum = VectorOperations::Sum(elf->calories);

        if(sum > max)
        {
            maxIndex = index;
            max = sum;
        }

        index++;
    }

    std::cout << "max index ";
    std::cout << maxIndex << std::endl;
    return max;
}
