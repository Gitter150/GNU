#include <stdio.h>
int new_strcmp(char s1[],char s2[]) {   
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] < s2[i]) return -1;
        if (s1[i] > s2[i]) return 1;
        i++;
    }
    if (s1[i] == '\0' && s2[i] == '\0') return 0;
    return (s1[i] == '\0') ? -1 : 1;
}
int main(){
    char s1[100],s2[100];
    
    printf("Enter the first string\n");
    fgets(s1,100,stdin);
    printf("Enter the second string\n");
    fgets(s2,100,stdin);
    if (new_strcmp(s1,s2)==0){
        printf("The two strings are equal\n");
        return 0;
    }
    printf(new_strcmp(s1,s2)>0? "First string is greater than second string":"Second string is greater than first string");
    return 0;
}
