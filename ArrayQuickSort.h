#pragma once

void recursiveQuickSort(int* arr, int start, int end)
{
    int i = start, j = end;
    int tmp;
    int pivot = arr[(start + end) / 2];
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };
    if (start < j)
        recursiveQuickSort(arr, start, j);
    if (i < end)
        recursiveQuickSort(arr, i, end);
}

void iterativeQuickSort(int* arr, int start, int end)
{
	const int dim = 100;
	int tempMemory[dim];
	int top = -1;
	tempMemory[++top] = start;
	tempMemory[++top] = end;

	while (top >= 0)
	{
		end = tempMemory[top--];
		start = tempMemory[top--];
		int tmp;
		int pivot = arr[end];
		int pIndex = start;
		for (int i = start; i < end; ++i)
			if (arr[i] < pivot)
			{
				tmp = arr[i];
				arr[i] = arr[pIndex];
				arr[pIndex] = tmp;
				pIndex++;
			}
		tmp = arr[end];
		arr[end] = arr[pIndex];
		arr[pIndex] = tmp;

		if (pIndex - 1 > start)
		{
			tempMemory[++top] = start;
			tempMemory[++top] = pIndex - 1;
		}
		if (pIndex + 1 < end)
		{
			tempMemory[++top] = pIndex + 1;
			tempMemory[++top] = end;
		}
	}
}
