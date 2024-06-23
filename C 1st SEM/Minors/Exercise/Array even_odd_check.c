// arrays
void Create_array();
void Display_array(int a[],int s);
void check_even(int a[],int s);
#include<stdio.h>
#define S 8
int main()
{

    // Even odd count check
    printf("your array is of length %d \n",S);
    int arr1[S];
    int even_count=0 , odd_count=0;

    for(int i=0 ; i<S ; i++)
    {
        printf("Enter element %d : ",i+1);
        scanf("%d",&arr1[i]);

    }

    for(int i=0 ; i<S ; i++)
    {
        if(arr1[i]%2==0)
        {
            even_count++;
        }
        else
            odd_count++;
    }

    printf("your array has %d even elements\n",even_count);
printf("your array has %d odd elements",odd_count);
printf("\n\n");

// for identifying each element separately
printf("Now checking a user-defined array's elements separately \n\n");
     Create_array();


}

void Create_array()
{
    int n;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    int arr[n];

    for(int i =0 ; i<n ; i++)
    {
        printf("Enter the element %d :  ",i+1);
        scanf("%d",&arr[i]);
    }

    Display_array(arr,n);
    check_even(arr,n);
}

void Display_array(int a[],int s)
{
    printf("[");
    for(int i=0 ; i<s ;i++)
    {
        printf("%d,",a[i]);
    }
    printf("]\n");
}

void check_even(int a[],int s)
{
    for(int i =0;i<s;i++)
    {
        if(a[i]%2==0)
            printf("%d is even\n",a[i]);
        else
            printf("%d is odd\n",a[i]);
    }
}










