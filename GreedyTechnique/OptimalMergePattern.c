#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int weight;
    struct node *left;
    struct node *right;
    struct node *next;
}node;

node* createnode(int w)
{
    node *nn = (node*)malloc(sizeof(node));
    nn->weight = w;
    nn->left = nn->right = NULL;
    nn->next = NULL;
    return nn;
}

void insertlist(node **head, node *nn)
{
    node *temp;

    if(*head == NULL || nn->weight < (*head)->weight)
    {
        nn->next = *head;
        *head = nn;
        return;
    }

    temp = *head;
    while(temp->next != NULL && temp->next->weight < nn->weight)
        temp = temp->next;

    nn->next = temp->next;
    temp->next = nn;
}

node* least(node **head)
{
    node *temp = *head;
    *head = (*head)->next;
    temp->next = NULL;
    return temp;
}

node* optimal_merge(node *head, int n)
{
    int i;
    node *nnode;

    for(i=1;i<=n-1;i++)
    {
        nnode = createnode(0);

        nnode->left = least(&head);
        nnode->right = least(&head);

        nnode->weight = nnode->left->weight + nnode->right->weight;

        insertlist(&head,nnode);
    }

    return least(&head);
}

int total_cost(node *root)
{
    if(root==NULL)
        return 0;

    return root->weight + total_cost(root->left) + total_cost(root->right);
}

int main()
{
    int n,i,w;
    node *head=NULL,*root;

    printf("Enter number of files: ");
    scanf("%d",&n);

    printf("Enter file sizes:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&w);
        insertlist(&head,createnode(w));
    }

    root = optimal_merge(head,n);

    printf("Optimal merge cost = %d\n", total_cost(root) - root->weight);

    return 0;
}
