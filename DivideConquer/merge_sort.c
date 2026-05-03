//merger sort using divide and conquer
#include<stdio.h>
#define SIZE 10
int b[20];
void merge(int a[], int low, int mid, int high)
{
    int i, j, h;
    i=low;
    h=low;
    j=mid+1;
    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
        {
            b[h]=a[i];
            i++;
        }
        else
        {
            b[h]=a[j];
            j++;
        }
        h++;
    }
    while(i <= mid)
    {
        b[h]=a[i];
        i++;
        h++;
    }
    while(j <= high)
    {
        b[h]= a[j];
        j++;
        h++;
    }
    for(int i=low; i<=high; i++)
        a[i]=b[i];
}

void mergesort( int a[], int low, int high)
{
    int mid=0;
    if(low<high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid, high);
    }
}
int main()
{
    int i,n;
    printf("enter the no. of elements in the array:");
    scanf("%d",&n);
    //printf("entered value of n is %d\n", n);
    int a[SIZE];
    printf("enter the elements:\n");
    if(n<=SIZE)
    {
        for(i=0; i<n; i++)
            scanf("%d",&a[i]);

        mergesort(a, 0, n-1);   

        printf("sorted array is:\n");
        for(i=0; i<n; i++)
            printf("%d ", a[i]);
    }
    else
    {
        printf("array size should be less than or equal to %d", SIZE);
    }
    return 0;
}