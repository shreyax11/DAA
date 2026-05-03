//linear search
#include<stdio.h>
int linear_search(int a[10], int n, int key)
{
	int j;
	j=0;
	for(j=0;j<n;j++)
	{
		if(a[j]==key)
			return(j);
	}
	return -1;
}

int main()
{
	int a[10];
	int n,i,key,b;
	printf("enter the total number of elements you want in an array:\n");
	scanf("%d",&n);
	printf("enter %d elements...\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	//calling searching function
	printf("\nEnter the element to search:");
	scanf("%d",&key);
	b=linear_search(a,n,key);
	if(b==-1)
		printf("element not found\n");
	else
		printf("element found");
	return 1;
}