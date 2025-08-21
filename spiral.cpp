#include <iostream>
#include <vector>

void printSpiral(std::vector<std::vector<int>> matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int top=0, right=1, down=0, left=0, rows_max = rows-1, cols_max = cols-1, rows_min = 0, cols_min = 0;
    int count = 0, i=0, j=0;

    while(count < rows*cols) {
        std::cout << matrix[i][j] << " ";
        if(i - 1 == rows_min && j == cols_min && cols_max != 0) { // cols_max !=0 ensures the matrix is not column vector.
            rows_min++;
            cols_min++;
            rows_max--;
            cols_max--;
            count++;
            top = 0;
            right = 1;
            down = 0;
            left = 0;
            i += down - top;
            j += right - left;
            std::cout<<"e ";
            continue;
        }
        if(j == cols_max && i == rows_min) {
            right = 0;
            down = 1;
            std::cout<<"a";
        }
        else if(i == rows_max && j == cols_max) {
            down = 0;
            left = 1;
            std::cout<<"b";
        }
        else if(j == cols_min && i == rows_max && rows_max !=0 && rows_max != rows_min) { // rows_max !=0 ensures the matrix is not row vector.
            left = 0;                                                        
            top = 1;                                                // matrix4 = 
            std::cout<<"c";                                                 //     { 1,  2,  3,  4,  5,  6},
                                                                            //     { 7,  8,  9, 10, 11, 12},
                                                                            //     {13, 14, 15, 16, 17, 18},
                                                                            
        }
        else if(i == rows_min && j == cols_min){
            top = 0;
            right = 1;
            std::cout<<"d";
        }
        std::cout<< " i,j="<<i<<","<<j<<"\n";
        std::cout <<" rowmax, rowmin="<<rows_max<<","<<rows_min<<std::endl;
        std::cout <<" colsmax, colsmin="<<cols_max<<","<<cols_min<<std::endl;
        i += down - top;
        j += right - left;
        count++;
    }
    std::cout << std::endl;
}

int main() {
    std::vector<std::vector<int>> 
    matrix1 = {
        {1, 2, 3},
        {8, 9, 4},
        {7, 6, 5}
    }, 
    matrix2 = {
        {1,2,3,4,5}
    },
    matrix3 = {
        {1},
        {2},
        {3},
        {4},
        {5},
        {6}
    },
    matrix4 = {{2,3,4},{5,6,7},{8,9,10},{11,12,13},{14,15,16}},
    matrix5 = {
        {1,2,3,4,5},
        {6,7,8,9,10}
    },
    matrix6 = {
        {1,2},
        {3,4},
        {5,6},
        {7,8},
        {9,10}
    },
    matrix7 = {
        {1}
    };
    printSpiral(matrix4);
    return 0;
}
