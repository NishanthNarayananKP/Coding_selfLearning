/***************************************************************
 * Author       : Nishanth Narayanan Kp
 * Date         : 2025-04-06 03:00 PM
 * Program Name : string_1_copy.c
 * Description  : string copy program
 ***************************************************************/

#include <stdio.h>

#define MAX_SIZE 20

int main() {
	char string1[MAX_SIZE] = "Hello world" ;
	char string2[MAX_SIZE] = {0} ;
	int i ;
	for(i = 0 ; string1[i] != '\0' ; i++)
	{
		string2[i] = string1[i] ;
	}
	string2[i] = '\0' ;
	printf("Copied string is : %s \n" , string2);
	return 0 ;
}

