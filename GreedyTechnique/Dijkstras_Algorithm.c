#include <stdio.h>

#define MAX 10
#define INF 9999

int cost[MAX][MAX], dist[MAX], visited[MAX];

void dijkstra(int n, int start)
{
    int i, j, u, min;

    for(i = 0; i < n; i++) 
    {
        dist[i] = cost[start][i];
        visited[i] = 0;
    }

    visited[start] = 1;
    dist[start] = 0;

    for(i = 0; i < n - 1; i++) 
    {
        min = INF;
        for(j = 0; j < n; j++) 
        {
            if(visited[j] == 0 && dist[j] < min) 
            {
                min = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        for(j = 0; j < n; j++) 
        {
            if(visited[j] == 0 && dist[j] > dist[u] + cost[u][j]) 
            {
                dist[j] = dist[u] + cost[u][j];
            }
        }
    }
}

int main() 
{
    int n, i, j, start, edges, u, v, w;

    printf("Enter vertices: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(i == j)
                cost[i][j] = 0;
            else
                cost[i][j] = INF;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v weight):\n");
    for(i = 0; i < edges; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        cost[u][v] = w;
        cost[v][u] = w;   
    }

    printf("Enter start vertex: ");
    scanf("%d", &start);

    dijkstra(n, start);

    printf("\nShortest distances:\n");
    for(i = 0; i < n; i++)
        printf("%d -> %d = %d\n", start, i, dist[i]);

    return 0;
}