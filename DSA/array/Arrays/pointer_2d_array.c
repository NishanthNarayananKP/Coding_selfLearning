/*
 * Program Name    : pointer_2d_array.c
 * Author          : Nishanth Narayanan Kp
 * Date            : 2025-04-13
 * Description     : Demonstrates how to work with 2D arrays using pointers in C.
 *                   Includes accessing and printing elements using both indexing
 *                   and pointer arithmetic.
 */

#include <stdio.h>

#define ROWS 3
#define COLS 3

void print_with_indexing(int arr[ROWS][COLS]);
void print_with_pointers(int *arr, int rows, int cols);

int main() {
    int matrix[ROWS][COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printf("Access using array indexing:\n");
    print_with_indexing(matrix);

    printf("\nAccess using pointer arithmetic:\n");
    print_with_pointers(&matrix[0][0], ROWS, COLS);

    return 0;
}

// Print using normal array indexing
void print_with_indexing(int arr[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

// Print using pointer arithmetic
void print_with_pointers(int *arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", *(arr + i * cols + j) ); // LInear indexing . directly calculates address and access element
	    // * ((arr + i) + j):  Moves to ith row first then moves to jth column in it
        }
        printf("\n");
    }
}

