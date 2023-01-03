#pragma once
#include <vector>
#include <xstring>

class Worker
{
public:
    explicit Worker(std::string interval);
    int GetFirst();
    int GetLast();
private:
    int* _list;
    int _intervalLength;
};
