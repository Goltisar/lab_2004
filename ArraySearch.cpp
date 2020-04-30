#include "ArraySearch.h"

ArraySearch::ArraySearch()
{
	int minVal = -1000;
	int maxVal = 1000;
	srand(unsigned(time(0)));
	for (int i = 0; i < N; i++)
		ArraySearch::array[i] = rand() % (maxVal - minVal) + minVal;
}

ArraySearch::~ArraySearch()
{
	delete ArraySearch::array;
}

int ArraySearch::search(int val) const
{
	for (int i = 0; i < N; i++)
		if (array[i] == val)
			return i;
}
