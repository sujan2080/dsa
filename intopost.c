#include<stdio.h>
#include<conio.h>
#include<string.h>
#define max 30

struct stack
{
    char item[max];
    int top;
}st;

void infix_to_postfix(char *);
void push(char);
char pop();
int prec(char);

int main()
{
    char infix[30];
    printf("\nEnter the infix expression:");
    gets(infix);
    infix_to_postfix(infix);
    return 0;
}

void infix_to_postfix(char infix[])
{
    int length;
    static int index=0, pos=0;
    char symbol,temp;
    char postfix[50];
    length=strlen(infix);
    while(index < length)
    {
        symbol=infix[index];
        switch(symbol)
        {
            case '(' : push(symbol);
            break;

            case ')' : temp =pop();
            while (temp != '(')
            {
                postfix[pos]=temp;
                pos++;
                temp=pop();
            }
            break;

            case '+':
            case '-' :
            case '*' :
            case '/' :
                while(prec (st.item[st.top]) >= prec(symbol))
                {
                    temp=pop();
                    postfix [pos]=temp;
                    pos++;
                }
                push(symbol);
                break;

            default:
                postfix[pos++]=symbol;
                break;
        }
        index++;
    }
    while(st.top >= 0)
    {
        temp=pop();
        postfix[pos++] =temp;
    }
    postfix[pos++]='\0';
    printf("\nEquivalent postfix expression is:\n");
    puts(postfix);
    return ;
}

void push(char sym)
{
    if(st.top >= max-1)
    {
        printf("\nStack is overflow");
        return;
    }
    else
    {
        st.top=st.top+1;
        st.item[st.top]=sym;
    }
}

char pop()
{
    char i;
    if (st.top == -1)
    {
        printf("\nStack is empty");
        return (0);
    }
    else
    {
        i=st.item[st.top];
        st.top=st.top-1;
    }
    return (i);
}

int prec(char ch)
{
    if(ch=='^')
    {
        return (5);
    }

    else if(ch == '*' || ch =='/')
    {
        return (4);
    }

    else if(ch == '+' || ch =='-')
    {
        return (3);
    }

    else
    {
        return (2);
    }


}
