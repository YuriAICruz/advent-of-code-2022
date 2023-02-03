#include "SupplyLayout.h"

#include <iostream>
#include <sstream>
#include <string>

#include "Crate.h"

SupplyLayout::SupplyLayout(std::string layoutInput)
{
    std::istringstream iss(layoutInput);
    for(std::string line; std::getline(iss, line);)
    {
        AddToStack(line);
    }
}

void SupplyLayout::AddToStack(std::string line)
{
    for (int i = 0, n = static_cast<int>(line.size()); i <= n; i += 4)
    {
        if (inventory.size() <= (i / 4))
        {
            for (int j = static_cast<int>(inventory.size()), m = (i / 4); j <= m; ++j)
            {
                inventory.push_back(*new std::vector<Crate>);
            }
        }

        std::string key = line.substr(i + 1, 1);

        if(!isspace(key[0]))
        {
            auto crate = Crate(key);
            inventory[i / 4].push_back(crate);
        }
    }
}

int SupplyLayout::GetMaxStack()
{
    int max = 0;
    for (auto& i : inventory)
    {
        max = std::max(max, static_cast<int>(i.size()));
    }
    return max;
}

void SupplyLayout::OperateFromInput(std::string operationInput)
{
}

void SupplyLayout::Print()
{
    std::string stack;
    
    for (int k = GetMaxStack(); k >= 0; --k)
    {
        for (int i = 0, n = static_cast<int>(inventory.size()); i < n; ++i)
        {
            const int size = static_cast<int>(inventory[i].size());

            if (size <= k)
            {
                stack += "    ";
                continue;
            }
            
            stack += "[";
            stack += inventory[i][k].Key;
            stack += "] ";
        }
        stack += "\n";
    }

    for (int i = 0, n = static_cast<int>(inventory.size()); i < n; ++i)
    {
        stack += " ";
        stack += std::to_string(i+1);
        stack += "  ";
    }

    stack += "\n";

    std::cout << stack;
}
