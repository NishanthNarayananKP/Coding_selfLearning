/*
 * Program Name    : 5_selction_sorting_optimized.c
 * Author          : Nishanth Narayanan Kp
 * Date            : 2025-04-13
 * Description     : Implements a selection sorting program
 *                   
 */


#include <stdio.h>

#define SIZE 10

int main()
{
	int i , j , temp ;
	int a[SIZE] = { 11,14,6,52,47,25,1,98,21,8};
	
	for (i = 0; i < SIZE - 1; i++) {
		int min_idx = i;
		for (j = i + 1; j < SIZE; j++) {
			if (a[j] < a[min_idx]) {
				min_idx = j;
			}
		}
		// Swap only if needed
		if (min_idx != i) {
			temp = a[i];
			a[i] = a[min_idx];
			a[min_idx] = temp;
		}
}
	


	printf("Sorted Array : \n");
	for( i = 0 ;i<SIZE-1;i++){
		printf("%d ",a[i] );
	}
	printf("\n");
	return 0 ;
}

// Time and Space complexity remains same but no of swaps reduced.
//
// Time : O(n²) Space : O(1)
