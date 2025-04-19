/*
 * Program Name    : two_d_array.c
 * Author          : Nishanth Narayanan Kp
 * Date            : 2025-04-13
 * Description     : Demonstrates the use of a 2D array in C without using pointers.
 *                   Initializes a 2D array, takes user input, and prints the matrix.
 */

#include <stdio.h>

#define ROWS 3
#define COLS 4

int main() {
    int matrix[ROWS][COLS];  // Declare 2D array
    int i, j;

    // Input elements
    printf("Enter %d elements for a %dx%d matrix:\n", ROWS * COLS, ROWS, COLS);
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Print matrix
    printf("\nMatrix:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}


/*
 * Metric	Complexity
 * Time Complexity	O(n × m)
 * Space Complexity	O(n × m)
 *
 * Implementation types: 
 *
 * Row - Major
 * 	Address = base + ((i * total_columns) + j) * size_of_element
 *
 * 	1 2 3
 * 	4 5 6
 * 	7 8 9
 *
 * stored in memory address :
 * 	[1][2][3][4][5][6][7][8][9]
 *
 * Column - Major
 * 	Address = base + ((j * total_rows) + i) * size_of_element
 *
 *STored in memory as : [1][4][7][2][5][8][3][6][9]
 */

