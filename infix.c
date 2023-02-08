#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}
char pop()
{
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x)
{
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    if (x == '^')
        return 3;
    return 0;
}

void infixToPostfix(char infix[], char postfix[])
{
    int i = 0, j = 0;
    char x;

    push('(');
    strcat(infix, ")");

    while (infix[i] != '\0')
    {
        if (isalnum(infix[i]))
            postfix[j++] = infix[i];
        else if (infix[i] == '(')
            push(infix[i]);
        else if (infix[i] == ')')
        {
            while ((x = pop()) != '(')
                postfix[j++] = x;
        }
        else
        {
            while (priority(stack[top]) >= priority(infix[i]))
                postfix[j++] = pop();
            push(infix[i]);
        }
        i++;
    }
    postfix[j] = '\0';
}

void StepByStep(char infix[], char postfix2[])
{
    int i = 0, j = 0;
    char x;

    push('(');
    strcat(infix, ")");

    while (infix[i] != '\0')
    {
        if (isalnum(infix[i]))
            postfix2[j++] = infix[i];
        else if (infix[i] == '(')
            push(infix[i]);
        else if (infix[i] == ')')
        {
            while ((x = pop()) != '(')
                postfix2[j++] = x;
        }
        else
        {
            while (priority(stack[top]) >= priority(infix[i]))
                postfix2[j++] = pop();
            push(infix[i]);
        }
        i++;
        printf("Step %d Result %s\n", i, postfix2);
    }
    postfix2[j] = '\0';
}

int main()
{
    char infix[MAX], postfix[MAX], postfix2[MAX];
    int ch;
    int i = 1;
    while (i > 0)
    {
        printf("Infix to Postfix Conversion\n");
        printf("1: To Enter the Infix Expression\n");
        printf("2. Infix to Postfix Conversion\n");
        printf("3. Infix to Postfix Conversion step by step\n");
        printf("Any other input is wrong choice\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter infix expression: ");
            scanf("%s", infix);
            printf("Infix Expression: %s\n", infix);
            break;
        case 2:
            printf("Infix Expression: %s\n", infix);
            infixToPostfix(infix, postfix);
            printf("Postfix expression: %s\n", postfix);
            break;
        case 3:
            printf("Infix Expression: %s\n", infix);
            StepByStep(infix, postfix2);
            printf("Postfix expression: %s\n", postfix2);
            break;
        default:
            printf("Wrong Input\n");
        }
        printf("Do you want to continue(1:yes | 0: no)\n");
        scanf("%d", &i);
    }
    return 0;
}
