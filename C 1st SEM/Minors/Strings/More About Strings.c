//  Ex 1 { String Tokenization}
/*

#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
char a[50];
printf("Enter the name of organization:\n");
gets(a);

printf("\nThe name of the organization is %s ",a);
printf("and its abbreviation is ");
char *b=strtok(a," ");
while(b!=NULL)
{

    printf("%c",b[0]);
    b=strtok(NULL," ");

}
return 0;
}*/

/*
//  Ex 2 { String function self implementation }
#include<stdio.h>
#include<string.h>
int str_len(const char arr[]);
void str_copy(char s1[], const char s2[]);
void str_cat(char s1[], const char s2[]);

int str_len_p(const char arr[]);
void str_copy_p(char s1[], const char s2[]);
void str_cat_p(char s1[], const char s2[]);
int main()

{
    // implementing strlen
    char str[]="Hello World";
    int y=str_len(str);

    int x=str_len_p(str);     // the function using pointer

    printf("The length of string is %d\n",x);
    printf("The length of string is %d\n",y);

    // implementing strcpy
    char a[]="Daoud Haroon Dar";
    char b[(int)strlen(a)+1]; // 1 is added to store null character
    char c[(int)strlen(b)+1];

    str_copy(b,a);
   printf("The copied String 'b' is : "); puts(b);

   str_copy_p(c,b); // using the function working with pointers
   printf("The copied String 'c' is : "); puts(c);


    // implementing strcat
    char e[20]="Mouse "; // here we initially defined the size of array greater cuz it has to store the characters of the other array as well
    char f[20]="Keyboard";
    char g[]=" Printer";
    str_cat(e,f);
    printf("Concatenated string 'e' : ") ; puts(e);

    str_cat_p(f,g);
    printf("Concatenated string 'F' : ") ; puts(f);


}
// function self definition
int str_len(const char arr[])
{
    int i;
    for(i=0 ; arr[i]!='\0';i++);

    return i;
}

void str_copy(char s1[], const char s2[])
{
    int i;
    for(i=0; s2[i]!='\0';i++)
    {
        s1[i]=s2[i];
    }
    s1[i]='\0';
}

void str_cat(char s1[], const char s2[])
{
    int i,j;
    for(i=(int)strlen(s1) , j=0 ;    s2[j]!='\0'   ; i++)
    {
        s1[i]=s2[j];
        j++;
    }
}

// now creating the same functions using pointers
// array name can also act as pointers ( char arr[] can also be written as char *arr)
int str_len_p(const char arr[])
{
    int len=0;
    while(*arr!='\0')   // array name , array k first element ka reference/address hota , and * will dereference that address
    {
        arr++;  // base address increase hota jy ga , in simple words shifting to next indexes on each increment
        len++;
    }
    return len;
}
void str_copy_p(char s1[], const char s2[])
{
    while(*s2!='\0')
    {
        *s1=*s2;
        s1++;
        s2++;
    }

    *s1='\0'; // here the address of s1 is that where null character should be placed
}

void str_cat_p(char s1[], const char s2[])
{
    while(*s1!='\0')
    {
        s1++;
    }
    //after coming out of the loop the address of s1 will be pointing to the the memory box containing the null character

    while(*s2!='\0')
    {
        *s1=*s2;
        s1++;
        s2++;
    }
    *s1='\0';
}
*/




//  Ex 3 { Practice Program }

#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    char str[200];
    printf("Enter your string : \n");
    gets(str);
    int vowels=0,consonants=0,digits=0,spaces=0,others=0;
     int As=0,Es=0,Is=0,Os=0,Us=0;

    char *ptr=str;

    while(*ptr!='\0')
    {
        if(isspace(*ptr))
        {
            spaces++;
            ptr++;
        }

        else if(isdigit(*ptr))
        {
            digits++;
            ptr++;
        }

        else if(isalpha(*ptr))
        {

            if(*ptr=='a' || *ptr=='e' || *ptr=='i' || *ptr=='o' || *ptr=='u' || *ptr=='A' || *ptr=='E' || *ptr=='O' || *ptr=='I' || *ptr=='U')
            {
                        vowels++;
                        *ptr=toupper(*ptr);

                        if(*ptr=='A')
                        {
                            As++;
                            ptr++;
                        }
                        else if(*ptr=='E')
                        {
                            Es++;
                            ptr++;
                        }
                        else if(*ptr=='I')
                        {
                            Is++;
                            ptr++;
                        }
                        else if(*ptr=='O')
                        {
                            Os++;
                            ptr++;
                        }
                        else if(*ptr=='U')
                        {
                            Us++;
                            ptr++;
                        }

            }

            else
            {
                consonants++;
                ptr++;

            }
        }

        else
        {
            others++;
            ptr++;
        }


}



    printf("\nDigits     : %d",digits);
    printf("\nSpaces     : %d",spaces);
    printf("\nOthers     : %d",others);
    printf("\nConsonants : %d",consonants);
    printf("\nVowels     : %d",vowels);
    printf("\nTotal A or a  : %d",As);
    printf("\nTotal E or e  : %d",Es);
    printf("\nTotal I or i  : %d",Is);
    printf("\nTotal O or o  : %d",Os);
    printf("\nTotal U or u  : %d",Us);

}




/*
// Ex 4 { Practice Program  }
#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    char str[100];
    printf("Enter your string\n");
    gets(str);
   int i,j;
    for( i=0, j=0 ; str[i]!='\0'; i++)
    {
        if(isalpha(str[i]) || isspace(str[i]))  // use of isspace() depends upon situation
        {
          str[j]=str[i];
          j++;
        }
    }
    str[j]='\0';

   printf("String after removing non-alphabetic characters: %s",str);

//   // can also be done using pointers
//    char  *src , *dest ;
//    src = str;
//    dest = str ;
//
//    while( *src!= '\0')
//    {
//        if(isalpha(*src) || isspace(*src))  // use of isspace() depends upon situation
//        {
//                *dest = *src ;
//                dest++;
//
//        }
//    src++;
//
//
//    }
//    *dest = '\0';
//
//     printf("String after removing non-alphabetic characters: %s",str);

}

*/


/*

 //Ex 5 { Practice Program Encryption }
//The encryption criteria for the given code involve shifting each uppercase alphabetic character in the input string by three positions forward in the alphabet.
// Specifically, if a character is 'X', 'Y', or 'Z', it wraps around to 'A', 'B', or 'C', respectively.
// Non-alphabetic characters, such as whitespace and digits, are not altered during this process


#include<stdio.h>-*
#include<string.h>
#include<ctype.h>
int main()
{
    char str[100];
    printf("Note : program gives valid output only for UpperCase letters\n");
    printf("Enter your string for Encryption : ");
    gets(str);
    int i;
    for(i=0  ; str[i]!='\0'; i++)
    {
    if(isalpha(str[i]))
    {
        if(str[i]=='X' || str[i]=='Y' || str[i]=='Z')
        {
            if(str[i]=='X')
                str[i]='A';
            else if(str[i]=='Y')
                str[i]='B';
            else
                str[i]='C';
        }

        else
            str[i]=str[i]+3;
    }

    else
        continue ; // to avoid encryption of  white space and digits
    }

    printf("Encrypted String :"); puts(str);
}
*/
