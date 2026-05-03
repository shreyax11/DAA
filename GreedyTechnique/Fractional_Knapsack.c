//greedy method for fractional knapsack problem

#include <stdio.h>
#define MAX 20
typedef struct item
{
    int id;
    float w;   // weight
    float p;   // profit
} Item;


// Sorting items in decreasing order of p/w
void sort(Item obj[], int n)
{
    int i, j;
    Item temp;
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if((obj[i].p / obj[i].w) < (obj[j].p / obj[j].w))
            {
                temp = obj[i];
                obj[i] = obj[j];
                obj[j] = temp;
            }
        }
    }
}

float Knapsack(Item obj[], int n, float m)
{
    float solvec[MAX];     // solution vector
    float U;          // capacity
    float Profit = 0;
    int i;

    // Step 2: initialize solution vector
    for(i = 0; i < n; i++)
        solvec[i] = 0;

    U = m;      //remaining capacity

    for(i = 0; i < n; i++)
    {
        if(obj[i].w <= U)
        {
            solvec[i] = 1;
            U = U - obj[i].w;
        }
        else
        {
            solvec[i] = U / obj[i].w;
            U = 0;
            break;
        }
    }
    for(i = 0; i < n; i++)
        Profit += obj[i].p * solvec[i];
    printf("\nSolution Vector:\n");
    for(i = 0; i < n; i++)
        printf("Item %d : %f\n", obj[i].id, solvec[i]);

    return Profit;
}


int main()
{
    Item obj[MAX];
    int n, i;
    float m;
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter knapsack capacity: ");
    scanf("%f", &m);
    for(i = 0; i < n; i++)
    {
        printf("Enter id, weight and profit: ");
        scanf("%d %f %f", &obj[i].id, &obj[i].w, &obj[i].p);
    }
    sort(obj, n);
    printf("\nMaximum Profit = %f\n", Knapsack(obj, n, m));
    return 0;
}