#include <stdio.h>
#include <string.h>
int main() {
    FILE* file;
    FILE* _copyfile;
    char buffer[100];
    printf("Enter the file name!\n");
    if(fgets(buffer, 100, stdin)) {
        size_t len = strlen(buffer);
        if(len > 0 && buffer[len - 1] == '\n'){
            buffer[len - 1] = '\0';
        }
    }
    else {
        printf("Invalid Input. Try again\n");
        return 0;
    }
    if(!(file = fopen(buffer, "r"))) {
        printf("Error! File \"%s\" could not be opened.\n",buffer);
        printf("Provide the subdirectory or absolute path of the file if possible. Try again!\n");
        return 0;
    }
    _copyfile = fopen(strncat(buffer,"_copy",100), "w");
    if(_copyfile == NULL) {
        printf("Error! new file couldn't be created. Try again\n");
        return 0;
    }
    printf("Copying is beginning..\n");
    while(fgets(buffer, 100, file)) {
        fprintf(_copyfile,"%s",buffer);
    }
    printf("Copying done!\n");
    if(fclose(file) == EOF) {
        printf("Error closing the original file.\n");
        return 0;
    }
    if(fclose(_copyfile) == EOF) {
        printf("Error closing the new file. \n");
        return 0;
    }
    return 0;
}