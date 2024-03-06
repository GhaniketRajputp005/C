#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int info;
    struct node* next;
}nt;
nt* push(nt*);
nt* pop(nt*);
void display(nt*);
int main()
{
    int ch;
    nt*t=NULL;
    do{
        printf("Enter choice");
        scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        t=push(t);
        break;
        case 2:
        t=pop(t);
        break;
        case 3:
        display(t);
    }
    }while(ch<=3);
}

nt* push(nt* t)
{
    nt*p;
    p=(nt*)malloc(sizeof(nt));
    printf("Enter info");
    scanf("%d",&(p->info));
    p->next=t;
    t=p;
    return t;
}
nt* pop(nt*t)
{
   nt*p;
   p=t;
   printf("popped element is %d",p->info);
   p=p->next;
   return p;
}
void display(nt* t)
{
    while(t!=NULL)
    {
        printf("%d",t->info);
        t=t->next;
    }
}
