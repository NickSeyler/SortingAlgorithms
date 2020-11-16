from BubbleSort import bubble_sort
from InsertionSort import insertion_sort
from MergeSort import merge_sort
from QuickSort import quick_sort
from SelectionSort import selection_sort


def main():
    arr = [9, 3, 4, 2, 6, 10, 1, 8, 7, 5]
    print(arr)
    quick_sort(arr)
    print(arr)


if __name__ == "__main__":
    main()