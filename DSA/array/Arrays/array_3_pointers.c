/*
 * Program Name    : pointer_array.c
 * Author          : Nishanth Narayanan Kp
 * Date            : 2025-04-06
 * Description     : Demonstrates the relationship between arrays and pointers in C.
 *                   Shows how pointers can be used to access and manipulate array elements.
 */

#include <stdio.h>

#define SIZE 5

void print_with_array(int arr[], int size);
void print_with_pointer(int *ptr, int size);

int main() {
    int numbers[SIZE] = {10, 20, 30, 40, 50};

    printf("Accessing array using array indexing:\n");
    print_with_array(numbers, SIZE);

    printf("\nAccessing array using pointer arithmetic:\n");
    print_with_pointer(numbers, SIZE);  // Same as &numbers[0]

    return 0;
}

// Function to print array elements using array indexing
void print_with_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}

// Function to print array elements using pointer arithmetic
void print_with_pointer(int *ptr, int size) {
    for (int i = 0; i < size; i++) {
        printf("*(ptr + %d) = %d\n", i, *(ptr + i));
    }
}

