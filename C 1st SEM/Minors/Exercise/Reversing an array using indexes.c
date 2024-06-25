#include <stdio.h>

// Function prototype
void reverse_arr(int arr[], int len);

int main() {
    int arr[] = {1, 2, 3, 4,5,6,7,8,9,10};
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
/*
// with temp
void reverse_arr(int arr[], int len) {

        for(int i = 0,j=len-1  ; i<len/2 ; i++)
        {
            int temp ;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j]= temp;
            j--;


        }




}*/

// without temp
void reverse_arr(int arr[], int len) {

        for(int i = 0,j=len-1  ; i<len/2 ; i++)
        {
            arr[i] = arr[i] + arr[j];
            arr[j] = arr[i] - arr[j];;
            arr[i]= arr[i] - arr[j];;
            j--;


        }




}

