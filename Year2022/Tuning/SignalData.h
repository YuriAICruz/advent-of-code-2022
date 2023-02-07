#pragma once
#include <xstring>

class SignalData
{
public:
    explicit SignalData(std::string signal);
    void FindSignal(std::string* signal, int* position, int size = 4);
private:
    std::string _signal;
};
