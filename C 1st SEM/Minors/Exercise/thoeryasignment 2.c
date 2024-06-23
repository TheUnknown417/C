#include<stdio.h>
#include <limits.h>

//function proto types
    int find_largest();
    int find_smallest();
    float Average();
    int Sum();

int main()
{
    // user inputs
    int choice;
    char continueChoice;
    int result_Int;
    float result_Float;

    do {
        printf("Menu:\n");
        printf("1. Find Largest\n");
        printf("2. Find Smallest\n");
        printf("3. Find Sum\n");
        printf("4. Find Average\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice)
         {
            case 1:
                result_Int=find_largest();
                if(result_Int==INT_MIN)
                printf("No number entered");
                else
                printf("the largest number is %d",result_Int);
                break;

            case 2:
                result_Int=find_smallest();
                if(result_Int==INT_MIN)
                printf("No number entered");
                else
                printf("the smallest number is %d",result_Int);
                break;

            case 3:
                result_Int = Sum();
                printf("The sum is %d.\n", result_Int);
                break;

            case 4:
                result_Float = Average();
                printf("the average is %.2f",result_Float);
                break;

            case 5:
                printf("Goodbye!\n");
                return 0;


            default:
                printf("Invalid choice. Please enter a valid option (1-5).\n");
                break;
        }

        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &continueChoice);
        printf("\n\n");
    } while (continueChoice == 'y' || continueChoice == 'Y');

    if(continueChoice=='n' || continueChoice=='N' )
        printf("Program is terminating ....");
    return 0;
}





// SUM FUNCTION
int Sum()
{
    int num,sum=0;
    printf("Enter integers to find Sum OR Enter -1 to Exit\n");  // prompt for user

    while(1)  // working as an infinite loop until sentinel values is entered
    {
        printf("Enter an integer ");
        scanf("%d",&num);

        if(num==-1) // terminating loop for sentinel value
            break;

        sum+=num;
    }

        return sum;

}



// AVERAGE FUNCTION
float Average()
{

    int num,counter=1;
    float avg ,sum_1;
    printf("Enter integers to find Average OR Enter -1 to Exit\n"); // prompt for user

    while(1) // working as an infinite loop until sentinel values is entered
    {
        printf("Enter an integer ");
        scanf("%d",&num);

        if(num==-1) // terminating loop for sentinel value
            break;

        sum_1+=num;
        counter++;


    }
    if(counter==1)  // // to deal with ( if user add -1 for the very first time )
        return 0.0;
    else
    {
        avg=sum_1/(counter-1);
        return avg;
    }


}



// FUNCTION TO FIND LARGEST
int find_largest()
{

    int num,largest=INT_MIN,flag=INT_MIN; // flag is used if the user enters -1 for the very first time
    printf("Enter integers to find Largest OR Enter -1 to Exit\n"); // prompt for user

    while(1) // working as an infinite loop until sentinel values is entered
    {
        printf("Enter an integer ");
        scanf("%d",&num);

        if(num==-1)
            break;

        if(num>largest)
            largest=num;

        flag++;
    }

    if(flag==INT_MIN)
       return flag; // // to deal with ( if user add -1 for the very first time )
    else
     return largest;


}


// FUNCTION TO FIND SMALLEST

int find_smallest()
{

    int num, smallest=INT_MAX , flag=INT_MIN ;// flag is used if the user enters -1 for the very first time
    printf("Enter integers to find Smallest OR Enter -1 to Exit\n"); // prompt for user


    while(1) // working as an infinite loop until sentinel values is entered
    {
        printf("Enter an integer ");
        scanf("%d",&num);

        if(num==-1)
            break;

         if(num<smallest)
            smallest=num;

        flag++;
    }

    if(flag==INT_MIN)
       return INT_MIN; // // to deal with ( if user add -1 for the very first time )
    else
     return smallest;


}
