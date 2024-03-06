#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node * left;
    int info;
    struct node * right;
}tree;

tree * createnode()
{
    tree * p = (tree*)malloc(sizeof(tree));
    printf("enter value to insert in node\n");
    scanf("%d",&p->info);
    p->left = p->right = NULL;
    return p;
}


void insertbst(tree ** root, tree * p)
{
    if(*root==NULL)
    {
        *root = p;
        return;
    }
    else
    {
        if(p->info<(*root)->info)
        {
            insertbst(&(*root)->left,p);
        }
        else
        {
            
            insertbst(&(*root)->right,p);
        }
    }
}

void preorder(tree * root)
{
    if(root == NULL)
    {
        return;
    }
    else{

        printf("%d ",root->info);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(tree * root)
{
    if(root == NULL)
    {
        return;
    }
    else{

        inorder(root->left);
        printf("%d ",root->info);
        inorder(root->right);
    }
}

void postorder(tree * root)
{
    if(root == NULL)
    {
        return;
    }
    else{

        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->info);
    }
}

void totalnodes(tree * root, int * nodectr)
{
    if(root == NULL)
    {
        return;
    }
    else{

        totalnodes(root->left,nodectr);
        (*nodectr)++;
        totalnodes(root->right,nodectr);
        
    }
}

void leafnodes(tree * root, int * leafnodectr)
{
    if(root == NULL)
    {
        return;
    }
    else{

        leafnodes(root->left,leafnodectr);
        if(root->left == NULL&&root->right == NULL)
        {
            (*leafnodectr)++;
        }
        leafnodes(root->right,leafnodectr);
        
    }
}

void onechildnode(tree * root, int * onectr)
{
    if(root == NULL)
    {
        return;
    }
    else{

        onechildnode(root->left,onectr);
        if(root->left == NULL&&root->right != NULL || root->left != NULL&&root->right == NULL)
        {
            (*onectr)++;
        }
        onechildnode(root->right,onectr);
        
    }
}

void biggestnode(tree * root,int * max)
{

    if(root == NULL)
    {
        return;
    }
    else{

        biggestnode(root->left,max);
        if(root->info>*max)
        {
            *max = root->info;
        }
        biggestnode(root->right,max);
        
    }
}

void smallestnode(tree * root,int * min)
{

    if(root == NULL)
    {
        return;
    }
    else{

        smallestnode(root->left,min);
        if(root->info<*min)
        {
            *min = root->info;
        }
        smallestnode(root->right,min);
        
    }
}

void  search(tree * root,int key,int *flag)
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        if(key<root->info)
        {
        if(key==root->info)
            *flag=1;
        search(root->left,key,flag);
        }
        else
        {
        if(key==root->info)
        {
            *flag =1;
        }
        search(root->right,key,flag);
        }
    }
    
}

void nodesatleft(tree * root,int num)
{
    
    if(root == NULL)
    {
        return;
    }
    else
    {
        
             nodesatleft(root->left,num);
             if(root->info<num)
              printf("%d ",root->info,num);
              nodesatleft(root->right,num);
        }
    }



int main()
{
    tree* root = NULL,*p =NULL;
    int choice=0,nodectr = 0,leafnodectr=0,onectr =0,max,min,key,flag =0,num;
    do
    {
          printf("enter value to switch\n");
         scanf("%d",&choice);
        switch(choice)
        {
            case 1: p = createnode();
                        insertbst(&root,p);
                        break;

            case 2:  printf("\npreorder\n");
                     preorder(root);
                    printf("\ninorder\n");
                    inorder(root);
                    printf("\npostorder\n");
                    postorder(root);
                    break;

            case 3: totalnodes(root,&nodectr);
                    printf(" \ntotal number of nodes = %d",nodectr);
                        break;
            case 4: leafnodes(root,&leafnodectr);
                    printf("\n number of leaf nodes = %d",leafnodectr);
                    break;
            
            case 5 : onechildnode(root,&onectr);
                     printf("\n number of one child nodes = % d",onectr);
                     break;
            case 6 : max = root->info;
                    biggestnode(root,&max);
                    printf("%d ",max);
                    break;
            case 7 :  min = root->info;
                    smallestnode(root,&min);
                    printf("%d ",min);
                    break;

            case 8 : printf("enter key to search\n");
                     scanf("%d",&key);
                     flag =0;
                      search(root,key,&flag);
                     if(flag==1)
                        printf("search found\n");
                    else 
                        printf("not found");
                        break;

            case 9 :    num = root->info;
                        nodesatleft(root,num);
                        break;


                     
            case 404 : exit(0);
        }


    } while (1);
    
}