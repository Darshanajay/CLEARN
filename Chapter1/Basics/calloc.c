#include <stdio.h>
#include <stdlib.h>  // Required for calloc and free functions

int main() {
    int *arr;
    int n = 5;

    // Allocate memory for an array of 5 integers using calloc
    // calloc initializes the allocated memory to 0
    arr = (int*)calloc(n, sizeof(int));

    // Check if memory allocation was successful
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Print the default initialized array elements (all zeros)
    printf("Array elements after calloc: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Assign values to the allocated array
    for (int i = 0; i < n; i++) {
        arr[i] = (i + 1) * 10;
    }

    // Print modified array elements
    printf("Modified array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(arr);

    return 0;
}