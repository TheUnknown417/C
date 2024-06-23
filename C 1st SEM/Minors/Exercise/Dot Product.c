#include<stdio.h>
int dot_product(int a[],int b[],int s);

int main()
{
    int s,z;

    // creating an array (taking values from user)
    printf("Enter the size of array ");
    scanf("%d",&s);
    int arr[s],arr1[s];

    //creating 1st array
    printf("\nNow Enter the elements of 1st array\n");
    for(int i=0; i<s ; i++)
    {
        printf("Enter next element ");
        scanf("%d",&arr[i]);
    }

    printf("\n\nNow Enter the elements of 2nd array\n\n");

    //creating 2nd array
    for(int i=0; i<s ; i++)
    {
        printf("Enter next element ");
        scanf("%d",&arr1[i]);
    }

    // calling the sum function
    z=dot_product(arr,arr1,s);
    printf("\nThe dot product of the given two arrays is %d ",z);

}

int dot_product(int a[],int b[],int s)// this function is accepting an array as parameter and returning the sum of all elements in it , s is the size pf array
{
    int dot_pro;
    for(int i=0 ; i<s ; i++)
    {
      dot_pro+=a[i]*b[i];

    }
      return dot_pro;
}
