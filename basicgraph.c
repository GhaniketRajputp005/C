#include <stdio.h>
#include <stdlib.h>
typedef struct nodetype
{
    int data;
    struct nodetype *next;
} node;
node *create_node()
{
    node *p = NULL;
    int val;
    p = (node *)malloc(sizeof(node));
    printf("Enter value of adjacent node/vertex\n ");
    scanf("%d", &val);
    p->data = val;
    p->next = NULL;
    return p;
}
void create_graph(node *vertex[], int no_vertex)
{
    
    int num_nodes;
    node *p = NULL, *temp = NULL;
    for (int i = 0; i < no_vertex; i++)
    {
        temp = vertex[i];
        printf("Enter no of nodes for vertex %d", i + 1);
        scanf("%d", &num_nodes);
        for (int j = 1; j <= num_nodes; j++)
        {
            p = create_node();
            temp->next = p;
            temp = p;
        }
        //temp = temp->next;
    }
}
void print(node*vertex[],int no_vertex)
{
    for(int i=0;i<no_vertex;i++)
    {
        node*temp = vertex[i];
       
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp = temp-> next;
            if(temp==NULL)
            {
                printf("NULL des==>\n");
            }
        }
        printf("\n");

    }
}
int main()
{
    int no_vertex;
    node *vertex[100],*p;
    printf("enter total number of vertex\n");
    scanf("%d", &no_vertex);
    printf("assigning value to all vertex initially\n");
    for (int i = 0; i < no_vertex; i++)
    {
        p = create_node();
        vertex[i]= p;
    }
    create_graph(vertex, no_vertex);
    print(vertex,no_vertex);
}
