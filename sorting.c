#include<stdio.h>
# define max 10

void bsort(int a[])
{
    int i,f,j,temp;
    for(i=0;i<max-1;i++)
    {
        f=0;
        for(j=0;j<max-1-i;j++)
        if(a[j]>a[j+1])
            {
                f=1;
                temp = a[j];
                a[j]= a[j+1];
                a[j+1]=temp;
            }
        if(f==0)
        {
            break;
        }
    }
}

void selectionsort(int a[])
{
    int i,j,pos,min;
    for(i=0;i<max-1;i++)
    {
        min=a[i];
        pos =i;
        for(j=i+1;j<max;j++)
        {
            if(a[j]<min)
            {
                min = a[j];
                pos =j;
            }
        }
        if(i!=pos)
        {
            a[pos]=a[i];
            a[i]=min;
        }
    }
}

void insertsort(int a[])
{
    int i,j,t;
    for(i=1;i<max;i++)
    {
        t=a[i];
        j=i-1;
        while(j>=0&&t<a[j])
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=t;
    }
    
}

void quicksort(int a[],int lb,int ub)
{
    int i=lb,j=ub,key = a[lb],t=0;

    if(lb>=ub)
        return;
    while(i<j)
    {
        while(i<j && key>= a[i])
        i++;
        while(key<a[j])
        j--;
        
        if(i<j)
        {
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }

    a[lb] = a[j];
    a[j] = key;
    quicksort(a,lb,j-1);
    quicksort(a,j+1,ub);
}

int main()
{
    int a[max],i;
    for(i=0;i<max;i++)
        a[i]=max -i;
    for(i=0;i<max;i++)
        printf("%d ",a[i]);
    printf("\n");
    //bsort(a);
    //selectionsort(a);
    //insertsort(a);
    quicksort(a,0,max);
    for(i=0;i<max;i++)
        printf("%d ",a[i]);

}