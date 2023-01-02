#include "RucksackReorganization.h"

#include <fstream>
#include <nlohmann/json.hpp>
#include <iostream>
#include <vector>

#include "Rucksack.h"

void RucksackReorganization::Execute()
{
    PopulatePriorityData();

    _sacks.clear();

    std::string line;
    std::cout << "Rucksack Reorganization, enter data: (to end use $)" << std::endl;
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

        auto sack = new Rucksack(&line);
        _sacks.push_back(sack);
    }

    int sum = 0;
    for (auto rucksack : _sacks)
    {
        auto c = rucksack->GetCommonItem();
        const int value = GetPriorityValue(&c);
        
        std::cout << "Same value found: '";
        std::cout << c;
        std::cout << "' priority: ";
        std::cout << value <<std::endl;
        sum = sum + value;
    }

    std::cout << "Total Sum: ";
    std::cout << sum <<std::endl;
}

std::string RucksackReorganization::GetDescription()
{
    return "Rucksack Reorganization Algorithm";
}

int RucksackReorganization::GetPriorityValue(char* c)
{
    for (int i = 0, n = _priorityData.size(); i < n; ++i)
    {
        if (_priorityData[i]->Key == *c)
        {
            return _priorityData[i]->Value;
        }
    }
    return 0;
}

void RucksackReorganization::PopulatePriorityData()
{
    _priorityData.clear();

    std::string filePath;
        std::cout << "Enter priority file path"<<std::endl;
    std::cin >> filePath;
    std::ifstream f(filePath);
    if(f.fail() || f.bad())
    {
        std::cout << "No File Found in";
        std::cout << filePath << std::endl;
        return;
    }
    nlohmann::json data = nlohmann::json::parse(f);

    for (auto jsonData : data)
    {
        std::string key = jsonData["key"];
        auto pData = new PriorityData(key[0], jsonData["value"]);
        _priorityData.push_back(pData);
    }
}
