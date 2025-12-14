#include <stdio.h>
#include <stdlib.h>  // Required for malloc and free functions

int main() {
    int *ptr;  // Pointer to int, will hold the address of allocated memory
    int n = 5; // Number of integers to allocate memory for

    // Allocate memory to store n integers using malloc
    // sizeof(int) gives the size of one integer in bytes
    ptr = (int*)malloc(n * sizeof(int));

    // Check if malloc returned NULL, which means memory allocation failed
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1; // Exit the program with error code
    }

    // Use the allocated memory - here we initialize the array
    for (int i = 0; i < n; i++) {
        ptr[i] = (i + 1) * 10;  // Assign values 10, 20, 30, 40, 50 to array elements
    }

    // Print the values stored in the dynamically allocated memory
    printf("Allocated array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    // Free the allocated memory once it is no longer needed to avoid memory leaks
    free(ptr);

    return 0; // Program ended successfully
}