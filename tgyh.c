#include <stdio.h>
#include <stdlib.h>
typedef struct node // Creating a structure for the node of a linked list.
{
    int data;
    struct node *next;
} node;
node *create(node *, int[], int);
void scheduling(node *, int[], int);
int main()
{
    int n, i, a[100];
    node *head = NULL;
    printf("Enter the number of processes to be done by the processor\n");
    ;
    scanf("%d", &n);
    printf("Enter the time slot allocated to each process at a time\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    head = create(head, a, n);
    scheduling(head, a, n);
}

node *create(node *head, int a[], int n)
{
    node *p = NULL, *q = NULL;
    int i;
    for (i = 0; i < n; i++)
    {
        if (head == NULL)
        {
            p = (node *)malloc(sizeof(node));
            p->data = a[i];
            p->next = NULL;
            head = q = p;
        }
        else
        {
            p = (node *)malloc(sizeof(node));
            p->data = a[i];
            q->next = p;
            q = p;
            p->next = NULL;
        }
    }
    p->next = head;
    printf("%d \n", p->data);
    return head;
}

void scheduling(node *head, int a[], int n)
{
    node *p = NULL, *q = NULL;
    int t, i, j, c1 = 0, c2 = 0, c3 = 0;
    int max = 0, temp;
    printf("Enter the time taken by each process\n");
    scanf("%d", &t);

    p = q = head;
    do
    {
        if (max < p->data)
            max = p->data;
        p = p->next;
    } while (p != head);
    p = head;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    i = 0;
    while (c2 != (max / t))
    {
        if (c1 != n)
        {
            if (p->data != 0)
            {
                p->data = p->data - t;
                c3 = c3 + t;
                if (p->data == 0)
                {
                    printf("Execution time for %d is %d\n", a[i], c3);
                    i++;
                }
            }
            else
            {
                c3 = c3 + 0;
            }
            p = p->next;
            c1++;
        }
        else
        {
            c2++;
            c1 = 0;
        }
    }
    printf("The total time taken to execute the whole process by the single processor is %d", c3);
}
