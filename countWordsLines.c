#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    FILE* file;
    char buffer[100];
    char c;
    int words = 0, lines = 0;

    printf("Enter the file name!\n");

    if(fgets(buffer, 100, stdin)) {
        size_t len = strlen(buffer);
        if(len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }
    } else {
        printf("Invalid Input. Try again\n");
        return 0;
    }

    if(!(file = fopen(buffer, "r"))) {
        printf("Error! File \"%s\" could not be opened.\n", buffer);
        printf("Provide the subdirectory or absolute path of the file if possible. Try again!\n");
        return 0;
    }
    // Read file char by char, count newlines and ignore spaces
    while((c = fgetc(file)) != EOF) {
        if(c == '\n') {
            lines++;
            continue;
        }
        if(isspace(c)) continue;
    }

    // Reset file pointer for word counting
    fseek(file, 0, SEEK_SET);
    
    // Read words using fscanf and count them
    while(fscanf(file, "%s", buffer) == 1) words++;

    if(fclose(file) == EOF) {
        printf("Error! File couldn't be closed. Try again.\n");
        return 0;
    }
    printf("Number of words = %d\nNumber of lines = %d\n", words, lines);
    return 0;
}


