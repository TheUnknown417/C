#include<stdio.h>

int fib(int n)
{
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    else
        return fib(n-1)+fib(n-2);
}
int main()
{

// printing fib series by index number ;
/* int sum=0;
    for(int i=0 ; i<5;i++)
    {
        int res=fib(i);
        sum+=res;
        printf("%d\n",res);

    }
    printf("Sum of fib series %d",sum);

*/

// printing fib series until a number is reached
 int i=0;
while(1)
{

    int res=fib(i);
    if(res<100)
       {
          printf("%d\n",res);
        i++;
       }
    else
        break;
}


}
