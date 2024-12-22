#include <stdio.h>
#include <string.h>
int main(){
    int c, i;
    char s1[100], s2[100];
    printf("You have the following choices:\n");
    printf("1. Length of the given string\n");
    printf("2. Copy the given string\n");
    printf("3. Compare two strings\n");
    printf("4. Concatenate two strings\n");
    printf("Enter the choice: ");
    scanf("%d",&c);
    getchar();
    switch(c){
        case 1:
            printf("Enter the string\n");
            fgets(s1,100,stdin);
            s1[i = (int)strlen(s1)-1] = '\0';
            printf("The length of the string is %zu",i);
            break;
        case 2: {
            printf("Enter the string\n");
            fgets(s1,100,stdin);
            s1[strlen(s1)-1] = '\0';
            strcpy(s2,s1);
            printf("The copied string is\n%s\n",s2);
            break;
        }
        case 3: {
            printf("Enter the first string\n");
            fgets(s1,100,stdin);
            s1[strlen(s1)-1] = '\0';
            printf("Enter the second string\n");
            fgets(s2,100,stdin);
            s2[strlen(s2)-1] = '\0';
            int res = strcmp(s1,s2);
            if(res==0){
                printf("The two strings are equal");
                break;
            }
            printf(res<0? "First string is greater than the second string":"Second string is greater than the first string");
            break;
        } 
        case 4: {
            printf("Enter the first string\n");
            fgets(s1,100,stdin);
            s1[strlen(s1)-1]='\0';
            printf("Enter the second string\n");
            fgets(s2,100,stdin);
            s2[strlen(s2)-1]='\0';
            strcat(s1,s2);
            printf("The concatenated string is\n%s\n",s1);
        }         
    }
    return 0; 
}
