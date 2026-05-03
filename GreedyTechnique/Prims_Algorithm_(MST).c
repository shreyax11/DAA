//minimum spanning tree using prims algorithm

#include <stdio.h>
#define MAX 10
#define INF 9999    //  means no edge between the vertices

//  cost[][] is the adjacency matrix which conatin the weight of the edges. 
//  n is the number of vertices in the graph
//  t[][2] is the array to store the edges of the minimum spanning tree
//  mincost is used to add the edges whose cost is minimum and to calculate the total cost of the minimum spanning tree
//  k is used to store the vertex which is added to the minimum spanning tree
//  l is used to store the vertex which is connected to k with minimum cost edge
//  near[] is used to store the nearest vertex in the minimum spanning tree for each vertex which is not yet included in the minimum spanning tree
//  if near is 0 means that the vertex is included in the minimum spanning tree otherwise it is not included in the minimum spanning tree


/*

Algorithm Prim (E, cost, n,t)
// E is the set of edges in G. Cost (1:n, 1:n) is the
// Cost adjacency matrix of an n vertex graph such that
// Cost (i,j) is either a positive real no. or ∞ if no edge (i,j) exists.
//A minimum spanning tree is computed and
//Stored in the array T(1:n-1, 2).
//(t (i, 1), + t(i,2)) is an edge in the minimum cost spanning tree. The final cost is returned
{
Let (k, l) be an edge with min cost in E
Min cost: = Cost (x,l);
T(1,1):= k; + (1,2):= l;

for i:= 1 to n do    //initialize near
if (cost (i,l)<cost (i,k) then n east (i): l;
else near (i): = k;
near (k): = near (l): = 0;

for i: = 2 to n-1 do
{   

//find n-2 additional edges for t
let j be an index such that near (i) 0 & cost (j, near (i)) is minimum;
t (i,1): = j + (i,2): = near (j);
min cost: = Min cost + cost (j, near (j));
near (j): = 0;

for k:=1 to n do // update near ()
    if ((near (k) 0) and (cost {k, near (k)) > cost (k,j)))
        then near Z(k): = ji
}
return mincost;
}

*/
void prim(int cost[MAX][MAX], int n)
{
    int i, j, k = 0, l = 0;
    int near[MAX];
    int t[MAX][2];
    int mincost = 0;
    int min = INF;

    //  Finding the minimum cost edge
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(i != j && cost[i][j] < min)
            {
                min = cost[i][j];
                k = i;
                l = j;
            }
        }
    }

    //  Adding first edge
    t[0][0] = k;
    t[0][1] = l;
    mincost = cost[k][l];

    for(i = 0; i < n; i++)
    {
        if(cost[i][k] < cost[i][l])
            near[i] = k;
        else
            near[i] = l;
    }

    near[k] = -1;   // included in MST
    near[l] = -1;   // included in MST

    //  Selecting remaining n-2 edges
    for(i = 1; i < n - 1; i++)
    {
        min = INF;
        for(j = 0; j < n; j++)
        {
            if(near[j] != -1 && cost[j][near[j]] < min)
            {
                min = cost[j][near[j]];
                k = j;
            }
        }
        t[i][0] = k;
        t[i][1] = near[k];
        mincost += cost[k][near[k]];
        near[k] = -1;
        for(j = 0; j < n; j++)
        {
            if(near[j] != -1 && cost[j][k] < cost[j][near[j]])
                near[j] = k;
        }
    }
    printf("\nEdges in MST:\n");
    for(i = 0; i < n - 1; i++)
        printf("%d - %d\n", t[i][0], t[i][1]);
    printf("Minimum Cost = %d\n", mincost);
}

int main()
{
    int cost[MAX][MAX];
    int n, i, j;
    int edges, u, v, w;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initializeing cost matrix
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(i == j)  // As cost of self loop is 0
                cost[i][j] = 0;
            else
                cost[i][j] = INF;
        }
    }
    printf("How many edges have cost? ");
    scanf("%d", &edges);
    for(i = 0; i < edges; i++)
    {
        printf("\nEnter vertices (u v): ");
        scanf("%d %d", &u, &v);
        printf("Enter cost of %d - %d: ", u, v);
        scanf("%d", &w);
        cost[u][v] = w;
        cost[v][u] = w;   // undirected graph
    }
    prim(cost, n);
    return 0;
}
