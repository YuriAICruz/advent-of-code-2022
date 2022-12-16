#pragma once
#include <vector>

class Elf
{
public:
    explicit Elf();
    void addCalorie(int calorie);
    std::vector<int> calories;
};
