def quick_sort(arr):

    # if we don't know whether or not the array is sorted...
    if len(arr) > 1:
        # set pivot to the first index
        current_index = 0

        # check all other items in the array
        for i in range(1, len(arr)):
            # if the item of the compared index is less than or equal to the item of the original pivot index,
            # increment the current index and swap that item with the compared item.
            # Note: this sometimes swaps the current index's item with itself. this is intended.
            if arr[i] <= arr[0]:
                current_index += 1
                temp = arr[i]
                arr[i] = arr[current_index]
                arr[current_index] = temp

        # after checking all items, swap the pivot item with item of the new pivot index
        # in order to place the pivot item at its proper pivot
        temp = arr[0]
        arr[0] = arr[current_index]
        arr[current_index] = temp

        # perform the quicksort with items left of the index and right of the index. do not include the index
        left_arr = arr[0:current_index]
        right_arr = arr[current_index+1:len(arr)]
        quick_sort(left_arr)
        quick_sort(right_arr)

        # finally, combine the items left of the pivot index, the item of the pivot index, and the items right of the
        # pivot index.
        sorted_arr = left_arr + [arr[current_index]] + right_arr
        for i in range(0, len(arr)):
            arr[i] = sorted_arr[i]