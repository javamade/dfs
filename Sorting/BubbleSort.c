// Bubble Sort

#include <stdio.h>

int main()
{
    int arr[] = {5,4,3,2,1};
    
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int flag=0, temp=0, comparisons=0, swaps=0, pass=0;
    
    for(int i=0; i<n-1; i++)
    {
        flag = 0;
        pass++;
        for(int j=0; j<n-i-1; j++)
        {
            comparisons++;
            if(arr[j] > arr[j+1])
            {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
                flag = 1;
                swaps++;
            }
        }
        if(flag == 0)
        {
            break;
        }
    }    
    
    for(int k = 0; k<n; k++)
    {
        printf("%d ", arr[k]);
    }
    
    printf("\nNumber of passes: %d", pass);
    printf("\nNumber of Comparisons: %d",comparisons);
    printf("\nNumber of Swaps: %d", swaps);
    
    return 0;
}

