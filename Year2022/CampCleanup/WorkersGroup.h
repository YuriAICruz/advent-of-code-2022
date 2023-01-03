#pragma once
#include <string>
#include <vector>

class Worker;

class WorkersGroup
{
public:
    explicit WorkersGroup(std::string intervals);
    bool FullyOverlap();
private:
    std::vector<Worker*> _workers;
};
