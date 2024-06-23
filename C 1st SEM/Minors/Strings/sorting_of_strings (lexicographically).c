 //  sorting of strings

 #include<stdio.h>
 #include<string.h>

 int main()
 {
     char arr[5][20];
     char temp[20];
     printf("Enter 5 words \n");

    //putting words in the array
    for(int i=0 ; i<5 ; i++)
    {
        gets(arr[i]); // can also use scanf("%s",arr[i]);
    }

    // sorting the array

    for(int i=0 ; i<5 ; i++)
    {
        for(int j=0 ; j<5-i-1 ; j++)
        {
            if(strcmp(arr[j],arr[j+1])>0)
            {
                strcpy(temp,arr[j]);
                strcpy(arr[j],arr[j+1]);
                strcpy(arr[j+1],temp);
            }
        }
    }

    //printing the sorted array
    printf("\nIn lexicographical order: \n");
    for(int i=0 ; i<5 ; i++)
        puts(arr[i]);



 }


