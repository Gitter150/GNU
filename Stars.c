#include<stdio.h>
int main(){
    int n,m;
    printf("Enter the number of rows: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(m = 1;m<=i+1;m++){
            printf("*");
        }
        printf("\n");
    }  
    return 0;
}