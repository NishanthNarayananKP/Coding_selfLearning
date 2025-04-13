/*
 * Program Name    : 3_bubble_sort.c
 * Author          : Nishanth Narayanan Kp
 * Date            : 2025-04-13
 * Description     : Implements a Bubble sorting program
 *                   
 */


#include <stdio.h>

#define SIZE 10

int main()
{
	int i , j , temp ;
	int swap_flag ; // optimize by adding flag to avoid sorting again in a sorted array
	int arr[SIZE] = { 11,14,6,52,47,25,1,98,21,8};
	for( i = 0; i< SIZE-1 ; i++){
		swap_flag = 0; 
		for(j = 0 ;j <SIZE-1; j++){
			if( arr[j] > arr[j+1]){
				temp = arr[j] ;
				arr[j] = arr[j+1];	
				arr[j+1] = temp; 
				swap_flag = 1 ;
			}
		}
		if(swap_flag == 0 ) break ;
	}

	printf("Sorted Array is : \n");
	for(i = 0 ; i< SIZE - 1; i++){
		printf("%d  " ,arr[i]);
		}
	printf("\n");
	return 0 ;
}

/*
 *
 *
 *  Space complexity : O(1)
 *  Time Complexity : O(n²) best	O(n²)worst 	O(n²) AVerage after optimization best O(n)
 *
 */  
