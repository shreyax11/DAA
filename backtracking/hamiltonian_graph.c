// Hamiltonian Graph Problem
// Hamiltonian cycle is a cycle in a graph that visits each vertex exactly once and returns to the starting edge.

#include <stdio.h>

int x[20];
int G[20][20];
int n;

void NextValue(int k)
{
    int j;

    while(1)
    {
        x[k] = (x[k] + 1) % (n + 1);

        if(x[k] == 0)
            return;

        if(G[x[k-1]][x[k]] != 0)
        {
            for(j = 1; j < k; j++)
            {
                if(x[j] == x[k])
                    break;
            }

            if(j == k)
            {
                if(k < n || (k == n && G[x[n]][x[1]] != 0))
                    return;
            }
        }
    }
}

void Hamiltonian(int k)
{
    while(1)
    {
        NextValue(k);

        if(x[k] == 0)
            return;

        if(k == n)
        {
            for(int i = 1; i <= n; i++)
                printf("%d ", x[i]);

            printf("%d\n", x[1]);
        }
        else
        {
            Hamiltonian(k + 1);
        }
    }
}

int main()
{
    int edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    /* initialize matrix with 0 */
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            G[i][j] = 0;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter vertices (u v) which has edge:\n");

    for(int i = 1; i <= edges; i++)
    {
        scanf("%d %d", &u, &v);
        G[u][v] = 1;
        G[v][u] = 1;   // because graph is undirected
    }

    for(int i = 1; i <= n; i++)
        x[i] = 0;

    x[1] = 1;

    Hamiltonian(2);

    return 0;
}