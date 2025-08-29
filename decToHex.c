#include <stdio.h>

void hex(char *offset, size_t dec) {
    size_t temp = dec;
    int i;
    for(i = 0; i < 8; i++) offset[i] = '0';
    i = 7;
    offset[8] = '\0';
    char hexChar[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    while(temp > 0) {
        offset[i] = hexChar[temp % 16];
        temp = temp / 16;
        i--;
    }
}
