#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int x;
    struct node *next;
}nd;
void insert(nd**,nd**);
void display(nd*);
void del(nd**,nd**);
void search(nd*);
void main()
{
    nd *l=NULL,*r=NULL;
    int ch;
do
{
    printf("Enter Choice : ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:insert(&l,&r);
                break;
    case 2:
            if(l==NULL&&r==NULL)
            printf("Empty Linked List\n");
            else
            del(&l,&r);
            break;
    case 3:
            if(l==NULL&&r==NULL)
            printf("Empty Linked List\n");
            else
            display(l);
            break;
    case 4:
            if(l==NULL&&r==NULL)
            printf("Empty Linked List\n");
            else
            search(l);
            break;
    }
}while(ch!=4);
}
void insert(nd **l,nd **r)
{
    int in,c;
    nd *q=*l,*p;
    p=(nd*)malloc(sizeof(nd));
    printf("Enter Value to be Inserted : ");
    scanf("%d",&p->x);
    p->next=NULL;
    printf("Where do you want to insert front end or at a particular index : ");
    scanf("%d",&in);
    switch(in)
    {
        case 1:
            if (*l==NULL||*r==NULL)
            {
                *l=p;
                *r=p;
            }
            else
            {
                p->next=*l;
                *l=p;
            }
            break;
        case 2:
            if (*l==NULL||*r==NULL)
            {
                *l=p;
                *r=p;
            }
            else
            {
                (*r)->next=p;
                *r=p;
            }
            break;
    case 3:
        printf("Enter Index : ");
        scanf("%d",&c);
        while(c!=0)
        {
            if(q==NULL)
            {
                printf("Not Enough Nodes\n");
                return;
            }
            q=q->next;
            c--;
        }
            p->next=q->next;
            q->next=p;
            break;
            default:printf("Not Valid\n");
        }
}
void display(nd *l)
{
    while(l!=NULL)
    {
        printf("%d",l->x);
        l=l->next;
    }
}
void del(nd **l,nd **r)
{
    nd *q=NULL;
    int c;
    printf("Where from delete the node : ");
    scanf("%d",&c);
    switch(c)
    {
        case 1:
                q=*l;
                *l=q->next;
                printf("Deleted Value : %d",q->x);
                free(q);
                if(*l==NULL)
                *r=NULL;
                break;
        case 2:
                if(*l==*r)
                {
                    free(*l);
                    *l=NULL;
                    *r=NULL;
                    return;
                }
                q=*l;
                while(q->next->next!=NULL)
                q=q->next;
                *r=q;
                free(q->next);
                (*r)->next=NULL;
                break;
        case 3:
                q=*l;
                printf("Enter Index : ");
                scanf("%d",&c);
                while(c!=0)
                {
                    if(q->next==NULL)
                    {
                        printf("Not Enough Space\n");
                        return;
                    }
                    q=q->next;
                    c--;
                }
                    nd *p=q->next;
                    q->next=q->next->next;
                    free(p);
                    break;
                    default:printf("Not a Valid Choice\n");
    }
}
void search(nd *l)
{
    int n,index=0;
    printf("Enter Element : ");
    scanf("%d",&n);
    while(l->x!=n&&l!=NULL)
    {
        l=l->next;
        index++;
    }
    if(l!=NULL)
    printf("Element Found at index : %d",index);
    else
    printf("Not Found");
}
