#pragma once
#include <sstream>
#include <string>

class File
{
public:
    File(std::string fileName, std::string sizeInput)
    {
        _fileName = fileName;

        std::stringstream stream;
        stream << sizeInput;
        int size;
        stream >> size;

        _size = size;
    }
    
    int GetSize()
    {
        return _size;
    }

    std::string GetName()
    {
        return _fileName;
    }

private:
    std::string _fileName;
    int _size;
};
