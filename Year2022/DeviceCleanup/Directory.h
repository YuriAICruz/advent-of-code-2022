#pragma once
#include <string>
#include <vector>

#include "File.h"

struct Directory
{
    Directory() {  }

    explicit Directory(const std::string& name)
    {
        _name = name;
        _parent = nullptr;
    }

    explicit Directory(const std::string& name, Directory* parent)
    {
        _name = name;
        _parent = parent;
    }

    std::string GetFullPath()
    {
        return _name;
    }

    File* GetFile(std::string fileName, std::string size);

    std::vector<File> GetFiles()
    {
        return _files;
    }

    Directory* GetParent() const
    {
        return _parent;
    }

    Directory* GetDirectory(const std::string& string);
    Directory* CreateDirectory(const std::string& name);
    int GetSize(bool recursive, int level = 0);

private:
    std::string _name;
    Directory* _parent;
    std::vector<File> _files;
    std::vector<Directory> _directories;
};
