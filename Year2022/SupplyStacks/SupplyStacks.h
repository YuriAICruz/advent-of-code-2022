#pragma once
#include "../IProgram.h"

class SupplyStacks : public IProgram
{
public:
    void Execute() override;
    std::string GetDescription() override;
};
