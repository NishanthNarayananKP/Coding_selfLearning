/***************************************************************
 * Author       : Nishanth Narayanan Kp
 * Date         : 2025-04-06 11:40 AM
 * Program Name : array_insertion_static.c
 * Description  : Inserts elements into a static integer array 
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

    /******************** Insertion at Beginning ********************/
    int insert_beg = 5;
    int pos_beg = 1; // 1-based position

    // Shift elements to the right
    for (int i = size; i >= pos_beg; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos_beg - 1] = insert_beg;
    size++;

    printf("\nAfter insertion at beginning (5):\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    /******************** Insertion at End ********************/
    int insert_end = 60;
    int pos_end = size + 1; // 1-based

    arr[size] = insert_end; // No shift needed
    size++;

    printf("\nAfter insertion at end (60):\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    /******************** Insertion at Position 3 ********************/
    int insert_pos = 25;
    int pos_mid = 3; // Insert at 3rd position => index 2

    // Shift to the right from end to desired position
    for (int i = size; i >= pos_mid; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos_mid - 1] = insert_pos;
    size++;

    printf("\nAfter insertion at position 3 (25):\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    /******************** Memory Layout Notes ***********************
     * Assume int = 4 bytes
     * Initial:  [0x1000] = 10, [0x1004] = 20 ...
     * Every insert shifts data to the right:
     * After 1st insert: 5 10 20 ...
     * After 3rd insert: 5 10 25 20 30 ...
     ***************************************************************/

    return 0;
}

