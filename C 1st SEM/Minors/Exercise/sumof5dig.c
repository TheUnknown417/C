#include<stdio.h>
int find_sum(int x);
int find_sum_by_recursion(int x);
int main()
{
    int n;
    printf("Enter a 5-dig number ");
    scanf("%d",&n);

    int res=find_sum(n);
    printf("The Sum is %d",res);

    int res1=find_sum_by_recursion(n);
       printf("\nThe Sum is %d",res1);
}

int find_sum(int x)
{
    int digit,sum=0;
    while(x>0)
    {
        digit=x%10;
        sum+=digit;
        x/=10;

    }

   return sum;
}

int find_sum_by_recursion(int x)
{
    if(x<10)
        return x;
    else
        return x%10+find_sum_by_recursion(x/10);
}
