#include "Tuning.h"

#include <iostream>
#include <sstream>
#include <vector>

#include "SignalData.h"

void Tuning::Execute()
{
    int size;
    while (true)
    {
        std::cout << "what is group size to look? (default 4)\n";

        std::string input;        
        std::cin.ignore();        
        std::getline(std::cin, input);
        if(input.empty())
        {
            size = 4;
            break;
        }
                
        std::stringstream stream;
        stream << input;

        int index;
        stream >> index;

        if (index > 0)
        {
            size = index;
            break;
        }
    }
    
    std::cout << "selected group size ";
    std::cout << size;
    std::cout << "\n";
    
    std::cout << "input the signals: (use $ to end input)\n";

    std::string lineInput;

    std::vector<SignalData> signals;
    while (std::getline(std::cin, lineInput))
    {
        if(lineInput.empty())
        {
            continue;
        }

        if(lineInput == "$")
        {
            break;
        }

        signals.emplace_back(lineInput);
    }

    std::cout << "Processing . . .\n";
    int position;
    std::string signalData;
    for (SignalData signal : signals)
    {
        signal.FindSignal(&signalData, &position, size);
        std::cout << "signal ";
        std::cout << signalData;
        std::cout << "position ";
        std::cout << position;
        std::cout << "\n";
    }
}

std::string Tuning::GetDescription()
{
    return "Tuning Algorithm";
}
