#include <stdio.h>

int main(){

    float matrix1[10][10],matrix2[10][10],product[10][10]={{}},sum=0; 
    int m1, n1, m2, n2;

    printf("Enter the order of the first matrix (row x column): ");

    if(scanf("%d x %d",&m1, &n1)!=2){
        printf("Invalid Input. Please enter integers in the format (row x column)\n");
        return 1;
    }

    printf("Enter the order of the second matrix (row x column): ");

    if(scanf("%d x %d",&m2, &n2)!=2){
        printf("Invalid Input. Please enter integers in the format (row x column)\n");
        return 1;
    }

    if (m1 > 10 || n1 > 10 || m2 > 10 || n2 > 10) {
        printf("Matrix dimensions exceed the maximum allowed size of 10x10.\n");
        return 1;
    }


    if(n1!=m2 || m1<0 || m2 <0 || n1<0 || n2<0){
        printf("Invalid Orders. Matrix multiplication is incompatible if number of columns of first matrix is not the same as the number of rows of the second matrix.");
        return 1;
    }

    printf("Enter the elements of the first matrix\n");

    for(int i=0;i<m1;i++){
        for(int j=0;j<n1;j++){
            if (scanf("%f", &matrix1[i][j]) != 1) {
                printf("Invalid input. Please enter numerical values only.\n");
                return 1;
            }
        }
    }

    printf("Enter the elements of the second matrix\n");

    for(int i=0;i<m2;i++){
        for(int j=0;j<n2;j++){
            if (scanf("%f", &matrix2[i][j]) != 1) {
                printf("Invalid input. Please enter numerical values only.\n");
                return 1;
            }
        }
    }
    
    for(int i=0;i<m1;i++){
        for(int j=0;j<n2;j++){
            sum = 0;
            for(int r=0;r<n1;r++){
                sum+=matrix1[i][r]*matrix2[r][j];
            }
            product[i][j]=sum;
        }
    }

    printf("The product of the above matrices in the given order is\n");

    for (int i = 0; i < m1; i++){
        for (int j = 0; j < n2; j++)
            printf("%.1f ",product[i][j]);
        printf("\n");
    }
    return 0;
}
