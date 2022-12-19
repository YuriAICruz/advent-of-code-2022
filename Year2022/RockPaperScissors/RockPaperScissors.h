#pragma once

#include "Match.h"
#include "../IProgram.h"

class RockPaperScissors : public IProgram
{
public:
    void Execute() override;
    std::string GetDescription() override;
};
