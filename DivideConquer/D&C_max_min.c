//divide and conquer approach to find the maximum and minimum element in an array

#include<stdio.h>
#define size 10
void max_min(int a[size],int low,int high,int *max,int *min)
{
	int mid;
	int max1;
	int min1;
	if(low==high)
		*max=*min=a[low];
	else if(low==high-1)
	{
		if(a[low]>a[high])
		{
			*max=a[low];
			*min=a[high];
		}
		else
		{
			*max=a[high];
			*min=a[low];
		}
	}
	else
	{
		mid=(low+high)/2;
		max_min(a,low,mid,max,min);
		max_min(a,mid+1, high, &max1, &min1);
		if(min1 < *min)
			*min=min1;
		if(max1 > *max)
			*max=max1;
	}
}
void main()
{
	int min=0;
	int max=0;
	int n;
	int a[size];
	printf("enter the no. of elements in the array:");
	scanf("%d",&n);
	printf("enter the elements:\n");
	for(int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	max_min(a,1,n,&max,&min);
	printf("the maximum value is %d\n", max);
	printf("the minimum value is %d", min);
}