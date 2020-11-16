#include "SortingAlgorithms.h"
#include <iostream>

void SortingAlgorithms::bubbleSort(int arr[], int len)
{
    bool has_swapped;

    for (int i = 0; i < len - 1; i++)
    {
        has_swapped = false;
        for (int j = 0; j < len - i - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                has_swapped = true;
            }
        if (!has_swapped)
            break;
    }
}

void SortingAlgorithms::insertionSort(int arr[], int len)
{
    for (int i = 1; i < len; i++)
    {
        int unsorted_item = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > unsorted_item)
        {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = unsorted_item;
    }
}

void SortingAlgorithms::selectionSort(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < len; j++)
            if (arr[j] < arr[min_index])
                min_index = j;
        swap(&arr[i], &arr[min_index]);
    }
}

void SortingAlgorithms::mergeSort(int arr[], int len)
{
    if (len > 1)
    {
        int m = len / 2;
        int l_arr_len = m;
        int r_arr_len = len - m;

        int* l_arr = new int[l_arr_len];
        int* r_arr = new int[r_arr_len];

        for (int i = 0; i < l_arr_len; i++)
            l_arr[i] = arr[i];
        for (int j = 0; j < r_arr_len; j++)
            r_arr[j] = arr[j + m];


        mergeSort(l_arr, l_arr_len);
        mergeSort(r_arr, r_arr_len);

        int i = 0; int j = 0; int k = 0;

        while (i < l_arr_len && j < r_arr_len)
        {
            if (l_arr[i] < r_arr[j])
            {
                arr[k] = l_arr[i];
                i++;
            }
            else
            {
                arr[k] = r_arr[j];
                j++;
            }
            k++;
        }

        while (i < l_arr_len)
        {
            arr[k] = l_arr[i];
            i++;
            k++;
        }

        while (j < r_arr_len)
        {
            arr[k] = r_arr[j];
            j++;
            k++;
        }

        delete[] l_arr;
        delete[] r_arr;
    }
}

void SortingAlgorithms::quickSort(int arr[], int len)
{
    if (len > 1)
    {
        int current_index = 0;
        for (int i = 1; i < len; i++)
            if (arr[i] <= arr[0])
            {
                current_index++;
                swap(&arr[i], &arr[current_index]);
            }

        swap(&arr[0], &arr[current_index]);
        
        int l_arr_len = current_index;
        int r_arr_len = len - current_index - 1;

        int* l_arr = new int[l_arr_len];
        int* r_arr = new int[r_arr_len];

        for (int i = 0; i < l_arr_len; i++)
            l_arr[i] = arr[i];
        for (int j = 0; j < r_arr_len; j++)
            r_arr[j] = arr[j + current_index + 1];
        quickSort(l_arr, l_arr_len);
        quickSort(r_arr, r_arr_len);

        for (int i = 0; i < l_arr_len; i++)
            arr[i] = l_arr[i];

        for (int j = 0; j < r_arr_len; j++)
            arr[j + current_index + 1] = r_arr[j];

        delete[] l_arr;
        delete[] r_arr;
    }
}

void SortingAlgorithms::swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void SortingAlgorithms::printArr(int arr[], int len)
{
    int i;
    std::cout << "Sorted array: \n";
    for (i = 0; i < len; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main()
{
    int arr[] = {9, 3, 4, 2, 6, 10, 1, 8, 7, 5 };
    int len = sizeof(arr) / sizeof(arr[0]);
    SortingAlgorithms s = SortingAlgorithms();
    s.quickSort(arr, len);
    s.printArr(arr, len);
    return 0;
}