/*
 * Program Name    : 7_quick_sort.c
 * Author          : Nishanth Narayanan Kp
 * Date            : 2025-04-13
 * Description     : Implements Quick Sort using Hoare partition scheme.
 *                   Uses start++ and end-- pointer-like logic to partition array.
 */

#include <stdio.h>

#define SIZE 10

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Hoare partition function
int hoare_partition(int arr[], int start, int end) {
    int pivot = arr[start];  // Choose first element as pivot
    int left = start - 1;
    int right = end + 1;

    while (1) {
        // Move left to the right until an element >= pivot is found
        do {
            left++;
        } while (arr[left] < pivot);

        // Move right to the left until an element <= pivot is found
        do {
            right--;
        } while (arr[right] > pivot);

        if (left >= right)
            return right;

        swap(&arr[left], &arr[right]);
    }
}

// Quick sort using Hoare scheme
void quick_sort(int arr[], int start, int end) {
    if (start < end) {
        int pi = hoare_partition(arr, start, end);
        quick_sort(arr, start, pi);       // Note: pi instead of pi - 1
        quick_sort(arr, pi + 1, end);
    }
}

// Main function
int main() {
    int arr[SIZE] = {11, 14, 6, 52, 47, 25, 1, 98, 21, 8};

    quick_sort(arr, 0, SIZE - 1);

    printf("Sorted Array:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d  ", arr[i]);
    }
    printf("\n");

    return 0;
}


/*
 *
 * Time : O(nlogn)
 * space : O(1)
 */

