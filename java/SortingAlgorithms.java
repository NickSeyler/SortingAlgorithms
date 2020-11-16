import java.util.ArrayList;

public class SortingAlgorithms
{
    void bubbleSort(int[] arr)
    {
        int len = arr.length;

        boolean has_swapped;
        for (int i = 0; i < len - 1; i++)
        {
            has_swapped = false;
            for (int j = 0; j < len - i - 1; j++)
                if (arr[j] > arr[j + 1])
                {
                    swap(arr, j,j + 1);
                    has_swapped = true;
                }
            if (!has_swapped)
                break;
        }
    }

    void insertionSort(int[] arr)
    {
        int len = arr.length;

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

    void selectionSort(int[] arr)
    {
        int len = arr.length;

        for (int i = 0; i < len; i++)
        {
            int min_index = i;
            for (int j = i + 1; j < len; j++)
                if (arr[j] < arr[min_index])
                    min_index = j;
            swap(arr, i, min_index);
        }
    }

    void mergeSort(int[] arr)
    {
        int len = arr.length;

        if (len > 1)
        {
            int m = len / 2;
            int l_arr_len = m;
            int r_arr_len = len - m;

            int[] l_arr = new int[l_arr_len];
            int[] r_arr = new int[r_arr_len];

            for (int i = 0; i < l_arr_len; i++)
                l_arr[i] = arr[i];
            for (int j = 0; j < r_arr_len; j++)
                r_arr[j] = arr[j + m];

            mergeSort(l_arr);
            mergeSort(r_arr);

            int i = 0; int j = 0; int k = 0;

            while (i < l_arr_len && j < r_arr_len)
            {
                if(l_arr[i] < r_arr[j])
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
        }
    }

    void quicksort(int[] arr)
    {
        int len = arr.length;

        if (len > 1)
        {
            int current_index = 0;
            for (int i = 1; i < len; i++)
                if (arr[i] <= arr[0])
                {
                    current_index++;
                    swap(arr, i, current_index);
                }

            swap(arr, 0, current_index);

            int l_arr_len = current_index;
            int r_arr_len = len - current_index - 1;

            int[] l_arr = new int[l_arr_len];
            int[] r_arr = new int[r_arr_len];

            for (int i = 0; i < l_arr_len; i++)
                l_arr[i] = arr[i];
            for (int j=0; j < r_arr_len; j++)
                r_arr[j] = arr[j + current_index + 1];

            quicksort(l_arr);
            quicksort(r_arr);

            for (int i = 0; i < l_arr_len; i++)
                arr[i] = l_arr[i];
            for (int j = 0; j < r_arr_len; j++)
                arr[j + current_index + 1] = r_arr[j];
        }
    }

    void swap(int[] arr, int x, int y)
    {
        int temp = arr[x];
        arr[x] = arr[y];
        arr[y] = temp;
    }

    void printArr(int[] arr)
    {
        int len = arr.length;
        for (int i = 0; i < len; i++)
            System.out.print(arr[i] + " ");
        System.out.println();
    }


    public static void main(String[] args)
    {
        SortingAlgorithms s = new SortingAlgorithms();
        int[] arr = {9, 3, 4, 2, 6, 10, 1, 8, 7, 5 };
        s.printArr(arr);
        s.quicksort(arr);
        s.printArr(arr);
    }
}
