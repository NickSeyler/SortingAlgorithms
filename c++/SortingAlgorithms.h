#pragma once
class SortingAlgorithms
{
public:
	void bubbleSort(int arr[], int len);
	void insertionSort(int arr[], int len);
	void selectionSort(int arr[], int len);
	void mergeSort(int arr[], int len);
	void quickSort(int arr[], int len);

	void swap(int* x, int* y);
	void printArr(int arr[], int len);
};