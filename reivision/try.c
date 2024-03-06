#include <stdio.h>
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
    for (int i = lb; i <= ub; i++)
    {
        printf("%d ",c[i]);
    }
    printf("\n");
}
// void merge(int A[], int low, int mid, int high)
// {
//     int i, j, k, B[100];
//     i = low;
//     j = mid + 1;
//     k = low;

//     while (i <= mid && j <= high)
//     {
//         if (A[i] < A[j])
//         {
//             B[k] = A[i];
//             i++;
//             k++;
//         }
//         else
//         {
//             B[k] = A[j];
//             j++;
//             k++;
//         }
//     }
//     while (i <= mid)
//     {
//         B[k] = A[i];
//         k++;
//         i++;
//     }
//     while (j <= high)
//     {
//         B[k] = A[j];
//         k++;
//         j++;
//     }
//     for (int i = low; i <= high; i++)
//     {
//         A[i] = B[i];
//     }
// }

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
    int n = 5, m = 7;
    //int a[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 12, 14};
int a[] = {6,3,10,100,80,40};
    mergesort(a, 0, 50);
    printf("\n");
    for (int i = 0; i < 6; i++)
        printf("%d ", a[i]);
}
