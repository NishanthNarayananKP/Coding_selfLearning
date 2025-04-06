/***************************************************************
 * Author       : Nishanth Narayanan Kp
 * Date         : 2025-04-06 11:55 AM
 * Program Name : array_deletion_static.c
 * Description  : Deletes elements from a static integer array 
 *                at the beginning, end, and a given position 
 *                (1-based index). No pointers or functions used.
 ***************************************************************/

#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE] = {10, 20, 30, 40, 50};
    int size = 5;

    printf("Initial array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    /******************** Deletion at Beginning ********************/
    int pos_beg = 1; // 1-based index

    // Shift elements to the left
    for (int i = pos_beg - 1; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;

    printf("\nAfter deletion at beginning:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    /******************** Deletion at End ********************/
    int pos_end = size; // Last position

    // No need to shift; just reduce size
    size--;

    printf("\nAfter deletion at end:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    /******************** Deletion at Position 2 ********************/
    int pos_mid = 2; // 1-based position = index 1

    for (int i = pos_mid - 1; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;

    printf("\nAfter deletion at position 2:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    /******************** Memory Layout Notes ***********************
     * Assume int = 4 bytes
     * Initial:  [0x1000] = 10, [0x1004] = 20 ...
     * Each delete shifts elements left from deleted index:
     * After 1st delete: 20 30 40 50
     * After 2nd delete: 20 30 40
     * After 3rd delete: 20 40
     ***************************************************************/

    return 0;
}

