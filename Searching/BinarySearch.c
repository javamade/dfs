#include <stdio.h>

int binarySearch(int arr[], int search, int length)
{
    int left = 0, right = length - 1, mid = 0;

    while (left <= right)
    {
        mid = (left + right) / 2;
        if (arr[mid] == search)
        {
            return mid;
        }
        else if (arr[mid] > search)
        {
            right = mid - 1;
        }
        else if (arr[mid] < search)
        {
            left = mid + 1;
        }
    }
    return -1;
}

void input(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
}

int main()
{
    int arr[100], size = 0, search = 0;
    printf("Enter how many you want : ");
    scanf("%d", &size);
    printf("Enter elements in ascending order :-\n");
    input(arr, size);
    printf("Enter element to search : ");
    scanf("%d", &search);

    int index = binarySearch(arr, search, size);

    if (index >= 0)
    {
        printf("Element found at position %d \n", index + 1);
    }
    else
    {
        printf("Element not found\n");
    }

    return 0;
}