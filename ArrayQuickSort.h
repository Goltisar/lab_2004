#pragma once
#define MAXSTACK 2048 // максимальный размер стека

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

int partition(int* arr, int start, int end)
{
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
	return pIndex;
}
void iterativeQuickSort(int* arr, int start, int end)
{
	const int stackSize = 2048;
	int stack[stackSize];
	int top = -1;
	stack[++top] = start;
	stack[++top] = end;

	while (top >= 0)
	{
		end = stack[top--];
		start = stack[top--];
		int pivot_index = partition(arr, start, end);

		if (pivot_index - 1 > start)
		{
			stack[++top] = start;
			stack[++top] = pivot_index - 1;
		}
		if (pivot_index + 1 < end)
		{
			stack[++top] = pivot_index + 1;
			stack[++top] = end;
		}
	}
}
