#include "SignalData.h"

#include <vector>

SignalData::SignalData(std::string signal)
{
    _signal = signal;
}

void SignalData::FindSignal(std::string* signal, int* pos, const int size)
{
    std::vector<char> signalChars;
    signalChars.resize(size);

    *pos = size-1;
    for (const int n = static_cast<int>(_signal.size()); *pos < n; ++(*pos))
    {
        bool isUnique = true;

        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                if(i == j)
                {
                    continue;
                }

                if(_signal[*pos-i] == _signal[*pos-j])
                {
                    isUnique = false;
                    break;
                }
            }
        }

        if(isUnique)
        {
            for (int j = 0, m = size-1; j <= m; ++j)
            {
                signalChars[m-j] = _signal[*pos-j];
            }
            break;
        }
    }

    *pos += 1;
    std::string s = "";
    for (const char signalChar : signalChars)
    {
        s += signalChar;
    }
    *signal = s;
}

std::string convertToString(char* a, int size)
{
    int i;
    std::string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}