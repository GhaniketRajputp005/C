#include <stdio.h>
#include <stdlib.h>
#define max 100
int push(int st[],int t,int data);
int pop(int st[],int* t);

int enqueue(int st1[],int t1);
void dequeue(int st1[],int st2[],int *t1,int *t2);
void display(int st[],int t);

void main()
{
    int st1[max], st2[max];
    int t1=-1,t2=-1;

    int ch;
    printf("\n1 - Enqueue element into queue");
    printf("\n2 - Dequeu element from queue");
    printf("\n3 - Display from queue");
    printf("\n4 - Exit");
    //create();
    while (1)
    {
        printf("\nEnter choice");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            t1=enqueue(st1,t1);
            break;
        case 2:
            dequeue(st1,st2,&t1,&t2);
            break;
        case 3:
            display(st1,t1);
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong choice");
        }
    }
}

//Function to push the element on to the stack/
int push(int st[],int t,int data)
{
    t++;
    st[t]=data;
    return t;
}
//Function to pop the element from the stack/
int pop(int st[],int* t)
{
    int x=st[(*t)];
    (*t)--;
    return(x);
}


//Function to add an element into the queue using stack/
int enqueue(int st1[],int t1)
{
    int data;
    printf("Enter data into queue");
    scanf("%d", &data);
    t1=push(st1,t1,data);
   /* t1++;
    st1[t1]=data;*/
    return t1;
}

//Function to delete an element from the queue using stack/

void dequeue(int st1[],int st2[],int* t1,int* t2)
{
    int x;
    while((*t1)!=-1)
    {
        x=pop(st1,t1);
        (*t2)=push(st2,*t2,x);
    }
    x=pop(st2,t2);
    printf("Deleted element is %d",x);
    while((*t2)!=-1)
    {
        x=pop(st2,t2);
        (*t1)=push(st1,*t1,x);
    }
}

//Function to display the elements in the queue/

void display(int st[],int t)
{
    int i;

    for (i = 0;i <= t;i++)
    {
        printf(" %d ", st[i]);
    }
}
