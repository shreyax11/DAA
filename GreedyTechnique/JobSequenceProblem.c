// Job Sequencing Problem
/*

Algorithm JS(d, j, n)

// d → deadline array
// j → subset of selected jobs
// n → total number of jobs
// Jobs are sorted such that p[1] ≥ p[2] ≥ ... ≥ p[n]
// j[i] stores the ith job in optimal solution

{
    d[0] = j[0] = 0;
    j[1] = 1;
    k = 1;

    for i = 2 to n do
    {
        r = k;

        while ((d[j[r]] > d[i]) AND (d[j[r]] ≠ r)) do
            r = r - 1;

        if ((d[j[r]] ≤ d[i]) AND (d[i] > r)) then
        {
            for q = k down to r + 1 do
                j[q + 1] = j[q];

            j[r + 1] = i;
            k = k + 1;
        }
    }

    return k;
}

*/

#include <stdio.h>

typedef struct 
{
    int id, profit, deadline;
} Job;

void sort(Job jobs[], int n) 
{
    for(int i = 0; i < n-1; i++) 
    {
        for(int j = i+1; j < n; j++) 
        {
            if(jobs[i].profit < jobs[j].profit) 
            {
                Job temp = jobs[i];
                jobs[i] = jobs[j];
                jobs[j] = temp;
            }
        }
    }
}

void sequence(Job jobs[], int n) 
{
    int slot[10] = {0};
    int totalProfit = 0;
    int countJobs = 0;

    for(int i = 0; i < n; i++) 
    {
        for(int j = jobs[i].deadline - 1; j >= 0; j--) 
        {
            if(slot[j] == 0)
            {
                slot[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                countJobs++;
                break;
            }
        }
    }

    printf("\nSelected Jobs: ");
    for(int i = 0; i < n; i++) 
    {
        if(slot[i] != 0)
            printf("J%d ", slot[i]);
    }

    printf("\nTotal Jobs Selected = %d", countJobs);
    printf("\nTotal Profit = %d\n", totalProfit);
}

int main() 
{
    int n;
    printf("Enter number of jobs: ");
    scanf("%d", &n);

    Job jobs[10];

    printf("Enter id, profit, deadline:\n");
    for(int i = 0; i < n; i++) 
        scanf("%d %d %d", &jobs[i].id, &jobs[i].profit, &jobs[i].deadline);

    sort(jobs, n);
    sequence(jobs, n);

    return 0;
}