#include <stdio.h>
#define max 100
void push(int q[],int *f,int *r);
void pop(int q[],int* f,int *r);

void enqueue(int q[],int *f1,int *r1,int data);
void dequeue(int q[],int* f1,int* r1);
void display(int [],int );

void main()
{
    int q1[max];
    int f1=-1,r1=-1;

    int ch;
    printf("\n1 - Push element into stack");
    printf("\n2 - Pop element from stack");
    printf("\n3 - Display from stack");
    printf("\n4 - Exit");
    //create();
    while (1)
    {
        printf("\nEnter choice");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push(q1,&f1,&r1);
            break;
        case 2:

            pop(q1,&f1,&r1);
            break;
        case 3:
            display(q1,r1);
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong choice");
        }
    }
}

//Function to push the element on to the stack/
void push(int q[],int *f,int *r)
{
    int data;
    printf("Enter data into stack");
    scanf("%d", &data);
    enqueue(q,f,r,data);
}
//Function to pop the element from the stack/
void pop(int q[],int* f,int *r)
{
    dequeue(q,f,r);
}


//Function to add an element into the stack using queue/
void enqueue(int q[],int *f1,int *r1,int data)
{
    (*r1)++;
    q[*r1]=data;
    if((*f1)==-1)
    (*f1)++;
}

//Function to delete an element from the stack using queue/

void dequeue(int q[],int* f1,int* r1)
{
    printf(" Deleted element is %d",q[*r1]);
    if((*f1)==(*r1))
    (*f1)=(*r1)=-1;
    else
    (*r1)--;
}
//Function to display the elements in the stack/
void display(int q[],int r)
{
    int i;

    for (i=r;i>=0;i--)
    {
        printf(" %d ", q[i]);
    }
}
