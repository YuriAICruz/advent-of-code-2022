#include "SupplyLayout.h"

#include <deque>
#include <iostream>
#include <sstream>
#include <string>

#include "Crate.h"
#include "../StringOperations.h"

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

void SupplyLayout::OperateFromInput(std::string operationInput, bool moveGrouped)
{
    const std::string delimiter = " ";
    size_t pos = 0;
    std::vector<std::string> args;
    while ((pos = operationInput.find(delimiter)) != std::string::npos)
    {
        args.push_back(operationInput.substr(0, pos));
        operationInput.erase(0, pos + delimiter.length());
    }
    
    if(!operationInput.empty())
    {
        args.push_back(operationInput);
    }


    int amount = -1;
    int originIndex = -1;
    int destinationIndex = -1;
    for (int i = 0, n = args.size(); i < n; ++i)
    {
        if (i + 1 >= n)
        {
            continue;
        }

        std::stringstream stream;
        stream << args[i + 1];

        int value;
        stream >> value;

        if (args[i] == "move")
        {
            amount = value;
        }
        else if (args[i] == "from")
        {
            originIndex = value - 1;
        }
        else if (args[i] == "to")
        {
            destinationIndex = value - 1;
        }
        else
        {
            //std::cout << "no valid argument\n";
        }        
    }

    if(amount <0 || originIndex < 0 || destinationIndex < 0)
    {
        std::cout << "command not complete\n";
    }


    const int size = static_cast<int>(inventory.size());
    if(originIndex >= size)
    {
        std::cout << "origin value invalid\n";
        return;
    }

    if(destinationIndex >= size)
    {
        std::cout << "destination value invalid\n";
        return;
    }

    std::deque<Crate> crates;
    for (int i = 0; i < amount; ++i)
    {
        const int columnSize = static_cast<int>(inventory[originIndex].size());

        if(columnSize <= 0)
        {
            std::cout << "not enough to remove";
            continue;
        }

        if (moveGrouped)
        {
            crates.push_front(inventory[originIndex][columnSize - 1]);
        }
        else
        {
            crates.push_back(inventory[originIndex][columnSize - 1]);
        }

        inventory[originIndex].pop_back();
    }
    for (int i = 0; i < amount; ++i)
    {
        inventory[destinationIndex].push_back(crates[i]);
    }

    crates.clear();
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
