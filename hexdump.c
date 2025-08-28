#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RED "\033[31m"
#define RESET "\033[0m"
#define SIZE_T_MAX 0xFFFFFFFFU

int main(int argc, char *argv[]) {
    unsigned char buffer[16];
    FILE *fp;
    size_t index = 0;
    size_t n;
    size_t max_iters; // gives number of filled lines + one last unfilled (or filled) line
    size_t bytes_read = 0;
    size_t bytes_left_to_read;
    size_t bytes_in_each_line = 16;
    int spaces[16] = {49, 46, 43, 39, 36, 33, 30, 26, 23, 20, 17, 13, 10, 7, 4, 0};
    long long no_of_bytes;
    // printf("argc = %d, argv = ", argc);
    // for(int i = 0; i < argc; i++) {
    //     printf("%s ",argv[i]);
    // }
    // printf("\n");
    if(argc < 2) {
        char filepath[100];
        printf("Enter the file path (separator: /) here: ");
        scanf("%99s", filepath);
        printf("You entered: %s\n", filepath);
        printf("Enter the number of bytes to read (-1 if all): ");
        scanf("%lld", &no_of_bytes);
        if(no_of_bytes == 0) {
            printf("Number of bytes should not be zero. Please try again");
            return 1;
        }
        if(no_of_bytes < -1) {
            printf("Number of bytes cannot be less than -1. Please try again");
            return 1;
        }
        if(no_of_bytes == -1) no_of_bytes = SIZE_T_MAX;
        bytes_left_to_read = (size_t)no_of_bytes;
        fp = fopen(filepath, "rb");
    } else {
        if(argc == 2) {
            bytes_left_to_read = SIZE_T_MAX;
        } else {
            for(int i = 0; i < argc; i++) {
                if(strcmp(argv[i], "-n") == 0) {
                    no_of_bytes = strtoll(argv[i+1], NULL, 10);
                    if(!no_of_bytes) {
                        printf("Number of bytes should not be zero. Please try again");
                        return 1;
                    }
                    if(no_of_bytes < -1) {
                        printf("Number of bytes cannot be less than -1. Please try again");
                        return 1;
                    }

                    bytes_left_to_read = (size_t)no_of_bytes;
                } // -n flag
            }
        }
        fp = fopen(argv[1], "rb");
    }

    if(fp == NULL) {
        printf("Either the filepath is wrong or the file doesn't exist. Please try again.");
        return 1;
    }

    int any_bytes_read = 0;
    size_t i = 0;
    int remainder_bytes = bytes_left_to_read % 16;

    if(remainder_bytes == 0) {
        max_iters = (bytes_left_to_read) / 16;
    } else {
        max_iters = (bytes_left_to_read - remainder_bytes) / 16 + 1;
    }

    if(bytes_left_to_read < 16) bytes_in_each_line = bytes_left_to_read;

    while( ((n = fread(buffer, 1, bytes_in_each_line, fp)) != 0) && (i < max_iters) ) { // n is the number of bytes in each line. if 0, loop stops. 
        any_bytes_read = 1;
        printf("%08zX: ", index);

        for(int j = 0; j < n; j++) {
            //if(j >= n) buffer[j] = (unsigned char)32;

            printf("%02X ", buffer[j]);
            if(j == 3 || j == 7 || j == 11 || j == 15) printf(" ");
        }

        if(n <= 16) for(int i = 0; i < spaces[n-1]; i++) printf(" ");

        printf("|");

        for(int j = 0; j < n; j++) {
            if(buffer[j] >= 32 && buffer[j] <= 126) {
                printf("%c",(char)buffer[j]);
            } else {
                printf(RED "." RESET);
            }
        }

        if( (i == max_iters - 2) && (remainder_bytes != 0) ) bytes_in_each_line = remainder_bytes;
        printf("|\n");
        index += 16;
        i++;
    } 

    if(!any_bytes_read) {
        printf("The binary file is empty!");
    }

    fclose(fp);
    return 0;
}

