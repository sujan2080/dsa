#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define maxsize 5


struct stack
{
    int stack[maxsize],top;

}st;

void push();
void pop();
void display();

int main()

{
    int ch=1;
    st.top=-1;

    while(1)
    {
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Terminate");

        printf("\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Terminating program.\n");
            exit(0);

        default:
            printf("Wrong choice. Try again");
        }
    }
}

void push()
{
    int value;

    if(st.top==maxsize-1)
    {
        printf("Stack overflow\n");
        return;
    }
    st.top++;
    printf("Enter value:");
    scanf("%d",&value);
    st.stack[st.top]=value;
    printf("\nElements in stack are:\n");
    display();
}

void pop()
{
    int value;

    if(st.top==-1)
    {
        printf("Stack underflow\n");
        return;
    }
    value=st.stack[st.top];
    printf("Popped value is %d\n",value);
    st.top=st.top-1;

    printf("\nElements in stack are:\n");
    display();
}

void display()
{
    int T,i;
    if (st.top==-1)
    {
        printf("Stack underflow");
        return;
    }
    T=st.top;
    for(i=T;i>=0;i--)
    {
        printf("\t|%d|\n",st.stack[i]);
    }
}

