#include <stdio.h>
int HCF_by_div(int x ,int y);
int main()
{
    int x,y;

    printf("Enter your first number : ");
    scanf("%d",&x);

    printf("Enter your second number : ");
    scanf("%d",&y);
    int result=HCF_by_div(x,y);
    printf("The HCF of %d and %d is %d",x,y,result);
}

int HCF_by_div(int x ,int y)
{
    while(y!=0)
    {
        int rem=x%y;
        x=y;
        y=rem;
    }

   return x;
}
