/***************************************************************
 * Author       : Nishanth Narayanan Kp
 * Date         : 2025-04-06 11:00 AM
 * Program Name : array_memory_forloop.c
 * Description  : Initializes an integer array, prints each 
 *                element using a for loop inside main(), and 
 *                documents how it's stored in memory.
 ***************************************************************/

#include <stdio.h>

int main() {
    // Integer array initialization
    int arr[5] = {10, 20, 30, 40, 50};

    /***************************************************************
     * Memory Layout Explanation (Assuming 4 bytes per int):
     *
     * If base address of arr is 0x1000, memory will look like:
     *
     * Address     Value (Decimal)   Explanation
     * ---------   ---------------   -----------------------------
     * 0x1000      10                arr[0]
     * 0x1004      20                arr[1]
     * 0x1008      30                arr[2]
     * 0x100C      40                arr[3]
     * 0x1010      50                arr[4]
     *
     * Memory is stored contiguously. Each `int` takes 4 bytes.
     ***************************************************************/

    printf("Array Elements (using for loop in main):\n");

    // Print each element using normal array indexing in a loop
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    return 0;
}

