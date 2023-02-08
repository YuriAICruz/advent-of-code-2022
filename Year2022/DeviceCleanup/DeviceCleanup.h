#pragma once
#include "../IProgram.h"

class DeviceCleanup : public IProgram
{
public:
    void Execute() override;

    std::string GetDescription() override
    {
        return "No Space Left On Device algorithm";
    }
};
