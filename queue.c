#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int info;
    struct node* next;
}nt;
void enqueue(nt**,nt**);
void dequeue(nt**,nt**);
void display(nt*);
int main()
{
    int ch;
    nt*l=NULL,*r=NULL;
    do{
        printf("Enter choice");
        scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        enqueue(&l,&r);
        break;
        case 2:
        dequeue(&l,&r);
        break;
        case 3:
        display(l);
    }
    }while(ch<=3);
}

void enqueue(nt** l,nt**r)
{
    nt*p;
    p=(nt*)malloc(sizeof(nt));
    printf("Enter info");
    scanf("%d",&(p->info));
    if(*l==NULL)
    {
        *l=*r=p;
    }
    else
    {
        (*r)->next=p;
        *r=p;
    }
    (*r)->next=NULL;
}
void dequeue(nt** l,nt** r)
{
    nt*p=*l;
    printf("Deleted element is %d\n",p->info);
    if(*l==*r)
    {
        *l=NULL;
        *r=NULL;
    }
    else
    *l=(*l)->next;
}
void display(nt* l)
{
    while(l!=NULL)
    {
        printf("%d",l->info);
        l=l->next;
    }
}
