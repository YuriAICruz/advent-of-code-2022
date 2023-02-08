#pragma once
#include <string>

class File
{
public:
    File(std::string fileName, std::string size)
    {
        _fileName = fileName;
        _size = size;
    }
    
private:
    std::string _fileName;
    std::string _size;
};
