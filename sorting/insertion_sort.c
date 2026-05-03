//insertion sort:
#include<stdio.h>
void insertion_sort(int a[10],int n)
{
	int i,j,k,item;
	printf("%d ",a[0]);
	for(i=1;i<n;i++)
	{
		item=a[i];
		for(j=i-1;j>=0;j--)
		{
			if(a[j]>item)
			{
				a[j+1]=a[j];
			}
			else
				break;
		}
		a[j+1]=item;

		printf("\n");
		// for(k=0;k<=i;k++)
		// 	printf("%d ",a[k]);
		
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
	printf("\nsorting the array ....\n");
	insertion_sort(a,n);
	printf("\n\nSorted array is :\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	return 1;
}