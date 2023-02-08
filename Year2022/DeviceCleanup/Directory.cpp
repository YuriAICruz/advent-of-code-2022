#include "Directory.h"

void Directory::AddFile(std::string fileName, std::string size)
{
    _files.emplace_back(fileName, size);
}
