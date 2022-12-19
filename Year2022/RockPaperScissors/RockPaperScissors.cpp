#include "RockPaperScissors.h"

#include <iostream>
#include <vector>

#include "Match.h"
#include "../VectorOperations.h"


void RockPaperScissors::Execute()
{
    std::string predict;
    bool willPredict;

    while (true)
    {
        std::cout << "Predict? (Y/n)" << std::endl;
        std::cin >> predict;

        if (predict.empty() || predict == "y" || predict == "Y")
        {
            willPredict = true;
            break;
        }

        if (predict == "n" || predict == "N")
        {
            willPredict = false;
            break;
        }

        std::cout << "Invalid answer" << std::endl;
    }

    std::cout << "Please input all lines of games ($ to end)" << std::endl;
    std::string line;


    std::vector<Match*> matches;
    while (std::getline(std::cin, line))
    {
        if (line.empty())
        {
            continue;
        }
        if (line == "$")
        {
            break;
        }

        auto match = new Match(line, willPredict);
        matches.push_back(match);
    }

    int points = VectorOperations::Sum<Match*>(matches, [](Match* match)
    {
        return match->PointsWon;
    });

    std::cout << "Total Points: " + std::to_string(points) << std::endl;
}

std::string RockPaperScissors::GetDescription()
{
    return "Rock, Paper and Scissors Algorithm";
}
