#include "Match.h"

#include <iostream>

void Match::GetValue(std::string token)
{
    if (token == "A")
    {
        _optionA = 0;
    }
    else if (token == "B")
    {
        _optionA = 1;
    }
    else if (token == "C")
    {
        _optionA = 2;
    }
    else if (token == "X")
    {
        _optionB = 0;
    }
    else if (token == "Y")
    {
        _optionB = 1;
    }
    else if (token == "Z")
    {
        _optionB = 2;
    }
}

void Match::GetValuePredicted(std::string token)
{
    if (token == "A")
    {
        _optionA = 0;
    }
    else if (token == "B")
    {
        _optionA = 1;
    }
    else if (token == "C")
    {
        _optionA = 2;
    }
    else if (token == "X")
    {
        _optionB = (3+_optionA-1)%3;
    }
    else if (token == "Y")
    {
        _optionB = _optionA;
    }
    else if (token == "Z")
    {
        _optionB = (_optionA+1)%3;
    }
}

Match::Match(std::string values, bool predict)
{
    std::string delimiter = " ";

    size_t pos = 0;
    std::string token;

    _optionA = -1;
    _optionB = -1;

    while ((pos = values.find(delimiter)) != std::string::npos)
    {
        token = values.substr(0, pos);

        if(predict)
        {
            GetValuePredicted(token);
        }else
        {
            GetValue(token);
        }

        values.erase(0, pos + delimiter.length());
    }

    if(!values.empty())
    {
        if(predict)
        {
            GetValuePredicted(values);
        }else
        {
            GetValue(values);
        }
    }
    

    // Win +6
    // Draw +3
    // Lose +0

    // 0 - Rock | 1 - Paper | 2 - Scissors
    // 0 +1
    // 1 +2
    // 2 +3

    if (_optionA < 0 || _optionB < 0)
    {
        std::cout << "\n\n Error parsing data \n\n";
        PointsWon = 0;
        return;
    }

    auto offset = (_optionB + 1) % 3;
    if (_optionA == offset) // Lose
    {
        PointsWon = 0 + _optionB + 1;
    }
    else if (_optionA == _optionB)
    {
        PointsWon = 3 + _optionB + 1;
    }
    else
    {
        PointsWon = 6 + _optionB + 1;
    }
    std::cout << "Result = " + std::to_string(PointsWon) << std::endl;
}
