#include<stdio.h>
void Circular_shift(int a , int b , int c);
int main()
{
    int a,b,c;
    printf("Enter 3 numbers for circular shift\n");
    printf("a =");
    scanf("%d",&a);
    printf("b =");
    scanf("%d",&b);
    printf("c =");
    scanf("%d",&c);
    Circular_shift(a,b,c);
    return 0;
}

void Circular_shift(int a , int b , int c)
{
    int temp,temp1;
    temp=b;
    b=a;
    temp1=c;
    c=temp;
    a=temp1;

    printf("After Circular Shift : \n ");
    printf("a=%d\n b=%d\n c=%d",a,b,c);
}
