#include <stdio.h>
#define MAX 10

//Min Heapify
void min_heapify(int a[], int i, int n)
{
    int smallest, l, r, temp;

    smallest = i;
    l = 2*i + 1;
    r = 2*i + 2;

    if (l < n && a[l] < a[smallest])
        smallest = l;

    if (r < n && a[r] < a[smallest])
        smallest = r;

    if (smallest != i)
    {
        temp = a[i];
        a[i] = a[smallest];
        a[smallest] = temp;

        min_heapify(a, smallest, n);
    }
}

void create_min_heap(int a[], int n)
{
    for (int i = n/2 - 1; i >= 0; i--)
        min_heapify(a, i, n);
}

// Heap Sort (Min Heap)
void heap_sort(int a[], int n)
{
    int i, temp;

    create_min_heap(a, n);

    for(i = n - 1; i >= 1; i--)
    {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        min_heapify(a, 0, i);
    }
}

int main()
{
    int n, i;
    int a[MAX];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Original array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    heap_sort(a, n);

    printf("\nSorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}