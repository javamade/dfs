#include <stdio.h>

void mergeSort(int [], int);
void merge(int [], int [], int [], int, int);

int main()
{
    int arr[] = {2, 4, 5, 6, 1, 3, 8, 7};
    int length = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, length);

    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

void merge(int left[], int right[], int arr[], int nL, int nR)
{
    int i = 0, j = 0, k = 0;

    while (i < nL && j < nR)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < nL)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < nR)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int n)
{
    if (n <= 1)
    {
        return;
    }

    int mid = n / 2;
    int left[mid];
    int right[n - mid];

    for (int i = 0; i < mid; i++)
        left[i] = arr[i];

    for (int i = mid; i < n; i++)
        right[i - mid] = arr[i];

    mergeSort(left, mid);
    mergeSort(right, n - mid);
    merge(left, right, arr, mid, n - mid);
}