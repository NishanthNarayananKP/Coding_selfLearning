/*
*  filename : nowrapper.c
*  Author : NIshanth Narayanan k p
*  Date : 24/12/25
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>


int main(){
	char str[] = "Hi hello welcome \n" ;
	//int ret = syscall(SYS_write,1 , str , sizeof str ); 
	/*use Number directly */
	int ret = syscall(1,1 , str , sizeof str );
	return ret;
}
