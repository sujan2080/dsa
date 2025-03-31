#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
    int choice,n,new_size,i;
    int *ptr=NULL;

    do{
        printf("Select the following\n");
        printf("1.Allocate memory using malloc\n");
        printf("2.Allocate memory using calloc\n");
        printf("3.Allocate memory using realloc\n");
        printf("4.Free allocated memory \n");
        printf("5.Exit\n");
        printf("Enter choice for operation to be performed: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            if(ptr!=NULL)
            {
                printf("Memory is already allocated\n");
                break;
            }
            printf("Enter number of element to allocate: ");
            scanf("%d",&n);
            ptr=(int*)malloc(n*sizeof(int));
            if(ptr==NULL)
            {
                printf("Memory allocation failed\n");
                break;
            }
            printf("Memory allocation using malloc\n");
            for(i=0;i<n;i++)
            {
                printf("Enter number:");
                scanf("%d",&ptr[i]);
            }
            printf("Sorted values: ");
            for(i=0;i<n;i++)
            {
                printf("%d\t",ptr[i]);
            }
            printf("\n");
            break;

        case 2:
             if(ptr!=NULL)
            {
                printf("Memory is already allocated\n");
                break;
            }
            printf("Enter number of element to allocate: ");
            scanf("%d",&n);
            ptr=(int*)calloc(n,sizeof(int));
            if(ptr==NULL)
            {
                printf("Memory allocation failed\n");
                break;
            }
            printf("Memory allocation using calloc\n");
            for(i=0;i<n;i++)
            {
                printf("Enter number:");
                scanf("%d",&ptr[i]);
            }
            printf("Sorted values: ");
            for(i=0;i<n;i++)
            {
                printf("%d\t",ptr[i]);
            }
            printf("\n");
            break;

        case 3:
            if(ptr==NULL)
            {
                printf("No memory is allocated.\n");
                break;
            }
            printf("Enter the new size: ");
            scanf("%d",&new_size);
            ptr=(int*)realloc(ptr,new_size*sizeof(int));
            if(ptr==NULL)
            {
                printf("Memory allocation failed\n");
                break;
            }
            printf("Memory reallocated using realloc\n");
            for(i=0;i<new_size;i++)
            {
                printf("Enter number: ");
                scanf("%d",&ptr[i]);
            }
            n=new_size;
            printf("Sorted value after allocatiion\n");
            for(i=0;i<n;i++)
            {
                printf("%d\t",ptr[i]);
            }
            printf("\n");
            break;

        case 4:
            if(ptr==NULL)
            {
                printf("No memory is allocated\n");
                break;
            }
            free(ptr);
            ptr=NULL;
            printf("Memory freed\n");
            break;

        case 5:
            printf("Exiting program.\n");
            if(ptr!=NULL)
            {
                free(ptr);
            }
            break;


        default:
            printf("Invalid Choice!\n");

        }
    }while(choice!=5);

}
