#pragma once
#include <vector>

#include "PriorityData.h"
#include "Rucksack.h"
#include "../IProgram.h"

class RucksackReorganization : public IProgram
{
public:
    void Execute() override;
    std::string GetDescription() override;
private:
    int GetPriorityValue(char* c);
    void PopulatePriorityData(bool useDefault = true);
    char FindBadge(int size, Rucksack* list);
    std::vector<Rucksack*> _sacks;
    std::vector<PriorityData*> _priorityData;
    
};
