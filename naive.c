#include <stdio.h>
#include <string.h>

void main()
{
    int i, j, k = 0;
    char n[50], m[50];
    printf("Enter the Element to be searched from: ");
    gets(n);
    printf("Enter the Element to be searched: ");
    gets(m);
    int actualsize = strlen(n) - strlen(m);
    printf("n = %d m = %d", strlen(n), strlen(m));

    for (i = 0; i < strlen(n); i++)
    {

        for (j = 0; j < strlen(m) + 1; j++)
        {
            printf("\n%c is n[i] and %c m[j]", n[i], m[j]);

            if (n[i] == m[j])
            {
                printf("\ni value is %d", i);
                printf("\nj value is %d", j);
                k = k + 1;
                printf("\nk is %d index at %d", k, i);
                if (k == strlen(m))
                {
                    int size = i - strlen(m);
                    printf("\nindex found at %d", size);
                }
                i++;
            }
            else
            {
                j++;
            }
        }

        k = 0;
    }
}
