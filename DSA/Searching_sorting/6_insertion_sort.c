/*
 * Program Name    : 6_insertion_sort.c
 * Author          : Nishanth Narayanan Kp
 * Date            : 2025-04-13
 * Description     : Implements a insertion sorting program
 *                   
 */


#include <stdio.h>

#define SIZE 10

int main()
{
	int i , j , temp ;
	int a[SIZE] = { 11,14,6,52,47,25,1,98,21,8};
	
	for( i =1 ; i < SIZE ;i++)
	{
		j = i-1 ;
		temp = a[i] ;
		while( j >= 0 && a[j] > temp ){
			a[j+1] = a[j] ;
			j--;
		}
		a[j+1] =temp ;
	}

	printf("Sorted Array : \n");
	for(i = 0 ; i <SIZE ;i++){
		printf("%d  " ,a[i] );
	}
	printf("\n");
	return 0 ;
}


/*
 *
 * Time and Space Complexity
 * Best Case (Already Sorted): O(n)
 * Average/Worst Case: O(n²)
 * Space Complexity: O(1) – in-place
 *
 */
