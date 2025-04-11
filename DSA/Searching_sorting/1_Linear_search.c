/*
 * Program Name    : 1_Linear_search.c
 * Author          : Nishanth Narayanan Kp
 * Date            : 2025-04-11
 * Description     : Implements a simple linear search algorithm to find an element in an integer array , returns index
 *                   
 */

#include <stdio.h>

#define SIZE 10

int linear_search(int arr[], int size, int target);

int main() {
    int array[SIZE] = {10, 25, 30, 45, 50, 65, 70, 85, 90, 100};
    int target;

    printf("Enter the number to search: ");
    scanf("%d", &target);

    int index = linear_search(array, SIZE, target);

    if (index != -1) {
        printf("Element %d found at index %d.\n", target, index);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}

// Performs linear search on the array
int linear_search(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return index if found
        }
    }
    return -1; // Return -1 if not found
}


/*
 *	TIme : O(1) : best case at the beginning and worst case : 0(n) in unsoreted arrays . sorted array binary seacrh will be better
 *
 *	Space : O(1) 
 *
 */
