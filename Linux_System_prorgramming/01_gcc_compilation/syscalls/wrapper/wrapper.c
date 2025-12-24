/*
*  filename : wrapper.c
*  Author : NIshanth Narayanan k p
*  Date : 24/12/25
*/

#include <unistd.h>


int main(){
	char str[] = "Hi hello welcome \n" ;
	int ret = write(1 , str , sizeof str );
	return ret;
}
