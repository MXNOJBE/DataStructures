/*Task To Do:

1. Linear Search
2. Random Function to gernerate numbers
3. Binary search for sorted numbers
4. Explore Iterative, Recursive Methods
5. Difference between iteration and recursion
6. Use Menu driven function for binary search*/

#include <stdio.h>
#include <stdlib.h>

void linearsearch(int ele[], int n)
{
    int i, find;
    printf("Enter the element to be searched: ");
    scanf("%d", &find);
    for (i = 0; i < 10; i++)
    {
        if (find == ele[i])
        {
            printf("%d is found", find);
        }
    }
}
void binarysearch(int ele[], int x, int low, int high, int n)
{
    int temp, i, j;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; ++j)
        {
            if (ele[i] > ele[j])
            {
                temp = ele[i];
                ele[i] = ele[j];
                ele[j] = temp;
            }
        }
    }
    if (high < low)
    {
        printf("not found");
    }
    else
    {
        int mid = (high + low) / 2;
        if (x == ele[mid])
        {
            printf("\n%d is found ", x);
        }

        // If found at mid, then return it
        else if (x > ele[mid])
        {
            binarysearch(ele, x, mid + 1, high, n);
        }

        // Search the left half
        else
        {
            binarysearch(ele, x, low, mid - 1, n);
        }
    }
}
void main()
{

    int ele[100], n, i, e, x, low, high;
    printf("Enter the number of elements to be inserted: ");
    scanf("%d", &n);
    /*
        for (int i = 0; i < n; i++)
        {
            printf("Enter numbers to be inserted: ");
            scanf("%d", &ele[i]);
        }*/
    for (i = 0; i <= n; i++)
    {
        e = rand() % 100 + 1;
        printf("\t%d", e);
        ele[i] = e;
    }
    int choice;     
    printf("\nEnter 1 to perform LinearSearch operation\n");
    printf("Enter 2 to perform BinarySearch operation\n");
    printf("Enter 3 to exit\n");
    while (1)
    {
        printf("\nEnter the Choice Accordingly: ");
        scanf("%d", &choice);
        switch (choice)
        {

        case 1:
            linearsearch(ele, n);
            break;

        case 2:
            high = n - 1;
            low = 0;
            printf("Enter the element to be searched:  ");
            scanf("%d", &x);
            binarysearch(ele, x, low, high, n);
            break;

        case 3:
            exit(0);

        default:
            printf("Wrong Choice\n");
        }
    }
}
