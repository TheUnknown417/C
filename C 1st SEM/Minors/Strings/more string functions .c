// strlen , strcat, strncat , strcmp;

#include<stdio.h>
#include<string.h>

int main()
{
 /*   char arr[100]="Hello";
    char *arr1="Worldtimes";

    printf("%d",strlen(arr1));
     printf("\n%d",strlen(arr));

     char a[20]="DAOUD";
     char b[10]=" HAROON";

     strcat(a,b);  // a will change into a+b
     printf("\n%d \n%s ",strlen(a),a);

     char c[30]="DAOUD";
     char d[20]=" DAR HAROON";

    strncat(c,&d[4],7);
    printf("\n%d \n%s ",strlen(c),c);

    char p[20]="ZemoT";
    char q[20]="Qemo";

    */
   int x= strcmp(p,q)

   if(x==0)
   {
       printf("The two strings are same ");
   }

   else if(x<0)
   {
       if(strlen(p)<strlen(q))
        printf("S1 < S2 cuz of of its size ");
       else
        printf(" S1 < S2 because of ASCII codes ");
   }

   else
   {
       if(strlen(p)>strlen(q))
        printf(" S1 > S2 cuz of of its size ");
       else
        printf(" S1 > S2 because of ASCII codes ");
   }


}


