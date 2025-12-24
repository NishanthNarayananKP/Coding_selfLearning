#include <stdio.h>
int func();
int x = 1;
int y = 2;
int main()
{
	func();
	printf("x = %d\n", x);
	printf("y = %d\n", y);
	return 0;
}




/*
 * In this case will choose stron symbol over weak ones will result in bug
 * */
