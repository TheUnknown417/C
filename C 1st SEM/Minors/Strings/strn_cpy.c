// strcpy , strncpy
void strn_copy(char b[], char a[] , int kitnay_chrs);
void strn_copy1(char b[], char a[] ,int kha_say ,  int kitnay_chrs);
#include<stdio.h>
#include<string.h>

int main()
{
    int how_many, from_where;
    char a[100];
    char b[100];

    printf("Enter a string with spaces (max 100 characters) :\n");
    gets(a);


    printf("Enter the index from where u want to start copying :");
    scanf("%d",&from_where);

    printf("Enter how many characters u want to copy from the above mentioned index :");
    scanf("%d",&how_many);

    strn_copy1(b,a,from_where,how_many);
    puts(b);



return 0;

}

/*void strn_copy(char b[], char a[] , int kitnay_chrs)
{

    for(int i=0; i<kitnay_chrs;i++)
    {
        b[i]=a[i];
    }
    b[kitnay_chrs]='\0';

}*/
void strn_copy1(char b[], char a[] ,int kha_say ,  int kitnay_chrs)
{
    int j=0;
    for(int i=kha_say ; i<=kitnay_chrs+kha_say;i++)
    {
        b[j]=a[i];
        j++;
    }
    b[j]='\0';

}






