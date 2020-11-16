# sort an array by iterating through it and placing the next value into the proper position


def insertion_sort(arr):
    # iterate through the entire array and assume arr[0] is a sorted item
    for i in range(1, len(arr)):
        unsorted_item = arr[i]
        j = i - 1
        # iterate through the array in reverse and compare the unsorted item to the next item.
        # shift the array's items up one when the unsorted item is less than the value of the item at index j, otherwise
        # place the item into its sorted position
        while j >= 0 and arr[j] > unsorted_item:
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = unsorted_item