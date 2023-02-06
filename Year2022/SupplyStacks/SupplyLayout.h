#pragma once
#include <vector>
#include <xstring>

struct Crate;

class SupplyLayout
{
public:
    explicit SupplyLayout(std::string string);
    void Print();
    void OperateFromInput(std::string operationInput, bool moveGrouped = true);
private:
    void AddToStack(std::string line);
    int GetMaxStack();
    std::vector<std::vector<Crate>> inventory;
};
