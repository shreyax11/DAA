#include<stdio.h>
//middle element as pivot
int partition(int arr[10], int low, int high)
{
    int pivot, l, r, mid, temp;

    mid = (low + high) / 2;
    pivot = arr[mid];

    l = low;
    r = high;

    while(l <= r)
    {
        while(arr[l] < pivot)
            l++;

        while(arr[r] > pivot)
            r--;

        if(l <= r)
        {
            temp = arr[l];
            arr[l] = arr[r];
            arr[r] = temp;
            l++;
            r--;
        }
    }

    return l;
}

void quicksort(int arr[10], int low, int high)
{
    int p;

    if(low < high)
    {
        p = partition(arr, low, high);

        quicksort(arr, low, p - 1);
        quicksort(arr, p, high);
    }
}

int main()
{
    int n, i, arr[10];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Array before sorting:\n");
    for(i = 0; i < n; i++)
        printf("%d\t", arr[i]);

    quicksort(arr, 0, n - 1);

    printf("\nSorted array:\n");
    for(i = 0; i < n; i++)
        printf("%d\t", arr[i]);

    return 0;
}