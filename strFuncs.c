#include <stdio.h>
#include <string.h>
int main(){
    int c;
    size_t i;
    char s1[100], s2[100];
    printf("You have the following choices:\n");
    printf("1. Length of the given string\n");
    printf("2. Reverse the given string\n");
    printf("3. Copy the given string\n");
    printf("4. Compare two strings\n");
    printf("5. Concatenate two strings\n");
    printf("Enter the choice: ");
    scanf("%d",&c);
    getchar();
    if(c<1||c>5){
        printf("Invalid Choice. Enter a choice between 1 and 5.");
        return -1;
    }
    switch(c){
        case 1:
            printf("Enter the string\n");
            fgets(s1,100,stdin);
            s1[i = strlen(s1)-1] = '\0';
            printf("The length of the string is %zu",i);
            break;
        case 2: {
            int low, high;
            char temp;
            printf("Enter the string\n");
            fgets(s1,100,stdin);
            s1[i = strlen(s1)-1] = '\0';
            i--;
            low = 0;
            high = i;
            while(low<high){
                temp = s1[low];
                s1[low] = s1[high];
                s1[high] = temp;
                low++;
                high--;
            }
            printf("Reversed string is\n%s\n",s1);
            break;
        }
        case 3: {
            printf("Enter the string\n");
            fgets(s1,100,stdin);
            s1[i = strlen(s1)-1] = '\0';
            i--;
            strcpy(s2,s1);
            printf("The copied string is\n%s\n",s2);
            break;
        }
        case 4: {
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
            printf(res>0? "First string is greater than the second string":"Second string is greater than the first string");
            break;
        } 
        case 5: {
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
