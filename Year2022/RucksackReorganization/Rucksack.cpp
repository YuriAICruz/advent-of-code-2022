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

	_fullStorage = arr;

	_halfSize = length/2;
	_storageA = new char[_halfSize];
	for (int i = 0, n = _halfSize; i < n; ++i)
	{
		_storageA[i] = arr[i];
	}
	
	_storageB = new char[_halfSize];
	for (int i = 0, j = _halfSize; j < length; ++i, ++j)
	{
		_storageB[i] = arr[j];
	}
}

char Rucksack::GetCommonItem()
{
	for (int i = 0, n = _halfSize; i < n; ++i)
	{
		for (int j = 0, m = _halfSize; j < m; ++j)
		{
			if(_storageA[i] == _storageB[j])
			{
				return _storageA[i];
			}
		}
	}
	
	return '0';
}

char* Rucksack::GetStorage()
{
	return _fullStorage;
}

int Rucksack::GetStorageSize()
{
	return _halfSize*2;
}
