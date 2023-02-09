#pragma once
#include <vector>
#include <xstring>

#include "Directory.h"

class Console
{
private:
    void MoveToDirectory(std::string directoryName);
public:
    Console()
    {
        _directory = Directory("/");
        _currentDirectory = &_directory;
    }

    void RunCommand(std::vector<std::string>::const_reference command, std::vector<std::string>::const_reference arg);
    void AddData(std::vector<std::string>::const_reference arg, std::vector<std::string>::const_reference name);
    int GetTotalSize();
    int GetTotalSizeCustom(int (* function)(File file));
private:
    Directory _directory;
    Directory* _currentDirectory;
};
