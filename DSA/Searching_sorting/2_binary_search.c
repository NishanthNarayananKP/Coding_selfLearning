/*
 * Program Name    : binary_search.c
 * Author          : Nishanth Narayanan Kp
 * Date            : 2025-04-11
 * Description     : Implements binary search on a sorted integer array.
 *                   Efficiently searches for a target number and returns its index if found.
 */

#include <stdio.h>

#define SIZE 10

int binary_search(int arr[], int size, int target);

int main() {
    int array[SIZE] = {5, 12, 18, 23, 34, 45, 56, 67, 78, 90};  // Sorted array
    int target;

    printf("Enter the number to search: ");
    scanf("%d", &target);

    int index = binary_search(array, SIZE, target);

    if (index != -1) {
        printf("Element %d found at index %d.\n", target, index);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}

// Function to perform binary search
int binary_search(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;  // Prevents potential overflow
	// if reached max value can cause oveflow . high-low /2 will always be less than high hence avoid risk of overflow.
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;  // Element not found
}



/*
 * TIme complexity : 
 * 	Case			Comparisons per Step			Total Steps (Logarithmic)	Time Complexity
 *
 * 	Best Case		1 (target at middle)			1				O(1)
 *	Average			log₂n					log₂n				O(log n)
 *	Worst			log₂n					log₂n				O(log n)
 *
 *
 * SPace complexity :
 *
 * Version	Extra Space Used					Space Complexity
 * Iterative	Uses only a few integer variables (low, high, mid)	O(1)
 * Recursive	Uses stack space for each recursive call		O(log n) (due to call stack depth)
 *
 */

/*
 *
 * # Binary Search Algorithm

* Step 1: Initialize two variables:
  - low = 0
  - high = size - 1

* Step 2: Repeat while low is less than or equal to high
  - Calculate mid = low + (high - low) divided by 2
  - If array[mid] is equal to the target
      - Return mid as the index
  - Else if array[mid] is less than target
      - Set low = mid + 1
  - Else
      - Set high = mid - 1

* Step 3: If the loop ends without finding the element
  - Return -1 to indicate element not found
*/

