#include "SupplyStacks.h"

#include <deque>
#include <iostream>

#include "SupplyLayout.h"

void SupplyStacks::Execute()
{
    bool moveAsGroup = true;
    while (true)
    {
        std::cout << "Move boxes in group? [Y/n]\n";
        std::string groupInput;
        std::cin.ignore();
        std::getline(std::cin, groupInput);
        if(groupInput.empty() || groupInput == "y" || groupInput == "Y")
        {
            moveAsGroup = true;
            break;
        }

        if (groupInput == "n" || groupInput == "N")
        {
            moveAsGroup = false;
            break;
        }
    }
    
    std::string layoutInput;
    std::cout << "Input boxes layout [use $ to end input]\n";

    std::deque<std::string> linesQ;
    while (std::getline(std::cin, layoutInput))
    {
        if(layoutInput.empty())
        {
            continue;
        }

        if(layoutInput == "$")
        {
            break;
        }

        linesQ.push_front(layoutInput);
    }

    std::string layoutFullInput;

    for( auto const& s : linesQ )
    {
        layoutFullInput+= s;
        layoutFullInput+= "\n";
    }

    auto layout = new SupplyLayout(layoutFullInput);
    
    std::cout << "Input operations: [use $ to end input]\n";

    std::string operationInput;
    while (std::getline(std::cin, operationInput))
    {
        if(operationInput.empty())
        {
            continue;
        }

        if(operationInput == "$")
        {
            break;
        }
        
        layout->OperateFromInput(operationInput, moveAsGroup);
    }
    
    std::cout << "Operations finished\n";

    layout->Print();
    
    std::cout << "\n";
}

std::string SupplyStacks::GetDescription()
{
    return "Supply Stacks Algorithm";
}
