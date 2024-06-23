#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 25

typedef struct {
    char name[MAX_NAME_LENGTH];
    int account_NO;
    float balance;
} data;

int main() {
    int choice;
    data members[5];

    FILE *fptr = fopen("bankdata.txt", "r");
    if (fptr == NULL) {
        printf("File not present");
        return 0;
    }
    for(int i=0 ;i<5 ;i++)
    {
         fscanf(fptr, "%d\t%s\t\t%f", &members[i].account_NO, members[i].name, &members[i].balance);
    }


/* Displaying all the data of the file , stored in Struct members
    for(int i=0 ;i<5 ;i++)
    {
         printf("%d\t%s\t\t%.2f\n",members[i].account_NO, members[i].name,members[i].balance);
    }

    fclose(fptr);*/


    do {
        printf("1_ List accounts with zero balance\n");
        printf("2_ List accounts with credit balance\n");
        printf("3_ List accounts with debit balance\n");
        printf("0_ End of Run\n");
        printf("Enter your choice from the above options : ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Accounts with 0 balance :\n");
            for (int i = 0; i < 5; i++) {
                if (members[i].balance == 0) {
                    printf("%d\t%s\t\t%.2f\n", members[i].account_NO, members[i].name, members[i].balance);
                }
            }
            break; // Add break statement

        case 2:
            printf("Account with credit balance :\n");
            for (int i = 0; i < 5; i++) {
                if (members[i].balance < 0) {
                    printf("%d\t%s\t\t%.2f\n", members[i].account_NO, members[i].name, members[i].balance);
                }
            }
            break; // Add break statement

        case 3:
            printf("Account with debit balance :\n"); // Corrected the print statement
            for (int i = 0; i < 5; i++) {
                if (members[i].balance > 0) {
                    printf("%d\t%s\t\t%.2f\n", members[i].account_NO, members[i].name, members[i].balance);
                }
            }
            break; // Add break statement

        case 0:
            printf("END OF RUN\n");
            break; // Add break statement

        default:
            printf("Invalid choice. Please enter a number between 0 and 3.\n");
        }

    } while (choice != 0);

    return 0;
}

