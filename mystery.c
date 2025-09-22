#include <stdio.h>
#include <stdint.h>

int main() {
	uint32_t arr[4] = {544499015, 1819043159, 1869566752, 8558};
	unsigned char* ptr = (unsigned char*)arr;
	puts(ptr);
	return 0;
}

// Hello World! = 48 65 6c 6c 6f 20 57 6f 72 6c 64 21 00 00 00 00
// 