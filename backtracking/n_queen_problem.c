#include <stdio.h>
#include <math.h>

int place(int x[], int k, int i)
{
    for(int j=1; j<=k-1; j++)
    {
        if(x[j]==i || abs(j-k)==abs(x[j]-i))
            return 0;
    }
    return 1;
}

void nqueen(int x[], int k, int n)
{
    for(int i=1;i<=n;i++)
    {
        if(place(x,k,i))
        {
            x[k]=i;

            if(k==n)
            {
                for(int j=1;j<=n;j++)
                    printf("%d ",x[j]);
                printf("\n");
            }
            else
            {
                nqueen(x,k+1,n);
            }
        }
    }
}

int main()
{
    int n;
    int x[20];

    printf("Enter number of queens: ");
    scanf("%d",&n);

    nqueen(x,1,n);

    return 0;
}