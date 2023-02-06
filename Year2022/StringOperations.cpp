#include "StringOperations.h"

constexpr unsigned int StringOperations::ToInt(const char* value, int h)
{
    return !value[h] ? 5381 : (ToInt(value, h+1) * 33) ^ value[h];
}
