#pragma once
#include <vector>
#include <xstring>

#include "Directory.h"

class Console
{
private:
    void MoveToDirectory(std::string directoryName);
    int GetDirectoryIndex(const std::string dirName);
    void CreateDirectory(std::vector<std::string>::const_reference name);
public:
    Console()
    {
        _directories.push_back(Directory("/"));
    }

    void RunCommand(std::vector<std::string>::const_reference command, std::vector<std::string>::const_reference arg);
    void AddData(std::vector<std::string>::const_reference arg, std::vector<std::string>::const_reference name);
private:
    std::vector<Directory> _directories;
    int _currentDirectoryIndex;
};
