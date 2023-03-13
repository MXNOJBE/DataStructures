#include <stdio.h>
#include <string.h>
int main()
{
    char n[50], m[50];
    printf("Enter the word to be searched from: ");
    gets(n);
    printf("Enter the word to be searched: ");
    gets(m);
    int M = strlen(m);
    int N = strlen(n);
    for (int i = 0; i <= N - M; i++)
    {
        int j;
        for (j = 0; j < M; j++)
            if (n[i + j] != m[j])
                break;
        if (j == M)
            printf("\nPattern matches at index %d", i);
    }
    return 0;
}