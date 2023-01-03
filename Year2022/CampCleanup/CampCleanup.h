#pragma once
#include "../IProgram.h"

class CampCleanup : public IProgram
{
public:
    void Execute() override;
    std::string GetDescription() override;    
};
