#include<stdio.h>

void main()
{
    int i,n,a[10];
    printf("Enter the size of elements to be added into the array");
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        printf("Enter the element %d",i);
        scanf("%d", &a[i]);
    }
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
}
