#pragma once
#include <cstdlib>
#include <ctime>

class ArraySearch
{
public:
	ArraySearch();
	~ArraySearch();
	int search(int) const;
private:
	const int N = 10000;
	int* array = new int[N];
};
