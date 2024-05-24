// Selection Sort

#include <stdio.h>

int main()
{
    int arr[] = {5,4,3,2,1};
    
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int temp = 0, comparisons=0, swaps=0, pass=0;
    
    int min; 
    int index;
    
    for(int i=0; i<n-1; i++)
    {
        min = arr[i];
        index = i;
        pass++;
        for(int j=i+1; j<n; j++)
        {
            comparisons++;
            if(min > arr[j])
            {
                min = arr[j]; 
                index = j;
            }
        }
        
        if(index != i) 
        {
            temp = arr[i];
            arr[i] = min;
            arr[index] = temp; 
            swaps++;    
        }
    }
    
    for(int k = 0; k<n; k++)
    {
        printf("%d ", arr[k]);
    }
    
    printf("\nNumber of passes: %d", pass);
    printf("\nNumber of Comparisons: %d",comparisons);
    printf("\nNumber of Swaps: %d\n", swaps);
    
    return 0;
}

