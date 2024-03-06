#include <stdio.h>
void bubble_sort(int a[], int n)
{
    int flag = 0, temp;
    for (int i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                flag = 1;
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
        if (flag == 0)
            break;
    }
}
void selection_sort(int a[], int n)
{
    int pos, min, temp;
    for (int i = 0; i < n - 1; i++)
    {
        min = a[i];
        pos = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[i])
            {
                min = a[j];
                pos = j;
            }
        }
        a[pos] = a[i];
        a[i] = min;
    }
}
void insertion_sort(int a[], int n)
{
    int j, t;
    for (int i = 1; i < n; i++)
    {
        t = a[i];
        j = i - 1;
        while (j >= 0 && t < a[j])
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = t;
    }
}
int ctr;
void quick_sort(int a[], int lb, int ub)
{
    int i = lb, j = ub, pivot = a[lb], t = 0;
    if (lb >= ub)
        return;
    while (i < j)
    {
        while (a[i] <= pivot&&i<j)
        {
            i++;
            ctr++;
        }
        while (a[j] > pivot)
            j--;
        if (i < j)
        {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    a[lb] = a[j];
    a[j] = pivot;
    quick_sort(a, lb, j-1 );
    quick_sort(a, j + 1, ub);
}
void merge(int a[], int lb, int mid, int ub)
{
    int i = lb, j = mid +1, k = lb, c[100];
    while (i <= mid && j <= ub)
    {
        if (a[i] < a[j])
        {
            c[k] = a[i];
            k++;
            i++;
        }
        else
        {
            c[k] = a[j];
            k++;
            j++;
        }
    }
    for (; i <= mid; i++)
        c[k++] = a[i];
    for (; j <= ub; j++)
        c[k++] = a[j];
    for (int i = lb; i <= ub; i++)
    {
        a[i] = c[i];
    }
    
}

void mergesort(int a[], int lb, int ub)
{
    int mid = 0;
    if (lb < ub)
    {
        mid = (lb + ub) / 2;
        mergesort(a, lb, mid);
        mergesort(a, mid + 1, ub);
        merge(a, lb, mid, ub);
    }
}
int main()
{
    int arr[100];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = 10 - i;
    }
    bubble_sort(arr, 10);
    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    printf("\n");
    for (int i = 0; i < 10; i++)
    {
        arr[i] = 10 - i;
    }
    selection_sort(arr, 10);
    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    for (int i = 0; i < 10; i++)
    {
        arr[i] = 10 - i;
    }
    printf("\n");

    insertion_sort(arr, 10);
    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    for (int i = 0; i < 10; i++)
    {
        arr[i] = 10 - i;
    }
    printf("\n");

    quick_sort(arr, 0, 9);
    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);

    printf("\n%d",ctr);
     for (int i = 0; i < 10; i++)
    {
        arr[i] = 10 - i;
    }
    printf("\n");

    mergesort(arr, 0, 9);
    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    return 0;
}

