#pragma once
#include "../IProgram.h"

class Tuning : public IProgram
{
public:
    void Execute() override;
    std::string GetDescription() override;
};
