#pragma once
#include <string>
#include <vector>
#include "Elf.h"

#include "../IProgram.h"

class CalorieCounting : public IProgram
{
public:
    void Execute() override;
    int GetMax();
    std::string GetDescription() override;
private:
    std::vector<std::string> _rawData;
    std::vector<Elf*> _elfs;
};
