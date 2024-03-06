#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *leftchild;
    int info;
    struct node *rightchild;
} tree;

int main()
{
}

void insertnode(tree **root)
{
    tree *temp = *root;
    tree *p = (tree *)malloc(sizeof(tree));
    scanf("%d", &p->info);

    if (p != NULL)
    {
        if (p->info < temp->info)
        {
            if (temp->leftchild == NULL)
                temp->leftchild = p;
            else
                insertnode(temp->leftchild);
        }
        else
        {
            if (temp->rightchild == NULL)
                temp->rightchild = p;
            else
                insertnode(temp->rightchild);
        }

        p->leftchild = NULL;
        p->rightchild = NULL;
    }
}