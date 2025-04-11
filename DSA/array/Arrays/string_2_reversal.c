/***************************************************************
 * Author       : Nishanth Narayanan Kp
 * Date         : 2025-04-11 11:32 AM
 * Program Name : string_2_reversal.c
 * Description  : string reversal program
 ***************************************************************/

#include <stdio.h>

#define MAX_SIZE 20

int main() {
	char string1[MAX_SIZE] = "Hello world" ;
	char string2[MAX_SIZE] = {0} ;
	int i ;
	for(i = 0 ; string1[i] != '\0' ; i++);
	int length = i ;
	printf("STring length is %d \n" , length );
	/* SImple approach */
	/*
	for(i = 0,length =length-1 ; length >= 0 ; length--,i++)
	{
		string2[i] = string1[length] ;
	}
	*/

	// optimized loop 
	
	// Reverse the string
   	for (int i = 0; i < length; i++) {
		string2[i] = string1[length - 1 - i];
	}
	string2[i] = '\0' ;
	printf("Reversed string is : %s \n" , string2); 
	return 0 ;
}


/*
 *	Time  : O(n) 
 *	SPace : O(n)  : since using reversed array
 *
 */
