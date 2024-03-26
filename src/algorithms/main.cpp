#include <iostream>
#include <algorithm>
#define MAX 10
using namespace std;

// Linear Search
int linearSearch(const int arr[MAX], const int size, const int target)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == target)
            return i;

    return -1;
}

// Display
void display(const int arr[MAX], const int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << "\t";
    cout << endl;
}

// Binary Search
int binarySearch(const int arr[MAX], const int size, const int target)
{
    int left = 0, right = size - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

// Bubble Sort
void bubbleSort(int arr[MAX], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        bool isSwap = false;
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                isSwap = true;
            }

        if (!isSwap)
            break;
    }

    display(arr, size);
}

// Insertion Sort
void insertionSort(int arr[MAX], int size)
{
    for (int i = 1; i < size; ++i)
    {
        int key = arr[i], j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }

    display(arr, size);
}

int main()
{
    int arr[MAX] = {2, 3, 4, 10, 40, 34, 57, 33, 45, 99},
        arr_2[MAX] = {2, 3, 4, 10, 40, 57, 63, 75, 89, 100},
        size = sizeof(arr) / sizeof(arr[0]), key = 40;

    int result = linearSearch(arr, size, key);
    (result == -1)
        ? cout << "Element is not present in array\n"
        : cout << "Element is present at index "
               << result << endl;

    int result_2 = binarySearch(arr_2, size, key);
    (result_2 == -1)
        ? cout << "Element is not present in array\n"
        : cout << "Element is present at index "
               << result_2 << endl;

    bubbleSort(arr, size);
    insertionSort(arr, size);

    system("pause");
    return 0;
}