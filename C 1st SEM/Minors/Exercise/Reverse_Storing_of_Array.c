#include<stdio.h>
#define S 6

int main()
 {
     int x[S],y[S];
       printf("Enter the Elements Of Array of Length 6 \n\n");
     //CREATING ARRAY X
     for(int i=0;i<S;i++)
     {
         printf("Enter element %d : ",i+1);
         scanf("%d",&x[i]);
     }

     //PRINTING ARRAY X
     printf("\n \t   x = ");
     printf("[");
     for(int i=0;i<S;i++)
    {
        if(i==S-1)
        {
              printf("%d]",x[i]);
              break;
        }
        printf("%d,",x[i]);

    }

    //CREATING ARRAY Y ( Reverse order of X  (Not just printing but also stored in reverse order in memory)
    int j=0;
     for(int i=S-1;i>=0;i--)
     {
        y[j]=x[i];
        j++;
     }

     //PRINTING ARRAY Y
     printf("\nReverse of x  = ");
    printf("[");
     for(int i=0;i<S;i++)
    {
        if(i==S-1)
        {
              printf("%d]",y[i]);
              break;
        }
        printf("%d,",y[i]);
    }
 }

