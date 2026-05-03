#include <stdio.h>

//  Divide & Conquer Binary Search
int binarySearch(int arr[], int low, int high, int key) 
{
    if(low <= high) 
    {
        int mid = (low + high) / 2;

        if(arr[mid] == key)
            return mid;

        else if(key < arr[mid])
            return binarySearch(arr, low, mid - 1, key);

        else
            return binarySearch(arr, mid + 1, high, key);
    }
    return -1;
}

//  Selection Sort 
void selectionSort(int arr[], int n) 
{
    int i, j, min, temp;

    for(i = 0; i < n - 1; i++) 
    {
        min = i;
        for(j = i + 1; j < n; j++) 
        {
            if(arr[j] < arr[min])
                min = j;
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int main() 
{
    int n, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[100];

    printf("Enter elements (unsorted):\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    selectionSort(arr, n);

    printf("Sorted array: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\nEnter element to search: ");
    scanf("%d", &key);

    int result = binarySearch(arr, 0, n - 1, key);

    if(result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}