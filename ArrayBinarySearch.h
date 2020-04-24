#pragma once

int iterativeBinarySearch(int val, int* arr, int left, int right)
{
    int mid = 0;
    int index = -1;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (val <= arr[mid])
            right = mid - 1;
        else if (val > arr[mid])
            left = mid + 1;
        if (val == arr[mid])
            index = mid;
    }
    return index;
}

int recursiveBinarySearch(int val, int* arr, int left, int right)
 {
    if (left == right)
    {
        if (arr[left] == val) return left;
        return -1;
    }
    int mid = (left + right) / 2;
    if (arr[mid] < val)
        return recursiveBinarySearch(val, arr, mid + 1, right);
    else
        return recursiveBinarySearch(val, arr, left, mid);
}
