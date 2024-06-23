// reading from file character by character using fgetc
/*
#include<stdio.h>
int main()
{
    //taking file name as a string from user
    char nof[50];
    printf("Enter the name of the file : ");
    gets(nof);

    char ch; // to store the character , which the fgetc will read from the file


    FILE *fptr;

    fptr=fopen(nof,"r");

    if(fptr!=NULL)
    {
        while(!feof(fptr))
        {
            ch=fgetc(fptr);
            printf("%c",ch);
        }
    }
    else
    {
        printf("File Does not exist");
    }
}*/


// reading from a file string by string using fgets
/*#include<stdio.h>
int main()
{
    FILE *fptr;
    fptr=fopen("danish.txt","r");

    if(fptr!=NULL)
    {
        char data[50];  //to store the string , which the fgets will read from the file

        while(!feof(fptr))
        {
            fgets(data,50,fptr); // the length 50 specifies the max number characters that the function can read at one time

            printf("%s\n",data);
        }
    }
    else
    {
        printf("File does not exist");
    }

}*/

/*
// using fscanf()
#include<stdio.h>
int main()
{
    FILE *fptr;
    fptr=fopen("danish.txt","r");

    if(fptr!=NULL)
    {
        char artist[50];
        char track[50];
        int views;

        while(!feof(fptr))
        {
            fscanf(fptr,"%s %s %d",artist,track,&views);

        }
        printf("Singer : %s\nSong : %s\nViews : %d",artist,track,views);
    }
    else
        printf("File does not exist");
}
*/
