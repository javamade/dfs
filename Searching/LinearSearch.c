// WAP in C to perform Linear Search and make a function for linear search.

#include <stdio.h>

int linearSearch(int arr[], int size, int search)
{
    for(int i=0; i<size; i++)
    {
        if(arr[i] == search)
        {
            return i;
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
    printf("Enter element :-\n");
    input(arr, size);
    printf("Enter element to search : ");
    scanf("%d", &search);

    int index = linearSearch(arr, size, search);

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