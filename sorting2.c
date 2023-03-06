#include <stdio.h>
#include <stdlib.h>

void bubblesort(int ele[], int n)
{
    int i, j, k;
    printf("Before Sort: ");
    for (int k = 0; k < n; k++)
    {
        printf("%d ", ele[k]);
    }

    printf("\n\nIntermediate Steps: \n");
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (ele[j] > ele[j + 1])
            {
                int temp = ele[j];
                ele[j] = ele[j + 1];
                ele[j + 1] = temp;
            }
        }

        for (int k = 0; k < n; k++)
        {
            printf("%d ", ele[k]);
        }
        printf("\n");
    }

    printf("\n\nAfter Sort: ");
    for (int k = 0; k < n; k++)
    {
        printf("%d ", ele[k]);
    }
}

void selection(int ele[], int n)
{
    int i, j, k, min;

    printf("\nOriginal Array : ");
    for (int k = 0; k < n; k++)
    {
        printf("%d ", ele[k]);
    }

    printf("\n Sorted Array using Selection Sort : \n");

    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (ele[min] > ele[j])
            {
                min = j;
            }
        }

        if (min != i)
        {
            int temp = ele[i];
            ele[i] = ele[min];
            ele[min] = temp;
        }
        for (int k = 0; k < n; k++)
        {
            printf("%d ", ele[k]);
        }
        printf("\n");
    }
}

void insertion(int ele[], int n)
{
    int k, i, j;

    printf("\nOriginal Array : ");
    for (int k = 0; k < n; k++)
    {
        printf("%d ", ele[k]);
    }

    printf("\n Sorted Array using Insertion Sort : \n");

    for (i = 1; i < n; i++)
    {
        int tmp = ele[i];
        j = i - 1;

        while (tmp < ele[j] && j >= 0)
        {
            ele[j + 1] = ele[j];
            --j;
        }
        ele[j + 1] = tmp;

        for (int k = 0; k < n; k++)
        {
            printf("%d ", ele[k]);
        }
        printf("\n");
    }
}

void main()
{

    int n = 10, i, e, x, low, high;
    /*
    printf("Enter the number of elements to be inserted: ");
    scanf("%d", &n);

        for (int i = 0; i < n; i++)
        {
            printf("Enter numbers to be inserted: ");
            scanf("%d", &ele[i]);
        }*/
    int ele[] = {9, 6, 5, 0, 8, 2, 7, 1, 3, 4};
    int choice;
    printf("\nEnter 1 to perform BubbleSort operation\n");
    printf("Enter 2 to perform Selection operation\n");
    printf("Enter 3 to perform Insertion operation\n");
    printf("Enter 4 to perform exit\n");

    while (1)
    {
        printf("\nEnter the Choice Accordingly: ");
        scanf("%d", &choice);
        switch (choice)
        {

        case 1:
            bubblesort(ele, n);
            break;

        case 2:
            selection(ele, n);
            break;

        case 3:
            insertion(ele, n);
            break;
        case 4:
            exit(0);

        default:
            printf("Wrong Choice\n");
        }
    }
}
