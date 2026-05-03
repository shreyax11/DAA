#include <stdio.h>
#define MAX 10

/*
Max Heap → Largest at top
Swap → Move largest to end
Repeat → Sorted in ascending order
*/

void max_heapify(int a[], int i, int n)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    int temp;

    if (l < n && a[l] > a[largest])
        largest = l;

    if (r < n && a[r] > a[largest])
        largest = r;

    if (largest != i)
    {
        temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        max_heapify(a, largest, n);
    }
}

void create_max_heap(int a[], int n)
{
    for (int i = n/2 - 1; i >= 0; i--)
        max_heapify(a, i, n);
}

void heap_sort(int a[], int n)
{
    int i, temp;

    create_max_heap(a, n);

    for(i = n - 1; i >= 1; i--)
    {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        max_heapify(a, 0, i);
    }
}

void insert(int a[], int *n, int value)
{
    int i = *n;
    (*n)++;

    a[i] = value;

    while(i > 0 && a[(i - 1)/2] < a[i])
    {
        int temp = a[i];
        a[i] = a[(i - 1)/2];
        a[(i - 1)/2] = temp;

        i = (i - 1)/2;
    }
}

int delete_max(int a[], int *n)
{
    if(*n <= 0)
    {
        printf("Heap is empty\n");
        return -1;
    }

    int max = a[0];
    a[0] = a[*n - 1];
    (*n)--;

    max_heapify(a, 0, *n);

    return max;
}

void display(int a[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    int a[MAX];
    int n, i;
    int choice, val;

    printf("\n--- MAX HEAP OPERATIONS ---\n");

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    create_max_heap(a, n);

    do
    {
        printf("\n1.Insert\n2.Delete Max\n3.Heap Sort\n4.Display\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insert(a, &n, val);
                break;

            case 2:
                val = delete_max(a, &n);
                if(val != -1)
                    printf("Deleted max = %d\n", val);
                break;

            case 3:
                heap_sort(a, n);
                printf("Sorted array: ");
                display(a, n);
                break;

            case 4:
                printf("Heap elements: ");
                display(a, n);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while(choice != 5);

    return 0;
}