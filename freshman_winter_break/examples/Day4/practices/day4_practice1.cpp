#include <iostream>

// === Practice 1: Matrix Operations (矩阵运算) ===

// TODO: Task 1 - Matrix Addition
// Create a function that adds two 3x3 matrices
// Parameters: matrixA[3][3], matrixB[3][3], result[3][3]
// Result should store the sum of A and B

// Your code here


// TODO: Task 2 - Matrix Multiplication
// Create a function that multiplies two 2x2 matrices
// Parameters: matrixA[2][2], matrixB[2][2], result[2][2]
// Formula: result[i][j] = sum of (A[i][k] * B[k][j]) for all k
// Example: [1 2] * [5 6] = [19 22]
//          [3 4]   [7 8]   [43 50]

// Your code here


// TODO: Task 3 - Matrix Transpose
// Create a function that transposes a matrix (swap rows and columns)
// Parameters: original[3][3], transposed[3][3]
// Example: [1 2 3]T = [1 4 7]
//          [4 5 6]    [2 5 8]
//          [7 8 9]    [3 6 9]

// Your code here


// TODO: Task 4 - Find Matrix Diagonal Sum
// Create a function that calculates the sum of main diagonal
// Parameters: matrix[4][4]
// Main diagonal: elements where row index == column index
// Example: [1 2 3 4]  -> diagonal sum = 1 + 5 + 9 + 13 = 28
//          [5 5 6 7]
//          [8 9 9 10]
//          [11 12 13 13]

// Your code here


int main() {
    std::cout << "=== Practice 1: Matrix Operations ===" << std::endl;
    
    // --- Test Task 1: Matrix Addition ---
    std::cout << "\n--- Task 1: Matrix Addition ---" << std::endl;
    // TODO: Test your matrix addition function
    // int A[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // int B[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    // int sum[3][3];
    // addMatrices(A, B, sum);
    // Print result
    
    // --- Test Task 2: Matrix Multiplication ---
    std::cout << "\n--- Task 2: Matrix Multiplication ---" << std::endl;
    // TODO: Test your matrix multiplication function
    // int M1[2][2] = {{1, 2}, {3, 4}};
    // int M2[2][2] = {{5, 6}, {7, 8}};
    // int product[2][2];
    // multiplyMatrices(M1, M2, product);
    // Print result
    
    // --- Test Task 3: Matrix Transpose ---
    std::cout << "\n--- Task 3: Matrix Transpose ---" << std::endl;
    // TODO: Test your transpose function
    // int original[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // int transposed[3][3];
    // transposeMatrix(original, transposed);
    // Print result
    
    // --- Test Task 4: Diagonal Sum ---
    std::cout << "\n--- Task 4: Diagonal Sum ---" << std::endl;
    // TODO: Test your diagonal sum function
    // int matrix[4][4] = {
    //     {1, 2, 3, 4},
    //     {5, 5, 6, 7},
    //     {8, 9, 9, 10},
    //     {11, 12, 13, 13}
    // };
    // int diagSum = diagonalSum(matrix);
    // std::cout << "Diagonal sum: " << diagSum << std::endl;
    
    return 0;
}
