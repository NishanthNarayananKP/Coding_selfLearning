/*
 * Program Name    : 8_merge_sort.c
 * Author          : Nishanth Narayanan Kp
 * Date            : 2025-04-13
 * Description     : Implements the Merge Sort algorithm in C.
 *                   Merge Sort is a divide-and-conquer sorting algorithm
 *                   with O(n log n) time complexity.
 */

#include <stdio.h>

#define SIZE 10

// Function to merge two sorted subarrays
void merge(int arr[], int start, int mid, int end) {
    int i = start, j = mid + 1, k = 0;
    int temp[end - start + 1];

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    // Copy remaining elements from left subarray
    while (i <= mid)
        temp[k++] = arr[i++];

    // Copy remaining elements from right subarray
    while (j <= end)
        temp[k++] = arr[j++];

    // Copy merged temp array back to original
    for (i = start, k = 0; i <= end; i++, k++)
        arr[i] = temp[k];
}

// Merge sort recursive function
void merge_sort(int arr[], int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;

        merge_sort(arr, start, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

// Main function
int main() {
    int arr[SIZE] = {11, 14, 6, 52, 47, 25, 1, 98, 21, 8};

    printf("Original Array:\n");
    for (int i = 0; i < SIZE; i++)
        printf("%d  ", arr[i]);
    printf("\n");

    merge_sort(arr, 0, SIZE - 1);

    printf("Sorted Array:\n");
    for (int i = 0; i < SIZE; i++)
        printf("%d  ", arr[i]);
    printf("\n");

    return 0;
}

