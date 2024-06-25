#include <stdio.h>

// Function prototype
void reverse_arr(int arr[], int len);

int main() {
    int arr[] = {1, 2, 3, 4};
    int len = sizeof(arr) / sizeof(arr[0]);

    // Print the original array
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Reverse the array
    reverse_arr(arr, len);

    // Print the reversed array
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
// with temp
void reverse_arr(int arr[], int len) {
    int *start = arr;
    int *end = arr + len - 1;

    while (start < end) {
        // Swap the elements
        int temp = *start;
        *start = *end;
        *end = temp;

        // Move the pointers
        start++;
        end--;
    }
}

/*
// without temp
void reverse_arr(int arr[], int len) {
    int *start = arr;
    int *end = arr + len - 1;

    while (start < end) {
        // Swap elements using arithmetic operations
        *start = *start + *end;
        *end = *start - *end;
        *start = *start - *end;

        // Move the pointers
        start++;
        end--;
    }
}

*/
