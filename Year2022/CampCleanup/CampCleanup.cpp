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

    int overlapSum = 0;
    for (WorkersGroup* pair : pairs)
    {
        if (pair->FullyOverlap())
        {
            overlapSum++;
        }
    }

    std::cout << "Full Overlap pairs sum:" << std::endl;
    std::cout << overlapSum << std::endl;
}

std::string CampCleanup::GetDescription()
{
    return "Camp Cleanup Algorithm";
}
