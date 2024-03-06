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

void compare(nd*Q,nd*P)
{
    int flag =0;
    nd*p= P,*q=Q,*temp=P,*temp2 = Q;

    while(Q!=NULL)
    {
        flag =0;
        P=p;
        while(P!=NULL)
        {
            if(Q->info==P->info)
                flag =1;
          P=P->next;
        }
          if(flag==0)
            printf("%d--->",Q->info);
        Q=Q->next;
    }
    

    while(p!=NULL)
    {
        flag =0;
         q=temp2;
        while(q!=NULL)
        {
           
            if(p->info==q->info)
                flag =1;
            q=q->next;
          
        }
          if(flag==0)
            printf("%d--->",p->info);
        p=p->next;

    }
}

void alternate(nd*P)
{
    nd*p=P;
    while(P!=NULL)
    {   
        p=P->next;
        if(p!=NULL)
    {
        
        P->next=p->next;
        free(p);
    }
    printf("%d ",P->info);
    P=P->next;
    }
   
}

void alternateprint(nd*P)
{
   int  ctr=0;
    while(P!=NULL)
    {   
       
        if(ctr%2==1)
        {
         printf("%d ",P->info);
        }
        ctr++;
        P=P->next;
        
   
   
  
    }
   
}



int main()
{
    nd *P, *right,*Q,*tail;
    P = Q= NULL;
    right = tail = NULL;
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
            if (P == NULL)
                P = right;
           
            break;
        case 2:
              tail = createlist(tail);
            if(Q==NULL)
            Q=tail;
            break;
        case 3:
            display(P);
            printf("\n");
            display(Q);
            break;
        case 4:
            compare(P,Q);
            break;
        case 5:
              alternate(P);
              break;
            
        case 6: alternateprint(P);
        break;
           
        }   
                                  
     
    } while (1);
}