/*
 Program to check whether your computer is little-endian or big-endian 
 Just compile and run
*/

#include <stdio.h>
#include <stdint.h>

void is_little_endian() {
	uint16_t x = 0x0001; // 00000000 00000001
	return is_little_endian = *((unsigned char*)&x) == 0x01;
}

int main() {
	if(is_little_endian())
		printf("This machine is little-endian\n");
	else
		printf("This machine is big-endian\n");

	return 0;
}