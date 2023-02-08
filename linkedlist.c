#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *front;
struct node *rear;

void enqueue()
{
    struct node *ptr;
    int item;

    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("overflow\n");
        return;
    }
    else
    {
        printf("Enter value to be inserted\n");
        scanf("%d", &item);
        ptr->data = item;
        if (front == NULL)
        {
            front = ptr;
            rear = ptr;
            front->next = NULL;
            rear->next = NULL;
        }
        else
        {
            rear->next = ptr;
            rear = ptr;
            rear->next = NULL;
        }
    }
}
void dequeue()
{
    struct node *ptr;
    if (front == NULL)
    {
        printf("Its an underflow \n");
        return;
    }
    else
    {
        ptr = front;
        front = front->next;
        free(ptr);
    }
}
void display()
{
    struct node *ptr;
    ptr = front;
    if (front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Values are\n");
        while (ptr != NULL)
        {
            printf("%d\n", ptr->data);
            ptr = ptr->next;
        }
    }
}

void main()
{
    int choice;
    printf("Enter 1 to perform Enqueue operation\n");
    printf("Enter 2 to perform Deqeue operation()\n");
    printf("Enter 3 to display\n");
    printf("Enter 4 to exit\n");
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
            printf("Wrong Choice\n");
        }
    }
}