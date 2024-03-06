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
        right->next = NULL;
    }
    else
    {
        p->next = right->next;
        right->next =p;
        
    }
    return p;
}

void display(nd *left)
{
    while (left != NULL)
    {
        printf("%d --->", left->info);
        left = left->next;
    } 
}

void delete(nd** left,int key)
{
   nd*prev,*current = *left;
   if(current->info==key)
   {
        *left= (*left)->next;
        free(current);
   }
   else
   {
        while(current->info!=key&&current !=NULL)
        {
            prev = current;
            current= current->next;
        }
     if(current==NULL)
       printf("key not found");
        prev->next  = current->next;
        free(current);
   }


}

int main()
{
    nd *left, *right;
    left = NULL;
    right = NULL;
    int choice, key;
    char ch;
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
        case 3:
            printf("enter key\n");
            scanf("%d", &key);
            delete(&left,key);
            break;
        }   
                                  
     
    } while (1);
}