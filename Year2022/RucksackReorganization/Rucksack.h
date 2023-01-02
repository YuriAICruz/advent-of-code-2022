#pragma once
#include <xstring>

class Rucksack
{
public:
    explicit Rucksack(const std::string* data);
    char GetCommonItem();
private:
    char* _storageA;
    char* _storageB;
    int _size;
};
