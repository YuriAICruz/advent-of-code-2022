#include "IProgram.h"

#include <iostream>

IProgram::~IProgram()
{
}

void IProgram::Execute()
{
    std::cout << "empty program\n";
}
