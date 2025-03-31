
#include<stdio.h>
#include<stdlib.h>

int factorial(int n)
{

    if(n==1)
        return (1);
    else
        return (n*factorial(n-1));
}

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d",&num);
    printf("The factorial is %d",factorial(num));
    return 0;
}




/*
#include<stdio.h>
#include<stdlib.h>

int fib(int n)
{
    if(n==1)
    {
        return 1;
    }
    else if(n==2)
    {
        return 1;
    }
    else
    {
        return (fib(n-1)+fib(n-2));
    }
}

int main()
{
    int num,i;
    printf("Enter fibonacci position number: ");
    scanf("%d",&num);
    for(i=1;i<=num;i++)
    {
        printf("\nThe %dth position fibonacci number is: %d",i,fib(i));
    }
    return 0;
}
*/

/*
#include<stdio.h>
#include<stdlib.h>

void TOH(int n, char x, char y, char z)
{
    if(n>0)
    {
        TOH(n-1,x,z,y);
        printf("\n move disk from %c to %c",x,z);
        TOH(n-1,y,x,z);
    }
}


int main()
{
    int n;
    printf("Enter number of disk: ");
    scanf("%d",&n);
    TOH(n,'S','T','D');
    return 0;
}

*/

/*
#include<stdio.h>
#include<conio.h>


int gcd(int m,int n)
{
    if(n==0)
    {
        return m;
    }
    if(m<n)
    {
        return gcd(n,m);
    }
    return (gcd(n,m%n));
}

void main()
{
    int m,n,result;
    printf("Enter two numbers: ");
    scanf("%d %d",&m,&n);
    result = gcd(m,n);
    printf("The GCD (%d %d)=%d\n",m,n,result);
    return 0;
}
*/
