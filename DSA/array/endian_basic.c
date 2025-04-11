/***************************************************************
 * Author       : Nishanth Narayanan Kp
 * Date         : 2025-04-06 10:00 AM
 * Program Name : endianness_check.c
 * Description  : Detects system endianness using pointer casting
 ***************************************************************/

#include <stdio.h>

int main()
{
	int x = 0x01 ;
	char *c = (char*)&x ;
	if( *c == 1){
		printf("Little endian \n");
	}
	else{
		printf("Big endian \n");
	}
	//if needed can print bytes in order to verify endianess
	return 0 ;

}










/********************************************************************
 * Endianness	Memory (Addr ↑)	First Byte (*c)
 *    Little	01 00 00 00	0x01 (== 1)
 *    Big	00 00 00 01	0x00 (== 0)
 *
 *	 Addr     Value
 *	----     -----
 *	0x1000   0x01   ← *c points here
 *	0x1001   0x00
 *	0x1002   0x00
 *	0x1003   0x00
 ********************************************************************/



