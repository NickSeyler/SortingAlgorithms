import math


def merge_sort(arr):
    if len(arr) > 1:
        # separate the array into two equal parts. Repeat the process until the length of all subarrays is one
        m = math.floor(len(arr) / 2)
        l_arr = arr[0:m]
        r_arr = arr[m:len(arr)]

        merge_sort(l_arr)
        merge_sort(r_arr)

        # initialization
        i = 0
        j = 0
        k = 0
        # while arrays are not sorted, compare the two unsorted subarrays and sort them into their main array,
        # when one of the subarrays is sorted, put the elements of the remaining subarray into the main array in order.
        while i < len(l_arr) and j < len(r_arr):
            if l_arr[i] < r_arr[j]:
                arr[k] = l_arr[i]
                i += 1
            else:
                arr[k] = r_arr[j]
                j += 1
            k += 1

        while i < len(l_arr):
            arr[k] = l_arr[i]
            i += 1
            k += 1
        while j < len(r_arr):
            arr[k] = r_arr[j]
            j += 1
            k += 1
