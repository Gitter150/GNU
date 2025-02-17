//generates primes within a given range
#include <stdio.h>

int main() {
    // Write C code here
    int a,b,flag,i,j,isFirst=1;
    printf("Enter the range: ");
    scanf("%d %d",&a,&b);
    printf("Prime numbers in the range (%d,%d) are\n",a,b);
    if(a%2==0)
      a++;
    for(i = a; i<=b; i+=2){
        flag = 0;
        for(j=2;j<=i/2;j++){
            if(i%j==0)
              flag=1;
        }
        if(flag==0){
           if(!isFirst){
              printf(", ");
           }
           printf("%d",i);
           is_first = 0;
        }
    }
    return 0;
}