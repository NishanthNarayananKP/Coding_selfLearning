#include <stdio.h>


int main()
{
	printf("hello world\n");
	return 0;
}



/*
 *
 * stat hello.c --> to see timestamps
 *
 * makefile > Makefile
 *
 * -f : for custom make files
 *
 * -n : to print out what it does without doing it
 * -k : to keep going even after error found
 *
 *  PHONY target : without any dep 
 *  eg : clean all etc
 *  @ to not print command on stdout
 *
 *
 *  if multiple makefiles are present add
 *
 *  include : <path/makefile> 
 *
 *  it will halt current execution and execute new makefile
 * */
