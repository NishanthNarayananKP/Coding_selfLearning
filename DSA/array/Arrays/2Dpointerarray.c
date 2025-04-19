#include <stdio.h>
#include <stdlib.h>

/*
 * Program Name    : 2DPointerArray.c
 * Author          : Nishanth Narayanan Kp
 * Date            : 2025-04-19
 * Description     : This program demonstrates the creation and usage of a 2D array
 *                   using an array of pointers (int *p[]). Memory is allocated 
 *                   row-wise and accessed using normal indexing.
 */

#define ROWS 3
#define COLS 3

int main() {
    int *p[ROWS]; // Array of pointers (each pointing to a row)

    // Allocate memory for each row
    for (int i = 0; i < ROWS; i++) {
        p[i] = (int *)malloc(COLS * sizeof(int));
        if (p[i] == NULL) {
            printf("Memory allocation failed at row %d\n", i);
            return 1;
        }
    }

    // Initialize the array with values
    int val = 1;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            p[i][j] = val++;
        }
    }

    // Print the array
    printf("2D Array using int *p[] approach:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < ROWS; i++) {
        free(p[i]);
    }

    return 0;
}

