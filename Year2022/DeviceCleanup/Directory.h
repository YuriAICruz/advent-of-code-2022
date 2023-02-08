#pragma once
#include <string>
#include <vector>

#include "File.h"

struct Directory
{
    explicit Directory(const std::string name)
    {
        _name = name;
    }

    std::string GetFullPath()
    {
        return _name;
    }

    void AddFile(std::string fileName, std::string size);

private:
    std::string _name;
    std::vector<File> _files;
};
