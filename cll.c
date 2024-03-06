#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int info;
    struct node *next;
} nd;

nd *createlist(nd *right)
{
    nd *p = (nd *)malloc(sizeof(nd));
    printf("enter value in node\n");
    scanf("%d", &p->info);

    if (right == NULL)
    {
        right = p;
        right->next = right;
    }
    else
    {
        p->next = right->next;
        right->next = p;
        right = p;
    }
    return right;
}

void display(nd *left)
{
    nd *temp = left;
    do
    {
        printf("%d ", left->info);
        left = left->next;
    } while (left != temp);
}

void compare(nd *left, int key)
{
    int ctr = 0;
    nd *temp = left;
    do
    {
        if (left->info < key)
            ctr++;
        left = left->next;

    } while (left != temp);
    printf("no of nodes having values less than %d = %d ", key, ctr);
}
int main()
{
    nd *left, *right;
    left = NULL;
    right = NULL;
    int choice, key,ch;
    do
    {
        printf("enter choice for switch\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            right = createlist(right);
            if (left == NULL)
                left = right;
            break;
        case 2:
            display(left);
            break;
        case 4:
            printf("enter key\n");
            scanf("%d ", &key);
            compare(left, key);
            break;
        case 404 : exit(0);
        }
        printf("do you want to continue\n");
        scanf("%d",&ch);

    } while (ch==1);
}