#pragma once

class PriorityData
{
public:
    PriorityData(char key, int value)
    {
        Key = key;
        Value = value;
    }

    char Key;
    int Value;
};
