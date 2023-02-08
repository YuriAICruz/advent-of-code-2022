#include "Console.h"

#include <iostream>
#include <stdexcept>

#include "../StringOperations.h"

void Console::RunCommand(std::vector<std::string>::const_reference command,
                         std::vector<std::string>::const_reference arg)
{
    if (command == "cd")
    {
        MoveToDirectory(arg);
        return;
    }

    if (command == "ls")
    {
    }
}

void Console::MoveToDirectory(std::string directoryName)
{
    if (directoryName == "..")
    {
        Directory* dir = _currentDirectory->GetParent();
        _currentDirectory = dir;
        return;
    }

    if(directoryName == "/")
    {
        _currentDirectory = &_directory;
        return;
    }

    Directory* dir = _currentDirectory->GetDirectory(directoryName);
    _currentDirectory = dir;
}

void Console::AddData(std::vector<std::string>::const_reference arg,
                      std::vector<std::string>::const_reference name)
{
    if (arg == "dir")
    {
        Directory* dir = _currentDirectory->GetDirectory(name);
        _currentDirectory = dir;
        return;
    }

    _currentDirectory->GetFile(name, arg);
}

void Console::GetTotalSize()
{
    int size = _directory.GetSize(true);
    std::cout << "Total size: " + std::to_string(size);
}
