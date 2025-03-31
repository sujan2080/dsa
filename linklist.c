#include<stdlib.h>
#include<stdio.h>


void create();
void display();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();

struct node
{

    int info;
    struct node *next;
};
struct node *start=NULL;

int main()
{
    int choice;
    while(1)
    {
        printf("\nMenu");
        printf("\n1.Create");
        printf("\n2.Display");
        printf("\n3.Insert from beginning");
        printf("\n4.Insert from end");
        printf("\n5.Insert at intermediate position");
        printf("\n6.Delete from beginning");
        printf("\n7.Delete from end");
        printf("\n8.Delete from intermediate position");
        printf("\n9.Exit");

        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            create();
            break;

        case 2:
            display();
            break;
        case 3:
            insert_begin();
            break;

        case 4:
            insert_end();
            break;

        case 5:
            insert_pos();
            break;

        case 6:
            delete_begin();
            break;

        case 7:
            delete_end();
            break;

        case 8:
            delete_pos();
            break;

        case 9:
            exit(0);

        default:
            printf("Wrong choice!");
            break;
        }

    }
    return 0;
}



void create()
{
    struct node *temp,*ptr;
    temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("\nOut of Memory Space:\n");
        exit(0);
    }
    printf("\nEnter the data value for the node:\t");
    scanf("%d",&temp->info);
    temp->next=NULL;
    if(start==NULL)
    {
        start=temp;
    }
    else
    {
        ptr=start;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
    }

}

void display()
{
    struct node *ptr;
    if(start==NULL)
    {
        printf("\n List is empty:\t");
        return;
    }
    else
    {
        ptr=start;
        printf("\nThe list elements are:\t");
        while(ptr!=NULL)
        {
            printf("%d\t",ptr->info);
            ptr=ptr->next;
        }
    }
}



void insert_begin()
{
    struct node *temp,*ptr;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data value for the node:\t");
    scanf("%d",&temp->info);
    if(start==NULL)
    {
        start=temp;
        temp->next=NULL;
    }
    else
    {
        temp->next=start;
        start=temp;
    }
}

void insert_end()
{
    create();
}

void insert_pos()
{
    struct node *temp,*ptr;
    int i,pos;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the position for the new node to be inserted: ");
    scanf("%d",&pos);
    printf("\nEnter the data value for the node:");
    scanf("%d",&temp->info);
    if(pos==0)
    {
        temp->next=start;
        start=temp;
    }
    else
    {
        for(i=1,ptr=start;i<pos-1;i++)
        {
            ptr=ptr->next;
            if(ptr==NULL)
            {
                printf("\nPosition not found");
                return;
            }
        }
        temp->next=ptr->next;
        ptr->next=temp;
    }
}


void delete_begin()
{
    struct node *ptr;
    if(start==NULL)
    {
        printf("\n List is empty:\t");
        return;
    }
    else
    {
        ptr=start;
        start=start->next;
        printf("The deleted element is:%d\t",ptr->info);
        free(ptr);
    }
}

void delete_end()
{
    struct node *temp,*ptr;
    if(start==NULL)
    {
        printf("\n List is empty:\t");
        return;
    }
    else if(start->next==NULL)
    {
        ptr=start;
        start=NULL;
        printf("The deleted element is:%d\t",ptr->info);
        free(ptr);

    }
    else
    {
        ptr=start;
        while(ptr->next!=NULL)
        {
            temp=ptr;
            ptr=ptr->next;
        }
        temp->next=NULL;
        printf("The deleted element is:%d\t",ptr->info);
        free(ptr);
    }
}


void delete_pos()
{
    struct node *temp,*ptr;
    int i,pos;
    printf("\nEnter the position for the new node to be deleted: ");
    scanf("%d",&pos);
    if(start==NULL)
    {
        printf("\n List is empty:\t");
        return;
    }
    else if(pos==1)
    {
        ptr=start;
        start=start->next;
        printf("The deleted element is:%d\t",ptr->info);
        free(ptr);

    }
    else
    {
        for(i=1,ptr=start;i<pos;i++)
        {
            temp=ptr;
            ptr=ptr->next;
            if(ptr==NULL)
            {
                printf("\nPosition not found");
                return;
            }
        }
        temp->next=ptr->next;
        printf("The deleted element is:%d\t",ptr->info);
        free(ptr);
    }
}
