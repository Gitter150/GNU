#include <stdio.h>
#define MAX_TERMS 101

void readMat(int mat[][10], int *row, int *col) {
    int rows, cols;
    printf("Enter the number of rows and number of columns: \n");
    scanf("%d", &rows);
    scanf("%d", &cols);
    *row = rows;
    *col = cols;
    printf("Enter the sparse matrix:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            scanf("%d", *(mat+i) + j);
        }
    }
}

void fillSparse(int s[][3], int mat[][10], int rows, int cols) {
    int k = 1;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(mat[i][j] != 0) {
                s[k][0] = i;
                s[k][1] = j;
                s[k][2] = mat[i][j];
                k++;
            }
        }
    }
    s[0][0] = rows;
    s[0][1] = cols;
    s[0][2] = k-1;
}

void printSparse(int s[][3]) {
    int rows = s[0][2] + 1;
    printf("Rows  Cols  Value\n");
    for(int i = 0; i < rows; i++) {
        printf(" %d     %d      %d\n", s[i][0], s[i][1], s[i][2]);
    }
    printf("\n");
}

int main() {
    int mat[10][10] = {0};
    int s[MAX_TERMS][3] = {0};
    int rows, cols;
    readMat(mat, &rows, &cols);
    fillSparse(s, mat, rows, cols);
    printSparse(s);
    return 0;
}