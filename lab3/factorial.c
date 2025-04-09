#include <stdio.h>
#include <stdlib.h>

int factorial(int n)
{
    while(n==1 || n==0)
    {
        return n;
    }
    return n*factorial(n-1);
}

int main ()
{
    int num;
    printf("Enter the positive number to find the factorial: ");
    scanf("%d",&num);
    if(num<0)
    {
        exit(1);
    }
    int result = factorial(num);
    printf("The factorial of %d is %d",num,result);
}