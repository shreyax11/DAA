#include <stdio.h>
int max(int a, int b) 
{
    return (a > b) ? a : b;
}

int knapsack(int weights[], int profits[], int numberOfItems, int capacity) 
{

    int dp[capacity + 1][numberOfItems + 1];

    for (int w = 0; w <= capacity; w++)
        dp[w][0] = 0;   // no items

    for (int i = 0; i <= numberOfItems; i++)
        dp[0][i] = 0;   // zero capacity

    // Fill DP table
    for (int item = 1; item <= numberOfItems; item++) 
    {
        for (int currentCapacity = 1; currentCapacity <= capacity; currentCapacity++) 
        {

            // If item is too heavy
            if (weights[item] > currentCapacity) 
            {
                dp[currentCapacity][item] = dp[currentCapacity][item - 1];
            }
            // If item can be taken
            else 
            {
                int notTake = dp[currentCapacity][item - 1];
                int take = profits[item] + dp[currentCapacity - weights[item]][item - 1];

                dp[currentCapacity][item] = max(notTake, take);
            }
        }
    }

    return dp[capacity][numberOfItems];
}
int main() 
{
    int numberOfItems, capacity;

    printf("Enter number of items: ");
    scanf("%d", &numberOfItems);

    int weights[numberOfItems + 1], profits[numberOfItems + 1];

    printf("Enter weights:\n");
    for (int i = 1; i <= numberOfItems; i++)
        scanf("%d", &weights[i]);

    printf("Enter profits:\n");
    for (int i = 1; i <= numberOfItems; i++)
        scanf("%d", &profits[i]);

    printf("Enter capacity: ");
    scanf("%d", &capacity);

    int result = knapsack(weights, profits, numberOfItems, capacity);

    printf("Maximum Profit = %d\n", result);

    return 0;
}