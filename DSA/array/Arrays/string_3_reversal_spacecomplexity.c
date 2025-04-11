/***************************************************************
 * Author       : Nishanth Narayanan Kp
 * Date         : 2025-04-11 11:47 AM
 * Program Name : string_3_reverse_spacecomplexity.c
 * Description  : string reversal program
 ***************************************************************/

#include <stdio.h>

#define MAX_SIZE 20

int main() {
	char string[MAX_SIZE] = "Hello world" ;
	int i ;
	char temp ;
	for(i = 0 ; string[i] != '\0' ; i++);
	int length = i ;
	length--;
	i = 0;
	while(i < length){
		temp = string[i] ;
		string[i] = string[length] ;
		string[length] = temp ;
		i++ ; 
		length-- ;
	}
	printf("String is : %s " ,string);
	return 0 ;
}


/*
 *	Time  : O(n) 
 *	SPace : O(1) : single array
 *
 */
