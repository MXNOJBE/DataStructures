#include <stdio.h>
#include <stdlib.h>

int stack1[100], stack2[100];
int top1 = -1;
int top2 = -1;
int count = 0;
int x;

void start()
{
    top1 = top2 = -1;
}
void push1(int x)
{
    stack1[++top1] = x;
}
int pop1()
{
    return (stack1[top1--]);
}
void push2(int x)
{
    stack2[++top2] = x;
}
int pop2()
{
    return (stack2[top2--]);
}

void enqueue()
{
    char c;
    int i;
    printf("Enter the elements schould be passed into: ");
    scanf("%s", &x);
    push1(x);
    count++;
}

void dequeue()
{
    int i;
    for (i = 0; i <= count; i++)
    {
        push2(pop1());
    }
    pop2();
    count--;
    for (i = 0; i <= count; i++)
    {
        push1(pop2());
    }
}
void display()
{
    int i;
    for (i = 0; i <= top1; i++)
    {
        printf("%s\n", &stack1[i]);
    }
}

void main()
{
    int choice;
    printf("Enter 1 to perform Enqueue operation\n");
    printf("Enter 2 to perform Deqeue operation()\n");
    printf("Enter 3 to Display elements in stack1\n");
    printf("Enter 4 to Stop the application\n");
    start();
    while (1)
    {
        printf("Enter the Choice Accordingly: ");
        scanf("%d", &choice);
        switch (choice)
        {

        case 1:
            enqueue();
            break;

        case 2:

            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);
        default:
            printf("Wrong Choice");
        }
    }
}