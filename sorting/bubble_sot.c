//bubble sort:
#include<stdio.h>
void bubble_sort(int a[10],int n)
{
	int i, j,k,temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
		printf("\n pass -> %d\t",i+1);
		for(j=0;j<n;j++)
			printf("%d ",a[j]);
		
	}
}
int main()
{
	int a[10];
	int n,i;
	printf("enter the total number of elements you want in an array:\n");
	scanf("%d",&n);
	printf("enter %d elements...\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	//call sorting function
	printf("\nsorting the array ....\n");
	printf("steps are :");
	bubble_sort(a,n);
	printf("\n\nSorted array is :\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	return 1;
}