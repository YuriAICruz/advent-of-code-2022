#pragma once
#include <string>
#include <vector>

class StringOperations
{
public:
    static int ToInt(const char* value, int h = 0);
    static std::vector<std::string> Split(std::string value, std::string delimiter);
};
