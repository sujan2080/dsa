#include<stdio.h>
#include<conio.h>

#define SIZE 10

struct lqueue
{
    int queue[SIZE], front, rear;
}q;

void enQueue(int);
void deQueue();
void display();

void main()
{
    int value, choice;
    q.front=0;
    q.rear=-1;
    while(1)
    {
        printf("\n\n*****MENU*****\n");
        printf("1.Insertion\n2.Deletion\n3.Display\n4.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the value to be insert: ");
                scanf("%d",&value);
                enQueue(value);
                display();
                break;

            case 2:
                deQueue();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("\nWrong selection!!! Try again!!!");

        }
    }
}

void enQueue(int value)
{
    if(q.rear==SIZE-1)
    {
        printf("\nQueue is Full!!! Insertion is not possible!!!");
    }
    else
    {
        q.rear++;
        q.queue[q.rear] = value;
        printf("\nInsertion success!!!");
    }
}

void deQueue()
{
    if(q.rear<q.front)
    {
        printf("\nQueue is Empty!!! Deletion is not possible!!!");
    }
    else
    {
        printf("\nDeleted : %d",q.queue[q.front]);
        q.front++;
    }
}

void display()
{
     if(q.rear<q.front)
    {
        printf("\nQueue is Empty!!!");
    }
    else
    {
        int i;
        printf("\nQueue elements are: \n");
        for(i=q.front;i<=q.rear;i++)
        {
            printf("%d\t",q.queue[i]);
        }
    }

}
