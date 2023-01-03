#include "CampCleanup.h"

#include <iostream>

#include "WorkersGroup.h"

void CampCleanup::Execute()
{
    std::cout << "Enter pair intervals ($ to end)" << std::endl;

    std::vector<WorkersGroup*> pairs;
    std::string line;

    while (std::getline(std::cin, line))
    {
        if (line.empty())
        {
            continue;
        }

        if (line == "$")
        {
            break;
        }

        auto pair = new WorkersGroup(line);
        pairs.push_back(pair);
    }

    int fullOverlapSum = 0;
    int overlapSum = 0;
    for (WorkersGroup* pair : pairs)
    {
        if (pair->FullyOverlap())
        {
            fullOverlapSum++;
        }

        if (pair->Overlap())
        {
            overlapSum++;
        }
    }

    std::cout << "Full Overlap pairs sum:" << std::endl;
    std::cout << fullOverlapSum << std::endl;
    std::cout << "Overlap pairs sum:" << std::endl;
    std::cout << overlapSum << std::endl;
}

std::string CampCleanup::GetDescription()
{
    return "Camp Cleanup Algorithm";
}
