#pragma once
#include <string>

class Match
{
public:
    void GetValue(std::string token);
    void GetValuePredicted(std::string token);
    explicit Match(std::string values, bool predict);
    int PointsWon;
private:
    // 0 - Rock | 1 - Paper | 2 - Scissors
    int _optionA;
    int _optionB;
};
