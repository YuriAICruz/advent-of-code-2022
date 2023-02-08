#include <iostream>
#include <sstream>
#include <string>

#include "ProgramsCollection.h"
#include "CalorieCounting/CalorieCounting.h"
#include "CampCleanup/CampCleanup.h"
#include "DeviceCleanup/DeviceCleanup.h"
#include "RockPaperScissors/RockPaperScissors.h"
#include "RucksackReorganization/RucksackReorganization.h"
#include "SupplyStacks/SupplyStacks.h"
#include "Tuning/Tuning.h"

int main(int argc, char* argv[])
{
    IProgram* programs[7] = {
        new CalorieCounting(),
        new RockPaperScissors(),
        new RucksackReorganization(),
        new CampCleanup(),
        new SupplyStacks(),
        new Tuning(),
        new DeviceCleanup(),
    };

    const auto collection = new ProgramsCollection<7>(programs);
    while (true)
    { 
        std::cout << collection->OptionValues() << std::endl;
        std::cout << "Input a option:" << std::endl;
        std::string input;
        std::cin >> input;
        
        std::stringstream stream;
        stream << input;

        int index;
        stream >> index;

        if(index < 0)
        {
            break;
        }
        
        if(index == 0 || index > collection->getSize() || collection->Programs[index-1] == nullptr)
        {
            std::cout << "invalid option:" << std::endl;
            continue;
        }

        collection->Programs[index-1]->Execute();
    }
    
    return 0;
}
