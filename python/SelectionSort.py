# sort an array by iterating through it and finding the minimum value


def selection_sort(arr):
    # iterate through the entire array
    for i in range(0, len(arr)):
        min_index = i
        # iterate through the rest of the array after index i
        for j in range(i + 1, len(arr)):
            # for every index j in the array, compare its value with the known minimum value.
            # if its value is lower, set the minimum index to index j
            if arr[j] < arr[min_index]:
                min_index = j
        # swap the value of the minimum index with the value of index i
        temp = arr[i]
        arr[i] = arr[min_index]
        arr[min_index] = temp
