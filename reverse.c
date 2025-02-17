#include <stdio.h>

int main(){
    char s[100], len=0,low,high, temp;
    printf("Enter the string\n");
    fgets(s,100,stdin);
    while(s[len]!='\n') len++;
    low = 0;
    high = len;
    while(low<high){
        temp = s[low];
        s[low] = s[high];
        s[high] = temp;
        low++;
        high--;
    }
    printf("Reversed string is%s\n",s);
    return 0;
}
