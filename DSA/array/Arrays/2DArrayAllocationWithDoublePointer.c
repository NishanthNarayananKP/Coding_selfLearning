#include <stdio.h>
#include <stdlib.h>

/*
 * Program Name    : 2DArrayUsingDoublePointer.c
 * Author          : Nishanth Narayanan Kp
 * Date            : 2025-04-19
 * Description     : This program demonstrates the allocation of a 2D array
 *                   using a single pointer in main and passing a double pointer
 *                   to the function. The program uses linear indexing.
 */

// Function to dynamically allocate and initialize the 2D array
void initializeArray(int **arr, int rows, int cols) {
    // Initialize the array with values using linear indexing
    int value = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            *(arr[0] + i * cols + j) = value++;  // Linear indexing using double pointer
        }
    }
}

// Function to free the dynamically allocated memory
void freeArray(int **arr) {
    free(*arr);  // Free the array
}

int main() {
    int rows = 3, cols = 3;

    // Declare a single pointer and allocate memory for the 2D array
    int *arr = (int *)malloc(rows * cols * sizeof(int));  // Memory allocation for rows * columns
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    // Declare a double pointer to pass to the function
    int **arr_ptr = &arr;

    // Initialize the array using the double pointer in the function
    initializeArray(arr_ptr, rows, cols);

    // Print the 2D array using linear indexing
    printf("2D Array using a single pointer and linear indexing:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", *(arr + i * cols + j));  // Access using linear indexing
        }
        printf("\n");
    }

    // Free the dynamically allocated memory
    freeArray(&arr);

    return 0;
}

