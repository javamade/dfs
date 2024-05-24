#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void max_heapify(int A[], int n, int i)
{
    // find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && A[left] > A[largest])
        largest = left;

    if (right < n && A[right] > A[largest])
        largest = right;

    // Swap and continue heapifying if the root is not the greatest
    if (largest != i)
    {
        swap(&A[largest], &A[i]);
        max_heapify(A, n, largest);
    }
}


void heapSort(int A[], int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
        max_heapify(A, size, i);

    for (int i = size - 1; i >= 0; i--)
    {
        swap(&A[0], &A[i]);
        max_heapify(A, i, 0);
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

int main()
{
    int arr[100];
    int size = 0, num = 0;
    printf("Enter no. of elements: ");
    scanf("%d", &size);
    printf("Enter array elements: ");

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &num);
        arr[i] = num;
    }

    heapSort(arr, size);
    printf("Sorted array: ");
    printArray(arr, size);
    printf("\n");
}