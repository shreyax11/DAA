#include<stdio.h>
//Last Element is Pivot 
//indexing starts from 0
int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low;
    int j = high - 1;
    int temp;

    while(i <= j)
    {
        while(i <= j && a[i] <= pivot)
            i++;

        while(i <= j && a[j] > pivot)
            j--;

        if(i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    temp = a[j+1];
    a[j+1] = a[high];
    a[high] = temp;

    return j+1;
}

void quicksort(int a[], int low, int high)
{
    if(low < high)
    {
        int p = partition(a, low, high);
        quicksort(a, low, p - 1);
        quicksort(a, p + 1, high);
    }
}

int main() 
{
    int n, arr[10];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    quicksort(arr, 0, n - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}