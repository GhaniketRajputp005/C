#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int x;
    struct node *next;
}nd;
nd* insert(nd*);
nd* del(nd*,int);
void disp(nd*);
void search(nd*);
int main()
{
    nd *last=NULL,*p=NULL;
    int ch;
    do
    {
        printf("Enter Choice :-\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                last=insert(last);
            }
            break;
            case 2:
            {
                if(last==NULL)
                printf("Underflow");
                else
                {
                    int x;
                    printf("Enter Element to be deleted : ");
                    scanf("%d",&x);
                    last=del(last,x);
                }
            }
            break;
            case 3:
            {
                if(last==NULL)
                printf("Underflow");
                else
                disp(last);
            }
            break;
            case 4:
            if(last==NULL)
            printf("Underflow");
            else
            search(last);
            break;
            case 5:
            printf("OK");
            break;
            default:printf("Please Enter a Valid Choice\n");
        }
    }while(ch!=5);
}
nd* insert(nd *l)
{
    nd *p=(nd*)malloc(sizeof(nd));
    printf("Enter Element : ");
    scanf("%d",&p->x);
    if(l==NULL)
    {
        l=p;
        l->next=p;
    }
    else
    {
        p->next=l->next;
        l->next=p;
    }
    return l;
}
void disp(nd *l)
{
    nd *p=l->next;
    do
    {
        printf("%d",p->x);
        p=p->next;
    }while(p!=l->next);
}
nd* del(nd *l,int c)
{
    nd *p=l->next,*t=NULL;
    while(p->x!=c)
    {
        t=p;
        p=p->next;
    }
    if(l==l->next)
        l=NULL;
    else if(p==l->next)
    {
        l->next=l->next->next;
    }
    else if(p==l)
    {
        l=t;
        t->next=p->next;
    }
    else
    {
        t->next=p->next;
    }
    free(p);
    return l;
}
void search(nd *l)
{
    nd *p=l;
    int n,c=0;
    printf("Enter Element to be Searched : ");
    scanf("%d",&n);
    do
    {
        if(p->x==n)
        break;
        c++;
    }while(p->next!=l);
    if(p->next==l)
        printf("Not Found");
    else
        printf("Found at %d",c);
}
