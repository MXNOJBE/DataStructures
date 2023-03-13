
#include<stdio.h>
#include<conio.h>

int main()
{
	int n,m,i,j,c=0;
	printf("\n Enter the number of elements for 1st array: ");
	scanf("%d",&n);
	printf("\n Enter the number of elements for 2nd array : ");
	scanf("%d",&m);
	
	int a1[m],a2[n];
	printf("\n-----------------------------------------------------\n");
	for(i=0;i<n;i++)
	{
		printf("\nEnter %d value for 1st array : ",(i+1));
		scanf("%d",&a1[i]);
	}
	
	printf("\n-----------------------------------------------------\n");

	for(i=0;i<m;i++)
	{
		printf("\nEnter %d value for 2nd array : ",(i+1));
		scanf("%d",&a2[i]);
	}
	
	printf("\n-----------------------------------------------------\n");

	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a1[j]==a2[i])
			c++;
		}
	}
	
	if(c==m)
	printf("the 2nd array is subset of first array");
	else
	printf("the 2nd array is  not a subset of first array");

}
