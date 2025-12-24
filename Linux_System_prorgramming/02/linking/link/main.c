/*
 *
 * Author : Nishanth\
 * filename : main.c
 * Description : to analyse symbol tables use nm,readelf and analyse variables in both files
 */

#include <stdio.h>
void swap();
int buf[2] = {1,2};
int main()
{
	swap();
	printf("buf[0]= %d, buf[1]= %d \n",buf[0], buf[1]);
	return 0;
}

