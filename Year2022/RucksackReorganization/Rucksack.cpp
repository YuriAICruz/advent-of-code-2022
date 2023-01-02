#include "Rucksack.h"

#include <iostream>

Rucksack::Rucksack(const std::string* data)
{
	const int length = (*data).length()+1;
    char* arr = new char[length];

	for (int i = 0; i < length; ++i)
	{
		arr[i] = (*data)[i];
	}

	_size = length/2;
	_storageA = new char[_size];
	for (int i = 0, n = _size; i < n; ++i)
	{
		_storageA[i] = arr[i];
	}
	
	_storageB = new char[_size];
	for (int i = 0, j = _size; j < length; ++i, ++j)
	{
		_storageB[i] = arr[j];
	}
}

char Rucksack::GetCommonItem()
{
	for (int i = 0, n = _size; i < n; ++i)
	{
		for (int j = 0, m = _size; j < m; ++j)
		{
			if(_storageA[i] == _storageB[j])
			{
				return _storageA[i];
			}
		}
	}
	
	return '0';
}
