/***************************************************************
 * Author       : Nishanth Narayanan Kp
 * Date         : 2025-04-06 10:00 AM
 * Program Name : endianness_union.c
 * Description  : Detects system endianness using union and byte array more safe than low level pointer method
 ***************************************************************/

#include <stdio.h>
#include <stdint.h>

union {
    uint32_t i;
    uint8_t c[4];
} test = {0x01020304};

int main() {
    if (test.c[0] == 0x04)
        printf("Little Endian\n");
    else if (test.c[0] == 0x01)
        printf("Big Endian\n");
    else
        printf("Unknown Endian Format\n");

    return 0;
}

