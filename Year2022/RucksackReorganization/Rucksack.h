#pragma once
#include <xstring>

class Rucksack
{
public:
    explicit Rucksack(const std::string* data);
    char GetCommonItem();
    char* GetStorage();
    int GetStorageSize();
private:
    char* _fullStorage;
    char* _storageA;
    char* _storageB;
    int _halfSize;
};
