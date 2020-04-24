#include "ArrayQuickSort.h"
#include "ArraySearch.h"
#include "ArrayBinarySearch.h"
#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;

int main()
{
	clock_t start;
	double duration;
	// create, randomly fill and print array for QuickSort
	const int dim = 100;
    int* arr = new int[dim];
	int minVal = -10;
	int maxVal = 10;
	srand(unsigned(time(0)));
	cout << "Not sorted array:" << endl;
	for (int i = 0; i < dim; i++)
	{
		arr[i] = rand() % (maxVal - minVal) + minVal;
		cout << arr[i] << " ";
	}
	cout << endl << endl;

	// sort array 
	//recursiveQuickSort(arr, 0, dim - 1);
	iterativeQuickSort(arr, 0, dim - 1);

	//print sorted array
	cout << "Sorted array(first 50 elements): " << endl;
	for (int i = 0; i < 50; i++)
		cout << arr[i] << " ";
	cout << endl << endl;

	// create, fill array for default search
	ArraySearch array = ArraySearch();

	// default search perfomance test
	start = clock();
	for (int i = 0; i < 1000000; i++)
		array.search(834);
	duration = ((clock() - start) / (double)CLOCKS_PER_SEC) / 1000000;

	// print pefromance time of default search
	cout << "Default search: " << duration << endl;

	// recursiveBinarySearch pefromance test
	start = clock();
	for (int i = 0; i < 1000000; i++)
		recursiveBinarySearch(2, arr, 0, dim - 1);
	duration = ((clock() - start) / (double)CLOCKS_PER_SEC) / 1000000;
	cout << "RecBinarySearch search: " << duration << endl;

	// iterativeBinarySearch pefromance test
	start = clock();
	for (int i = 0; i < 1000000; i++)
		iterativeBinarySearch(2, arr, 0, dim - 1);
	duration = ((clock() - start) / (double)CLOCKS_PER_SEC) / 1000000;
	cout << "IterBinarySearch search: " << duration << endl << endl;;

	cout << "Recursive search of -7: " << recursiveBinarySearch(-7, arr, 0, dim - 1) << endl;
	cout << "Iterarive search of -7: " << iterativeBinarySearch(-7, arr, 0, dim - 1) << endl;
}
