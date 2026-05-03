#include<stdio.h>

// taking any index from user as pivot
// and swapping it with first element, then applying quicksort

int partition(int arr[10], int low, int high)
{
    int pivot, l, r, temp, pivotIndex;

    printf("Enter pivot index (%d to %d): ", low, high);
    scanf("%d", &pivotIndex);

    if(pivotIndex < low || pivotIndex > high)
    {
        printf("Invalid index! Using %d as pivot.\n", low);
        pivotIndex = low;
    }

    if(pivotIndex != low)
    {
        temp = arr[low];
        arr[low] = arr[pivotIndex];
        arr[pivotIndex] = temp;
    }

    pivot = arr[low];

    l = low + 1;
    r = high;

    while(l <= r)
    {
        while(l <= high && arr[l] <= pivot)
            l++;

        while(arr[r] > pivot)
            r--;

        if(l < r)
        {
            temp = arr[l];
            arr[l] = arr[r];
            arr[r] = temp;
        }
    }

    temp = arr[low];
    arr[low] = arr[r];
    arr[r] = temp;

    return r;
}

void quicksort(int arr[10], int low, int high)
{
    int p;

    if(low < high)
    {
        p = partition(arr, low, high);

        quicksort(arr, low, p - 1);
        quicksort(arr, p + 1, high);
    }
}

int main()
{
    int n, i, arr[10];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if(n > 10)
    {
        printf("Max size is 10\n");
        return 0;
    }

    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    quicksort(arr, 0, n - 1);

    printf("Sorted array:\n");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}