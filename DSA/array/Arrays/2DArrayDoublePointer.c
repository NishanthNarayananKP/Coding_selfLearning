#include <stdio.h>
#include <stdlib.h>

/*
 * Program Name    : 2DArrayDoublePointer.c
 * Author          : Nishanth Narayanan Kp
 * Date            : 2025-04-19
 * Description     : This program demonstrates the creation and manipulation of a 2D array 
 *                   using double pointers in C. The program dynamically allocates memory 
 *                   for the 2D array, initializes it with values, and prints the array to 
 *                   the console. Finally, it frees the dynamically allocated memory.
 *
 * Steps:
 * 1. Dynamically allocate memory for an array of pointers (each pointing to a row).
 * 2. Dynamically allocate memory for each row.
 * 3. Initialize the 2D array with values.
 * 4. Print the 2D array.
 * 5. Free the dynamically allocated memory.
 */

int main() {
    int rows = 3, cols = 3;
    
    // Step 1: Dynamically allocate memory for an array of pointers (each pointing to a row)
    int **arr = (int **)malloc(rows * sizeof(int *));
    
    // Step 2: Dynamically allocate memory for each row
    for (int i = 0; i < rows; i++) {
        arr[i] = (int *)malloc(cols * sizeof(int));
    }
    
    // Step 3: Initialize the 2D array
    int value = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = value++;
        }
    }
    
    // Step 4: Print the 2D array
    printf("2D Array using double pointers:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    
    // Step 5: Free the dynamically allocated memory
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);
    
    return 0;
}

