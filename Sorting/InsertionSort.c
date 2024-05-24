// Insertion Sort

#include <stdio.h>

int main()
{
    int arr[] = {5,2,6,8};
    
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int temp = 0, comparisons=0, swaps=0, pass=0;
    int i,j;
    
    for(i=1; i<n;i++) 
    {
        temp = arr[i];
        j = i-1;
        pass++;
        
        while(j>=0 && temp <= arr[j])
        {
            arr[j+1] = arr[j];
            j = j-1;
            swaps++;
            comparisons++;
        }
        arr[j+1] = temp;
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

