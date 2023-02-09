#include "Directory.h"

#include <iostream>

File* Directory::GetFile(std::string fileName, std::string size)
{
    for (File& _file : _files)
    {
        if (_file.GetName() == fileName)
        {
            return &_file;
        }
    }

    _files.emplace_back(fileName, size);
    return &_files[_files.size() - 1];
}

Directory* Directory::GetDirectory(const std::string& name)
{
    for (Directory& directory : _directories)
    {
        if (directory._name == name)
        {
            return &directory;
        }
    }

    return CreateDirectory(name);
}

Directory* Directory::CreateDirectory(const std::string& name)
{
    _directories.emplace_back(name, this);
    return &_directories[_directories.size() - 1];
}

int Directory::GetSize(bool recursive, int level)
{
    std::string indent = "";

    for (int i = 0; i < level; ++i)
    {
        indent += "  ";
    }

    std::cout << indent + "Directory: " + _name + "\n";
    indent += " ";

    int size = 0;
    for (auto file : _files)
    {
        std::cout << indent + file.GetName() + "(" + std::to_string(file.GetSize()) + ")\n";
        size += file.GetSize();
    }
    if (!recursive)
    {
        return size;
    }

    for (auto directory : _directories)
    {
        size += directory.GetSize(recursive, ++level);
    }

    return size;
}

int Directory::GetSizeCustom(int(* function)(File file), bool recursive, int level)
{
    std::string indent = "";

    for (int i = 0; i < level; ++i)
    {
        indent += "  ";
    }

    std::cout << indent + "Directory: " + _name + "\n";
    indent += " ";

    int size = 0;
    for (auto file : _files)
    {
        std::cout << indent + file.GetName() + "(" + std::to_string(file.GetSize()) + ")\n";
        size += function(file);
    }
    if (!recursive)
    {
        return size;
    }

    for (auto directory : _directories)
    {
        size += directory.GetSize(recursive, ++level);
    }

    return size;
}
