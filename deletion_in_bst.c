#include <stdio.h>
#include <stdlib.h>
int ctr = 0;

typedef struct node
{
    struct node *left;
    int data;
    struct node *right;

} tree;
tree *create_node(int a)
{
    tree *new_node = (tree *)malloc(sizeof(tree));
    new_node->data = a;
    new_node->left = new_node->right = NULL;
    return new_node;
}
void insert_node_bst(tree **root, tree *new_node)
{
    if (*root == NULL)
    {
        *root = new_node;
    }
    else
    {
        if (new_node->data < (*root)->data)
        {
            insert_node_bst(&(*root)->left, new_node);
        }
        else
        {
            insert_node_bst(&(*root)->right, new_node);
        }
    }
}
void display(tree *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        display(root->left);
        printf("%d ==> ", root->data);
        display(root->right);
    }
}
void displaypost(tree *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        display(root->left);
        display(root->right);
        printf("%d ==> ", root->data);
    }
}
void count(tree *root, int *counter)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        count(root->left, counter);
        (*counter)++;
        count(root->right, counter);
    }
}
void countone(tree *root, int *counter1)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        countone(root->left, counter1);
        if ((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL))
            (*counter1)++;
        countone(root->right, counter1);
    }
}
void countnone(tree *root, int *counter1)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        countnone(root->left, counter1);
        if (root->left == NULL && root->right == NULL)
            (*counter1)++;
        countnone(root->right, counter1);
    }
}
void search(tree *root, int key)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        search(root->left, key);
        if (root->data == key)
        {
            printf("search found\n");
            return;
        }

        search(root->right, key);
    }
}

tree *inorderpredecessor(tree *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
tree *inordersuccessor(tree *root)
{
    root = root->right;
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

tree *delete(tree *root, int n)
{
    tree *ipre, *isuc;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    if (n < root->data)
    {
        root->left = delete (root->left, n);
    }
    else if (n > root->data)
        root->right = delete (root->right, n);
    else
    {
        if (root->left != NULL)
        {
            ipre = inorderpredecessor(root);
            root->data = ipre->data;
            root->left = delete (root->left, ipre->data);
        }
        else if (root->right != NULL)
        {
            isuc = inordersuccessor(root);
            root->data = isuc->data;
            root->right = delete (root->right, isuc->data);
        }
    }
    ctr++;
    return root;
}

int height(tree *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int left_height = height(root->left);
         printf("%d->\n ", left_height);
                //printf("%d-> ", root->data);


        int right_height = height(root->right);
                printf("%d \n", right_height);
                    //printf("%d-> ", root->data);

        if (left_height >= right_height)
        {
            return left_height + 1;
        }
        else
        {
            return right_height + 1;
        }
    }
}
int main()
{
    tree *root = NULL, *new_node = NULL;
    int a[] = {100, 50, 200, 40, 70, 150, 60, 170}, counter = 0, counter1 = 0, counter2 = 0, key = 100, val = 0;
    ;
    for (int i = 0; i < 8; i++)
    {
        new_node = create_node(a[i]);
        insert_node_bst(&root, new_node);
    }

    display(root);
    printf("\n");
    count(root, &counter);
    countone(root, &counter1);
    countnone(root, &counter2);
    search(root, key);
    printf("total nodes = %d\n ", counter);
    printf("one child nodes = %d\n ", counter1);
    printf("no child nodes = %d\n", counter2);
    // delete (root, 200);
    //  delete (root, 70);
    display(root);
    // printf("\n%d",ctr);
    printf("\n");
    displaypost(root);
    printf("\n");

    val = height(root);
    printf("\nheight of bst is = %d", val);
}
