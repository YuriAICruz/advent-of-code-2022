#include "DeviceCleanup.h"

#include <iostream>
#include <vector>

#include "Console.h"
#include "../StringOperations.h"

void DeviceCleanup::Execute()
{
    std::cout << "Enter commands sequence use '$ quit' to exit\n";

    Console console = Console();
    std::string lineInput;
    while (std::getline(std::cin, lineInput))
    {
        std::vector<std::string> args = StringOperations::Split(lineInput, " ");
        if(args.size()<=0)
        {
            continue;
        }
        if(args.size()==1)
        {
            continue;
        }
        if(args[0] == "$")
        {
            if(args[1] == "quit" || args[1] == "exit")
            {
                break;
            }

            if(args.size() == 2)
            {
                console.RunCommand(args[1], "");
            }else
            {
                console.RunCommand(args[1], args[2]);
            }
        }else
        {
            console.AddData(args[0], args[1]);
        }
    }

    int size = console.GetTotalSizeCustom([](File file){
        if(file.GetSize() >= 100000)
        {
            return 0;
        }
        return file.GetSize();
    });
    
    std::cout << "Total filtered size: " + std::to_string(size) + "\n";
    
    size = console.GetTotalSize();
    std::cout << "Total size: " + std::to_string(size) + "\n";
}
