#include<stdio.h>
void bin(int a);
int main()
{
    int n;
    printf("Enter a number : ");
    scanf("%d",&n);
    if(n>0)
    bin(n);
    else
        printf("Enter a valid positive integer");

    return 0;
}

void bin(int a)
{
    if(a==0)
    {
        printf("Binary : ");
        return;
    }

    bin(a/2);

    printf("%d",a%2);
}
