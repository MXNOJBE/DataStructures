#include <stdio.h>
#include <stdlib.h>

int i, ele[50], a, n;

void division_display(int si, int ei)
{
    int i;
    printf("[");
    for (i = si; i <= ei; i++)
    {
        printf("%d ", ele[i]);
    }
    printf("]");
}

void rand1(int u)
{

    for (i = 0; i < n; i++)
    {
        int a = rand() % 100;
        ele[i] = a;
        printf("\t%d", a);
    }
}
void display(int u)
{
    for (i = 0; i < n; i++)
    {
        printf("\t%d", ele[i]);
    }
}
void merge(int u[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
    {
        L[i] = ele[left + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = ele[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            ele[k] = L[i];
            i++;
        }
        else
        {
            ele[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        ele[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        ele[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int u[], int left, int right)
{
    int mid;
    mid = (right + left) / 2;
    if (left < right)
    {
        printf("\nArray: ");
        division_display(left, mid);
        printf(" ");
        division_display(mid + 1, right);
        printf("\n");
    }
    if (left < right)
    {
        mergeSort(ele, left, mid);
        mergeSort(ele, mid + 1, right);
        merge(ele, left, mid, right);
    }
}

void main()
{
    int choice;
    printf("Enter the number of elements to be inserted: ");
    scanf("%d", &n);
    while (1)
    {
        printf("\nEnter 1 to generate random numbers");
        printf("\nEnter 2 to display");
        printf("\nEnter 3 to perform sorting");
        printf("\nEnter 4 to exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {

        case 1:
            rand1(n);
            break;
        case 2:
            display(n);
            break;
        case 3:
            mergeSort(ele, 0, n - 1);
        case 4:
            exit(0);
        default: printf("\nWrong Choice");
        }
    }
}