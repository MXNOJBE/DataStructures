#include<stdio.h>
#include<string.h>
#include<stdlib.h>


static int c=0;
int takeInput()
{
	int ch;
	while(scanf("%d",&ch) !=1)
	{
			printf("\n\nInvalid value. Try with numeric values : ");
			scanf("%d",&ch);
			while(getchar()=='\n');
	}
	return ch;
	
}

char *randstring(int length) {

    static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ .?!";        
    char *randomString = NULL;
	
	srand(++c);
	
	int n;
    if (length) {
        randomString = malloc(sizeof(char) * (length +1));

        if (randomString) {            
            for (n = 0;n < length;n++) {            
                int key = rand() % (int)(sizeof(charset) -1);
                randomString[n] = charset[key];
            }

            randomString[length] = '\0';
        }
    }

    return randomString;
}

int naive()
{
	
	int s = 50;
    int w = 3;
    int i,flag=0;
	char *str; 
    str = randstring(s);
    
    printf(" \n The Random generated String is : ");
    printf("%s",str);
    
    char *word = randstring(w);
    //char *word ="Bre";
    printf(" \n The pattern to search is : ");
    printf("%s",word);
    
    
    for (i = 0; i <= s - w; i++) 
	{
        
		int j;
        for (j = 0; j < s; j++)
            if (str[i + j] != word[j])
                break;
 
        if (j== w) 
        {
        	printf("\n\n Pattern found at index %d \n", i);
        	return 0;
		}
        else
        	flag++;
    }
    if(flag!=0)
    printf("\n Pattern not present");
} 

void kmp()
{
	int s = 50;
    int w = 3;
	char *str; 
    str = randstring(s);
    
    printf(" \n The Random generated String is : ");
    printf("%s",str);
    
    char *word = randstring(w);
    //char *word ="Bre";
    printf(" \n The pattern to search is : ");
    printf("%s",word);
    
    
    
    
}

int split_string(char *s)
{
	int l=1,i;
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]==' ' && s[i+1]!= ' ')
			l++;
	}
	return l;
}
void find_substring()
{
	
	int s = 50;
    int w = 3;
    int i,wn=0,cn=0;
	char *str; 
    str = randstring(s);
    int flag=0;
    printf(" \n The Random generated String is : ");
    printf("%s",str);
    
    char *word = randstring(w);
    //char *word ="Bre";
    printf(" \n The pattern to search is : ");
    printf("%s",word);
    
    int l=split_string(str);
    //printf("\n Length : %d",l);
    
    char split[l][s];
    for(i = 0; i < strlen(str); i++)
  	{

	    if(!isspace(str[i]))
	    {
	      split[wn][cn] = str[i];
	      cn++;
	    }
	
	    else
	    {
	      split[wn][cn] = '\0';
	      wn++;
	      cn = 0;
	    }
  	}
  	
  	for (i = 0; i <= strlen(split) - w; i++) 
	{
        
		int j;
        for (j = 0; j < s; j++)
            if (str[i + j] != word[j])
                break;
 
        if (j== w) 
        {
        	printf("\n\n Pattern found at index %d \n", i);
        	return 0;
		}
        else
        	flag++;
    }
    if(flag!=0)
    printf("\n Pattern not present");
  	
  	
  	
  	
  	
    
}

int main()
{
	int ch=1;
	while(ch)
	{
		printf("\n\nPress 1 to perform Naive Pattern Searching");
		printf("\nPress 2 to perform Pattern Searching");
		printf("\nPress 3 to perform KMP Pattern Searching");
		printf("\n\nEnter your choice : ");
		ch=takeInput();
		switch(ch)
		{
			case 1:
				naive();
				break;
			
			case 2:
				find_substring();
				break;
				
			case 3:
				kmp();
				break;
			
			default :
				printf("\nInvalid Choice");
		}
		printf("\n\nDo u wish to continue  (Press 1 to continue else 0 to exit) : ");
		ch=takeInput();
	}
}
