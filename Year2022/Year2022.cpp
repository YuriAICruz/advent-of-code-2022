
#include <iostream>
#include <sstream>
#include <string>

#include "ProgramsCollection.h"
#include "CalorieCounting/CalorieCounting.h"

int main(int argc, char* argv[])
{
    int a [3] = { 0, 1, 2 };
    auto c = new CalorieCounting();
    IProgram* programs[2] = {
        c
    };

    const auto collection = new ProgramsCollection<2>(programs);
    while (true)
    { 
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
        
        if(index == 0 || index >= collection->getSize() || collection->Programs[index-1] == nullptr)
        {
            std::cout << "invalid option:" << std::endl;
            continue;
        }

        collection->Programs[index-1]->Execute();
    }
    
    return 0;
}
