#include "Worker.h"

#include <algorithm>
#include <iostream>
#include <sstream>

Worker::Worker(std::string interval)
{
    std::string delimiter = "-";
    auto pos = interval.find(delimiter);
    auto initialPos = interval.substr(0, pos);
    auto endPos = interval.substr(pos + delimiter.length(), interval.length());

    std::stringstream stream;

    stream << initialPos;
    int a;
    stream >> a;

    stream.clear();
    stream << endPos;
    int b;
    stream >> b;

    _intervalLength = b - a + 1;
    if (a < 0 || b < 0 || _intervalLength < 0)
    {
        std::cout << "Invalid interval - ";
        std::cout << interval << std::endl;
        return;
    }

    _list = new int[_intervalLength];
    for (int i = 0, n = _intervalLength; i < n; ++i)
    {
        _list[i] = a + i;
    }
}

int Worker::GetFirst()
{
    return _list[0];
}

int Worker::GetLast()
{
    return _list[_intervalLength - 1];
}
