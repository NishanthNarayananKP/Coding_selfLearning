#include <stdio.h>
#include <stdlib.h>

/*
 * Program Name    : 2DArrayAllocationInFunction.c
 * Author          : Nishanth Narayanan Kp
 * Date            : 2025-04-19
 * Description     : This program demonstrates how to dynamically allocate a 2D array 
 *                   inside a function and access it in the `main` function. The program 
 *                   initializes the array, prints it, and frees the allocated memory.
 *
 * Steps:
 * 1. Dynamically allocate memory for the 2D array inside a separate function.
 * 2. Initialize the array with values inside the function.
 * 3. Access and print the array inside `main`.
 * 4. Free the dynamically allocated memory inside the `main`.
 */

// Function to dynamically allocate and initialize the 2D array
void allocateAndInitializeArray(int ***arr, int rows, int cols) {
    // Dynamically allocate memory for an array of pointers (each pointing to a row)
    *arr = (int **)malloc(rows * sizeof(int *));
    
    // Dynamically allocate memory for each row
    for (int i = 0; i < rows; i++) {
        (*arr)[i] = (int *)malloc(cols * sizeof(int));
    }
    
    // Initialize the 2D array with values
    int value = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            (*arr)[i][j] = value++;
        }
    }
}

// Function to free the allocated memory
void freeArray(int ***arr, int rows) {
    for (int i = 0; i < rows; i++) {
        free((*arr)[i]);
    }
    free(*arr);
}

int main() {
    int rows = 3, cols = 3;
    int **arr = NULL;
    
    // Call the function to allocate and initialize the array
    allocateAndInitializeArray(&arr, rows, cols);
    
    // Print the 2D array
    printf("2D Array using double pointers:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    
    // Free the dynamically allocated memory
    freeArray(&arr, rows);
    
    return 0;
}

