//selection sort:
 #include<stdio.h>
// void selection_sort(int a[10],int n)
// {
// 	int i, j,b,temp,small;
// 	for(i=0;i<n-1;i++)
// 	{
// 		small=a[i];
// 		b=i;
// 		for(j=i+1;j<n;j++)
// 		{
// 			if(a[j]<small)
// 			{
// 				small=a[j];
// 				b=j;
// 			}
// 		}
// 		if(b!=i)
// 		{
// 			temp=a[i];
// 			a[i]=a[b];
// 			a[b]=temp;
// 		}
// 		printf("\n");
// 		for(j=0;j<n;j++)
// 			printf("%d ",a[j]);
		
// 	}
// }
// int main()
// {
// 	int a[10];
// 	int n,i;
// 	printf("enter the total number of elements you want in an array:\n");
// 	scanf("%d",&n);
// 	printf("enter %d elements...\n",n);
// 	for(i=0;i<n;i++)
// 		scanf("%d",&a[i]);
// 	//call sorting function
// 	printf("sorting the array ....\n");
// 	printf("steps are :");
// 	selection_sort(a,n);
// 	printf("\nSorted array is :\n");
// 	for(i=0;i<n;i++)
// 		printf("%d ",a[i]);
// 	return 1;
// }
void selectionsort(int a[10], int n)
{
	int i, j, small, temp;
	for(i=0;i<n-1;i++)
	{
		small=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[small])
				small=j;
		}
		if(small!=i)
		{
			temp=a[i];
			a[i]=a[small];
			a[small]=temp;
		}
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
	selectionsort(a,n);
	printf("Sorted array is :\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
}