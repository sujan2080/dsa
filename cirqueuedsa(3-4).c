#include<stdio.h>
#include<conio.h>

#define SIZE 10

struct cqueue
{
    int item[SIZE], front, rear;
}cq;

void insert(int);
void delet();
void display();


void main()
{
    int value, choice;
    cq.front=SIZE-1;
    cq.rear=SIZE-1;

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
                insert(value);
                display();
                break;

            case 2:
                delet();
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




void insert(int d)
{
    if(cq.front==(cq.rear+1)%SIZE)
    {
        printf("\nQueue is Full!!!");
    }
    else
    {
        cq.rear=(cq.rear+1)%SIZE;
        cq.item[cq.rear] = d;
    }
}

void delet()
{
    if(cq.rear==cq.front)
    {
        printf("\nQueue is Empty!!!");
    }
    else
    {
        cq.front=(cq.front+1)%SIZE;
        printf("\nDeleted item is: ");
        printf("%d\n",cq.item[cq.front]);
    }
}

void display()
{
    int i;
     if(cq.rear==cq.front)
    {
        printf("\nQueue is Empty!!!");
    }
    else
    {
        printf("\nItems of queue are: \n");
        for(i=(cq.front+1)%SIZE;i!=(cq.rear+1)%SIZE;i=(i+1)%SIZE)
        {
            printf("%d\t",cq.item[i]);
        }
    }

}
