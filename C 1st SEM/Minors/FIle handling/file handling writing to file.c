/* writing data on a file character by character using fputc
#include<stdio.h>
#include<string.h>
int main()
{
    char data[50]="HOMOCIDE";




FILE *fptr;
fptr=fopen("daoud.txt","a");

if(fptr!=NULL)
{
    printf("fILE OPENED SUCCESSFULLY");
    rewind(fptr);
    for(int i=0 ; i<strlen(data); i++)
    {
        fputc(data[i],fptr);
        printf("\n%c written successfully",data[i]);
    }
    printf("\nWriting Completed ");


}
else
{
    printf("fILE CANT BE OPENED");
}
}*/

/* writing data on a file string by string using fputs
#include<stdio.h>
int main()
{
    char input[50];
    FILE *fptr;
    fptr=fopen("daoud.txt","w");

    if(fptr!=NULL)
    {
        printf("Enter the content to be written onto the file ; ");
        gets(input);

        fputs(input,fptr);
        printf("Written Successfully");
    }
    else
    {
        printf("Unable to create file");
    }
}*/


//writing data on a file in different formats using fprintf
/*#include<stdio.h>
int main()
{
    char name[50];
    int roll;
    float gpa;

    FILE *fptr;
    fptr=fopen("daoud.txt","a");

    if(fptr!=NULL)
    {
        //inputing data from user
        printf("Enter Your name : ");
        gets(name);

        printf("Enter your Roll Number : ");
        scanf("%d",&roll);

        printf("Enter your GPA : ");
        scanf("%f",&gpa);

        // writing to file

        //fputs("Name",fptr);
        //fprintf(fptr,"\t\t");
        //fputs("Roll_Number",fptr); // fields (headings)  first use "w" to write fields and the data of first student and then use "a" to write data of other students
        //fprintf(fptr,"\t");
        //fputs("GPA",fptr);
        //fprintf(fptr,"\n");




        fprintf(fptr,"%s\t%d\t\t%.2f\n",name,roll,gpa);
        printf("Writing Successfully Completed");
    }
    else
        {
            printf("Unable to create file");
        }
}*/


