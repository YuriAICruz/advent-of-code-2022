#include "WorkersGroup.h"

#include <iostream>
#include <ostream>

#include "Worker.h"

WorkersGroup::WorkersGroup(std::string intervals)
{
    std::string delimiter = ",";
    size_t pos = 0;

    std::string interval;
    while ((pos = intervals.find(delimiter)) != std::string::npos)
    {
        interval = intervals.substr(0, pos);
        auto worker = new Worker(interval);
        _workers.push_back(worker);
        intervals.erase(0, pos + delimiter.length());
    }
    if (!intervals.empty())
    {
        auto worker = new Worker(intervals);
        _workers.push_back(worker);
    }
}

bool WorkersGroup::FullyOverlap()
{
    if (_workers.size() != 2)
    {
        std::cout << "Not Implemented" << std::endl;
        return false;
    }

    int a = _workers[0]->GetFirst();
    int b = _workers[0]->GetLast();

    int x = _workers[1]->GetFirst();
    int y = _workers[1]->GetLast();

    if (x >= a && y <= b || a >= x && b <= y)
    {
        return true;
    }

    return false;
}

bool WorkersGroup::Overlap()
{
    if (_workers.size() != 2)
    {
        std::cout << "Not Implemented" << std::endl;
        return false;
    }

    int a = _workers[0]->GetFirst();
    int b = _workers[0]->GetLast();

    int x = _workers[1]->GetFirst();
    int y = _workers[1]->GetLast();

    if (x >= a && x <= b || y >= a && y <= b || a >= x && a <= y || b >= x && b <= y)
    {
        return true;
    }

    return false;
}
