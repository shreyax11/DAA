// Subset Sum Problem
//statement: 
//Given a set of positive integers and a target sum, 
//determine if there is a subset of the given set with a sum equal to the target sum.

//Pruning: The process of eliminating branches in a backtracking search tree that cannot lead to a valid solution.

#include <stdio.h>

int weights[20], choice[20];
int size, target;

void SumOfSubsets(int currSum, int index, int remaining)
{
    int i;

    if (currSum + weights[index] <= target)
    {
        choice[index] = 1;

        if (currSum + weights[index] == target)
        {
            printf("Subset: ");
            for(i = 0; i <= index; i++)
                if(choice[i] == 1)
                    printf("%d ", weights[i]);
            printf("\n");
        }
        else if(index + 1 < size && currSum + weights[index] + weights[index+1] <= target)
        {
            SumOfSubsets(currSum + weights[index], index + 1, remaining - weights[index]);
        }
    }

    if(index + 1 < size && (currSum + remaining - weights[index] >= target) && (currSum + weights[index+1] <= target))
    {
        choice[index] = 0;
        SumOfSubsets(currSum, index + 1, remaining - weights[index]);
    }
}

int main()
{
    int i, remaining = 0;

    printf("Enter number of elements: ");
    scanf("%d", &size);

    printf("Enter weights (in increasing order):\n");
    for(i = 0; i < size; i++)
    {
        scanf("%d", &weights[i]);
        remaining += weights[i];
    }

    printf("Enter target sum: ");
    scanf("%d", &target);

    SumOfSubsets(0, 0, remaining);

    return 0;
}