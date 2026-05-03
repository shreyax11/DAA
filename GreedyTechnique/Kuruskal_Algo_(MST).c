//kurushkal's algorithm for minimum spanning tree
#include <stdio.h>

#define MAX 100

typedef struct edge
{
    int u, v, weight;
}Edge;

Edge heap[MAX];
int heap_size = 0;

int parent[MAX];

int find(int i)
{
    while (parent[i] >= 0)
        i = parent[i];
    return i;
}

void union_set(int i, int j)
{
    parent[j] = i;
}


void min_heapify(int i)
{
    int smallest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= heap_size && heap[left].weight < heap[smallest].weight)
        smallest = left;

    if (right <= heap_size && heap[right].weight < heap[smallest].weight)
        smallest = right;

    if (smallest != i)
    {
        Edge temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;

        min_heapify(smallest);
    }
}

void create_min_heap()
{
    for (int i = heap_size / 2; i >= 1; i--)
        min_heapify(i);
}

void insert_min_heap(Edge item)
{
    heap_size++;
    int i = heap_size;

    while (i > 1 && heap[i / 2].weight > item.weight)
    {
        heap[i] = heap[i / 2];
        i = i / 2;
    }

    heap[i] = item;
}

Edge delete_min()
{
    Edge min = heap[1];
    heap[1] = heap[heap_size];
    heap_size--;
    min_heapify(1);
    return min;
}


// -------- KRUSKAL --------
void kruskal(int n)
{
    Edge result[MAX];
    int count = 0, mincost = 0;

    for (int i = 0; i < n; i++)
        parent[i] = -1;

    create_min_heap();

    while (count < n - 1 && heap_size > 0)
    {
        Edge e = delete_min();

        int j = find(e.u);
        int k = find(e.v);

        if (j != k)
        {
            result[count++] = e;
            mincost += e.weight;
            union_set(j, k);
        }
    }

    if (count != n - 1)
    {
        printf("No Minimum Spanning Tree\n");
        return;
    }

    printf("\nEdges in MST:\n");
    for (int i = 0; i < count; i++)
        printf("%d -- %d == %d\n",
               result[i].u,
               result[i].v,
               result[i].weight);

    printf("Total Minimum Cost = %d\n", mincost);
}



int main()
{
    int n, e;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v weight):\n");

    for (int i = 0; i < e; i++)
    {
        Edge temp;
        scanf("%d %d %d", &temp.u, &temp.v, &temp.weight);
        insert_min_heap(temp);
    }

    kruskal(n);

    return 0;
}