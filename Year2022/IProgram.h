#pragma once
#include <string>

class IProgram
{
public:
    virtual ~IProgram();
    virtual void Execute();
    virtual std::string GetDescription();
};
