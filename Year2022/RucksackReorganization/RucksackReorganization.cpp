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
        std::cout << value << std::endl;
        sum = sum + value;
    }

    std::cout << "Total Sum: ";
    std::cout << sum << std::endl;
    std::cout << std::endl;

    sum = 0;
    for (int i = 0, n = _sacks.size(); i < n; i += 3)
    {
        if (n < i + 1 || n < i + 2)
        {
            std::cout << "index out of range" << std::endl;
            continue;
        }

        Rucksack arr[3] =
        {
            *_sacks[i],
            *_sacks[i + 1],
            *_sacks[i + 2]
        };
        auto c = FindBadge(3, arr);
        const int value = GetPriorityValue(&c);

        std::cout << "Badge value found: '";
        std::cout << c;
        std::cout << "' priority: ";
        std::cout << value << std::endl;
        sum = sum + value;
    }

    std::cout << "Total Badges Sum: ";
    std::cout << sum << std::endl;
    std::cout << std::endl;
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

void RucksackReorganization::PopulatePriorityData(bool useDefault)
{
    _priorityData.clear();

    std::string filePath;

    if (useDefault)
    {
        filePath = "./Data\\rucksack_reorganization.json";
    }
    else
    {
        std::cout << "Enter priority file path" << std::endl;
        std::cin >> filePath;
    }

    std::ifstream f(filePath);
    if (f.fail() || f.bad())
    {
        std::cout << "No File Found in";
        std::cout << filePath << std::endl;

        if (useDefault)
        {
            PopulatePriorityData(false);
        }

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

std::vector<char> Comapre(int sizeA, char* listA, int sizeB, char* listB)
{
    std::vector<char> matches;
    for (int j = 0; j < sizeA; ++j)
    {
        for (int k = 0; k < sizeB; ++k)
        {
            if (listA[j] == listB[k])
            {
                matches.push_back(listA[j]);
            }
        }
    }
    return matches;
}

char RucksackReorganization::FindBadge(int size, Rucksack* list)
{
    std::vector<char> matches;

    for (int i = 0; i < size - 1; ++i)
    {
        auto comp = Comapre(list[i].GetStorageSize(), list[i].GetStorage(), list[i + 1].GetStorageSize(),
                            list[i + 1].GetStorage());

        if (i == 0)
        {
            for (int j = 0, n = comp.size(); j < n; ++j)
            {
                matches.push_back(comp[j]);
            }
            continue;
        }

        std::vector<char> equals;
        for (int k = matches.size() - 1; k >= 0; --k)
        {
            for (int j = comp.size() - 1; j >= 0; --j)
            {
                if (comp[j] == matches[k])
                {
                    bool contains = false;
                    for (int l = 0, m = equals.size(); l < m; ++l)
                    {
                        if (equals[l] == comp[j])
                        {
                            contains = true;
                        }
                    }

                    if (!contains)
                    {
                        equals.push_back(comp[j]);
                    }
                }
            }
        }
        for (int k = matches.size() - 1; k >= 0; --k)
        {
            bool contains = false;
            for (int l = 0, m = equals.size(); l < m; ++l)
            {
                if (equals[l] == matches[k])
                {
                    contains = true;
                }
            }
            if (!contains)
            {
                matches.erase(matches.begin() + k);
            }
        }
    }

    if (matches.size() < 1)
    {
        return '0';
    }

    return matches[0];
}
