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
        auto path = StringOperations::Split(_directories[_currentDirectoryIndex].GetFullPath(), "/");
        std::string dirName = "";
        for (int i = 0, n = static_cast<int>(path.size()) - 1; i < n; ++i)
        {
            dirName += path[i];
        }

        _currentDirectoryIndex = GetDirectoryIndex(dirName);
        if (_currentDirectoryIndex < 0)
        {
            _currentDirectoryIndex = 0;
            std::cout << "Directory not found ";
            std::cout << dirName;
            std::cout << "\n";
        }

        return;
    }

    int newDirectoryIndex = GetDirectoryIndex(directoryName);
    if (newDirectoryIndex < 0)
    {
        CreateDirectory(directoryName);
        _currentDirectoryIndex = static_cast<int>(_directories.size()) - 1;
    }
    else
    {
        _currentDirectoryIndex = newDirectoryIndex;
    }
}

int Console::GetDirectoryIndex(const std::string dirName)
{
    for (int i = 0, n = static_cast<int>(_directories.size()); i < n; ++i)
    {
        if (_directories[i].GetFullPath() == dirName)
        {
            return i;
        }
    }

    return -1;
}

void Console::AddData(std::vector<std::string>::const_reference arg,
                      std::vector<std::string>::const_reference name)
{
    if(arg == "dir")
    {
        CreateDirectory(name);
        return;
    }

    _directories[_currentDirectoryIndex].AddFile(name, arg); 
}

void Console::ListDirectories()
{
    for (Directory directory : _directories)
    {
        int totalSize = GetSize(directory);
        std::cout << "Dir ";
        std::cout << directory.GetFullPath();
        std::cout << " size ";
        std::cout << totalSize;
        std::cout << "\n";
    }
}

void Console::CreateDirectory(std::vector<std::string>::const_reference name)
{
    _directories.emplace_back(_directories[_currentDirectoryIndex].GetFullPath() + "/" + name);
}

int Console::GetSize(Directory directory)
{
    int totalSize = 0;

    std::vector<File> files = directory.GetFiles();

    for (auto file : files)
    {
        totalSize += file.GetSize();
    }

    std::vector<Directory> directories = GetChildDirectories(directory);

    for (Directory directory : directories)
    {
        totalSize += GetSize(directory);
    }

    return totalSize;
}

std::vector<Directory> Console::GetChildDirectories(Directory directory)
{
    std::vector<Directory> directories;
    for (int i = 0, n = static_cast<int>(_directories.size()); i < n; ++i)
    {
        if (_directories[i].GetFullPath().find(directory.GetFullPath()+"/") != std::string::npos)
        {
            directories.push_back(_directories[i]);
        }
    }
    return directories;
}
