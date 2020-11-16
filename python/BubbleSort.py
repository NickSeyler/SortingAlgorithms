# iterate through an array by comparing two elements in the array in order, then again until the array is sorted


def bubble_sort(arr):
    # initialization
    has_swapped = True
    while has_swapped:
        has_swapped = False
        # iterate through the array and compare the element at index i to the next element.
        # if the element and index i is larger, swap them. the array "has performed a swap" this cycle.
        # the array is sorted when the array does not perform a swap
        for i in range(0, len(arr) - 1):
            if arr[i] > arr[i+1]:
                temp = arr[i]
                arr[i] = arr[i+1]
                arr[i+1] = temp
                has_swapped = True