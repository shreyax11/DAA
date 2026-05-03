// Multistage Graph
// multistage graph is a directed graph in which the vertices are divided into multiple stages, and edges 
//only connect vertices from one stage to the next. 
//The goal is to find the shortest path from the source vertex (in the first stage) to the destination vertex (in the last stage).
//complexity: O(n^2) where n is the number of vertices in the graph.

/*
Algorithm	            Starts From	        Direction       End to
Forward Multistage	    Destination	        Backward        Source
Backward Multistage	    Source	            Forward         Destination
*/

#include<stdio.h>
#define MAX 10

//Forward Algorithm: 
//In this approach, we start from the source vertex and move forward through the stages, 
//calculating the shortest path to each vertex in the next stage 
//until we reach the destination vertex.
//Approach : start from the last vertex (destination) and move backward toward the source vertex.


// Example of Forward Multistage Graph
// Stages: 0, 1, 2, 3

// Vertices in each stage:
// Stage 0 : A (Source)
// Stage 1 : B, C
// Stage 2 : D, E
// Stage 3 : F (Destination)

// Graph structure:
//        A
//      1/  \4
//      B    C
//    2/ \5 1/\3
//    D    E   F
//     \___1___/

// Edge costs:
// A -> B : 1
// A -> C : 4
// B -> D : 2
// B -> E : 5
// C -> E : 1
// C -> F : 3
// D -> F : 1
// E -> F : 2
// Possible paths and costs:
// A -> B -> D -> F = 1 + 2 + 1 = 4
// A -> B -> E -> F = 1 + 5 + 2 = 8
// A -> C -> F      = 4 + 3 = 7
// A -> C -> E -> F = 4 + 1 + 2 = 7
// Shortest path from A to F:
// A -> B -> D -> F
// Minimum cost = 4
void forward(int cost[MAX][MAX], int n)
{
    int i,j;
    int dist[MAX];

    for(i=0;i<n;i++)
        dist[i]=9999;

    dist[n-1]=0;   // destination cost F->F=0

    for(i=n-2;i>=0;i--)
    {
        for(j=i+1;j<n;j++)
        {
            if(cost[i][j]!=9999)
            {
                if(dist[i] > cost[i][j] + dist[j])
                {
                    dist[i] = cost[i][j] + dist[j];
                }
            }
        }
    }
    printf("Minimum cost from A to F = %d\n",dist[0]);
}

// Backward Algorithm:
// In this approach, we compute the minimum cost from the source to each vertex.
// The algorithm starts from the source vertex and moves forward through the stages
// until the destination vertex is reached.
//Example of Backward Multistage Graph
// Shortest path from A to F:
// A -> B -> D -> F = 1 + 2 + 1 = 4
// A -> B -> E -> F = 1 + 5 + 2 = 8
// A -> C -> F      = 4 + 3 = 7
// A -> C -> E -> F = 4 + 1 + 2 = 7
// Minimum cost from A to F = 4
void backward(int cost[MAX][MAX], int n)
{
    int i,j;
    int dist[MAX];

    for(i=0;i<n;i++)
        dist[i]=9999;

    dist[0]=0;   // source cost A->A=0

    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(cost[j][i]!=9999)
            {
                if(dist[i] > cost[j][i] + dist[j])
                {
                    dist[i] = cost[j][i] + dist[j];
                }
            }
        }
    }
    printf("Minimum cost from A to F = %d\n",dist[n-1]);
}

int main()
{
    int cost[MAX][MAX];
    int i,j,ch,n,e;
    int v1,v2,w;

    do{
        printf("\nMultistage Graph\n");
        printf("1. Forward Multistage\n");
        printf("2. Backward Multistage\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d",&ch);
        if(ch==1 || ch==2)
        {
            printf("Enter number of vertices: ");
            scanf("%d",&n);
            // Initialize matrix with infinity
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    if(i==j)
                        cost[i][j]=0;
                    else
                        cost[i][j]=9999;
                }
            }
            printf("Enter number of edges: ");
            scanf("%d",&e);
            printf("Enter edges (source destination cost):\n");
            for(i=0;i<e;i++)
            {
                scanf("%d %d %d",&v1,&v2,&w);
                cost[v1][v2]=w;
            }
            switch(ch)
            {
                case 1: forward(cost,n); break;
                case 2: backward(cost,n); break;
                case 3: printf("Exiting...\n"); break;
                default: printf("Invalid choice!\n");
            }
        }
    }while(ch!=3);
    return 0;
}