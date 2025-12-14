#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;
    int initial_size = 5;
    int new_size = 10;

    // Allocate memory for initial_size integers using malloc
    ptr = (int*)malloc(initial_size * sizeof(int));
    
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Initialize the array
    for (int i = 0; i < initial_size; i++) {
        ptr[i] = (i + 1) * 10;
    }

    printf("Original array elements: ");
    for (int i = 0; i < initial_size; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    // Reallocate memory to hold new_size integers
    int *temp = (int*)realloc(ptr, new_size * sizeof(int));
    if (temp == NULL) {
        printf("Memory reallocation failed\n");
        free(ptr);  // Free original memory if realloc fails
        return 1;
    }
    ptr = temp;

    // Initialize new elements in the reallocated memory
    for (int i = initial_size; i < new_size; i++) {
        ptr[i] = (i + 1) * 10;
    }

    printf("Array elements after realloc: ");
    for (int i = 0; i < new_size; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(ptr);

    return 0;
}
