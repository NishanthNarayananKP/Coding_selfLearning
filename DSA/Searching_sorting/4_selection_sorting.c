/*
 * Program Name    : 4_selction_sorting.c
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
	int swap_flag ; // optimize by adding flag to avoid sorting again in a sorted array
	int a[SIZE] = { 11,14,6,52,47,25,1,98,21,8};
	
	for(i = 0 ; i<SIZE-1 ;i++){
		for(j = i+1 ; j<SIZE-1 ;j++){
			if(a[i] > a[j] )
			{
				temp = a[i] ;
				a[i] = a[j] ;
				a[j]= temp ;
			}
		}
	}
	printf("Sorted Array : \n");
	for( i = 0 ;i<SIZE-1;i++){
		printf("%d ",a[i] );
	}
	printf("\n");
	return 0 ;
}
