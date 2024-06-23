#include <stdio.h>
#include <string.h>

#define MAX_LEN 100
#define MAX_BOOKS 10

int n_bks = 0;

typedef struct {
    char t[MAX_LEN];
    char a[MAX_LEN];
    int py;
} lib;

void Add_book(lib *ptr) {
    printf("Enter Name of Book: ");
    fgets(ptr->t, sizeof(ptr->t), stdin);
    ptr->t[strcspn(ptr->t, "\n")] = '\0'; // Remove newline character if present

    printf("Enter Name of Author: ");
    fgets(ptr->a, sizeof(ptr->a), stdin);
    ptr->a[strcspn(ptr->a, "\n")] = '\0'; // Remove newline character if present

    printf("Enter Publish Year: ");
    scanf("%d", &ptr->py);
    getchar(); // Consume newline character left by scanf

    printf("Successfully Entered...\n\n");
}

void Display_book(lib *ptr) {
    printf("Name of Book   : %s\n", ptr->t);
    printf("Name of Author : %s\n", ptr->a);
    printf("Publish Year   : %d\n\n", ptr->py);
}

void Search_Book(lib b[]) {
    char s[MAX_LEN];
    printf("Enter the title you want to search: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0'; // Remove newline character if present

    for (int i = 0; i < n_bks; i++) {
        if (strcmp(s, b[i].t) == 0) {
            printf("Book found!\n");
            printf("Book Title: %s\n", b[i].t);
            printf("Book Author: %s\n", b[i].a);
            printf("Publication Year: %d\n\n", b[i].py);
            return;
        }
    }
    printf("Book not found.\n\n");
}

int main() {
    lib books[MAX_BOOKS];

    while (1) {
        printf("1. ADD BOOK\n");
        printf("2. DISPLAY BOOKS\n");
        printf("3. SEARCH BOOK\n");
        printf("0. EXIT\n");
        printf("Choose an option from the above menu: ");

        int choice;
        scanf("%d", &choice);
        getchar(); // Consume newline character left by scanf

        switch (choice) {
            case 1:
                if (n_bks < MAX_BOOKS) {
                    printf("Enter the Data for Book %d\n", n_bks + 1);
                    Add_book(&books[n_bks]);
                    n_bks++;
                } else {
                    printf("Limit Reached\n\n");
                }
                break;
            case 2:
                for (int i = 0; i < n_bks; i++) {
                    Display_book(&books[i]);
                }
                break;
            case 3:
                Search_Book(books);
                break;
            case 0:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    }
}


