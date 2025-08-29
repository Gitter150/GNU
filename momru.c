#include <stdio.h>
#include <stdint.h>

int main(void) {
    uint32_t x = 0x01020304;
    // unsigned char *p = (unsigned char*)&x;

    printf("Memory bytes: %02x %02x %02x %02x\n", (&x)[0], (&x)[1], (&x)[2], (&x)[3]);

    if ((&x)[0] == 0x04 && (&x)[1] == 0x03 && (&x)[2] == 0x02 && (&x)[3] == 0x01) {
        printf("Little endian\n");
    } else if ((&x)[0] == 0x01 && (&x)[1] == 0x02 && (&x)[2] == 0x03 && (&x)[3] == 0x04) {
        printf("Big endian\n");
    } else {
        printf("Something exotic (middle endian or alignment issue)\n");
    }

    return 0;
}
