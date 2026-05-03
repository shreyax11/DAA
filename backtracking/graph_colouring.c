/*

Graph Coloring :
means assigning colors to vertices (nodes) of a graph such that:
No two adjacent vertices have the same color.
Only m colors are allowed.


Optimization Problem:
Find the minimum number of colors required to color the graph.
This minimum number is called:
Chromatic Number

Degree Rule:
If a graph has maximum degree = d
Then it can always be colored using:
d + 1 colors

Planar Graph:
A graph is planar if it can be drawn without edges crossing.

4 Color Problem:
Question:
Can every map be colored with only 4 colors?
Rule:
Adjacent regions must have different colors
** Any planar map can be colored with at most 4 colors

*/

#include <stdio.h>

int x[10];        // stores color of vertices
int g[10][10];    // adjacency matrix
int n, m;         // n = vertices, m = colors

void nextValue(int k)
{
    int j;

    while(1)
    {
        x[k] = (x[k] + 1) % (m + 1);   // try next color

        if(x[k] == 0)
            return;

        for(j = 1; j <= n; j++)
        {
            if(g[k][j] != 0 && x[k] == x[j])
                break;                // same color as adjacent vertex
        }

        if(j == n + 1)
            return;                  // valid color found
    }
}

void mColoring(int k)
{
    while(1)
    {
        nextValue(k);

        if(x[k] == 0)
            return;//No valid color found for vertex k → backtrack.

        if(k == n)//All vertices are colored.
        {
            for(int i = 1; i <= n; i++)
                printf("%d ", x[i]);

            printf("\n");
        }
        else
        {
            mColoring(k + 1);
        }
    }
}

int main()
{
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%d", &g[i][j]);

    printf("Enter number of colors: ");
    scanf("%d", &m);

    for(int i = 1; i <= n; i++)
        x[i] = 0;

    mColoring(1);

    return 0;
}