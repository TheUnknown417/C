#include<stdio.h>
void display_array(int a[],int s);
int main()
{
    int size1,size2;
    printf("Enter the size of array 1 : ");
    scanf("%d",&size1);
    int arr[size1];

    for(int i=0 ; i<size1 ; i++)
    {
        printf(" Enter element %d : ", i+1);
        scanf("%d",&arr[i]);
    }

display_array(arr,size1);

printf("\n\n");

printf("Enter the size of array 2 : ");
    scanf("%d",&size2);

    int arr1[size2];

    for(int i=0 ; i<size2 ; i++)
    {
        printf(" Enter element %d : ", i+1);
        scanf("%d",&arr1[i]);
    }

display_array(arr1,size2);

int arr2[size1+size2];
int size3;

find_union(arr,arr1,arr2,size1,size2,&size3);
printf("\nThe union array is : ");
display_array(arr2,size3);



}






void display_array(int a[],int s)
{
    printf("[");
    for(int i=0 ; i<s ; i++)
    {
        printf("%d,",a[i]);
    }
    printf("]");
}


void find_union(int a[],int b[], int c[],int s1,int s2,int *s3)
{
    //copying the elements of a in c
    int i,j;
    *s3=0;
    for( i=0 ; i<s1 ; i++)
    {
        c[*s3]=a[i];
        (*s3)++;
    }

    // checking if b is the part of c
    for(int i=0 ; i<s2 ; i++)
    {
        int ispresent=0;
        for( j=0 ; j< *s3; j++)
        {
            if(c[j]==b[i])
            {
                ispresent=1;
                break;
            }
        }
         // If the element is not present in array a, add it to array c
        if(!ispresent)
        {
            c[*s3]=b[i];
            (*s3)++;
        }
    }
}


