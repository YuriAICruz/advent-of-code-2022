#include "StringOperations.h"

int StringOperations::ToInt(const char* value, int h)
{
    return !value[h] ? 5381 : (ToInt(value, h+1) * 33) ^ value[h];
}

std::vector<std::string> StringOperations::Split(std::string value, std::string delimiter)
{
    size_t pos = 0;
    std::vector<std::string> args;
    while ((pos = value.find(delimiter)) != std::string::npos)
    {
        args.push_back(value.substr(0, pos));
        value.erase(0, pos + delimiter.length());
    }

    if(!value.empty())
    {
        args.push_back(value);
    }

    return args;
}