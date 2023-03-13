#include <stdio.h>
#include <string.h>

void main()
{
    int i, j;
    char n[50], m[50];
    printf("Enter the word to be searched from: ");
    gets(n);
    printf("Enter the word to be searched: ");
    gets(m);
    int exactnum = strlen(n) - strlen(m);
    printf("%d", exactnum);
    for (i = 0; i < strlen(n); i++)
    {
        // printf("\n%c", n[i]);
        for (j = 0; j < strlen(m); j++)
        {
            if (n[i] == m[j] && n[i + 1] == m[j + 1] && n[i + 2] == m[j + 2])
            {
                printf("\nPattern found at index %d", i);
            }
        }
    }
}