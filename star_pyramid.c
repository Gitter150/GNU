#include<stdio.h>
void space(int x){
    for(int i=0;i<x;i++)
          printf(" ");
}
int main(){
    int n;
    printf("Enter the number of rows: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
          if(i%2==0)
             continue;
          space(n%2==0? (n-i)/2:(n+1-i)/2);
          for(int j=0;j<i;j++)
             printf("*");
          printf("\n");
    }
    return 0;
}