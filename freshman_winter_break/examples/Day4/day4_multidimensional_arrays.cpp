#include <iostream>

// === MULTI-DIMENSIONAL ARRAYS (多维数组) ===

int main() {
    std::cout << "=== Day 4: Multi-dimensional Arrays ===" << std::endl;
    
    // --- Example 1: 2D Array Declaration and Initialization ---
    std::cout << "\n--- Example 1: 2D Array Basics ---" << std::endl;
    
    // Method 1: Declare and initialize separately
    int matrix1[3][4];  // 3 rows, 4 columns
    
    // Method 2: Initialize with values
    int matrix2[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    // Method 3: Partial initialization (rest filled with 0)
    int matrix3[3][4] = {{1, 2}, {5, 6}};
    
    // Print matrix2
    std::cout << "Matrix2:" << std::endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << matrix2[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    
    // --- Example 2: Accessing Elements ---
    std::cout << "\n--- Example 2: Accessing Elements ---" << std::endl;
    
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    std::cout << "Element at [0][0]: " << arr[0][0] << std::endl;
    std::cout << "Element at [1][2]: " << arr[1][2] << std::endl;
    std::cout << "Element at [2][1]: " << arr[2][1] << std::endl;
    
    // Modify element
    arr[1][1] = 99;
    std::cout << "After modifying [1][1]: " << arr[1][1] << std::endl;
    
    // --- Example 3: Matrix Operations ---
    std::cout << "\n--- Example 3: Matrix Addition ---" << std::endl;
    
    int matrixA[2][2] = {{1, 2}, {3, 4}};
    int matrixB[2][2] = {{5, 6}, {7, 8}};
    int result[2][2];
    
    // Add matrices
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    
    std::cout << "Matrix A + Matrix B:" << std::endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            std::cout << result[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    
    // --- Example 4: Finding Max in 2D Array ---
    std::cout << "\n--- Example 4: Finding Maximum ---" << std::endl;
    
    int data[3][3] = {
        {15, 23, 8},
        {42, 17, 31},
        {9, 28, 19}
    };
    
    int max = data[0][0];
    int maxRow = 0, maxCol = 0;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (data[i][j] > max) {
                max = data[i][j];
                maxRow = i;
                maxCol = j;
            }
        }
    }
    
    std::cout << "Maximum value: " << max << std::endl;
    std::cout << "Position: [" << maxRow << "][" << maxCol << "]" << std::endl;
    
    // --- Example 5: Matrix Transpose ---
    std::cout << "\n--- Example 5: Matrix Transpose ---" << std::endl;
    
    int original[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    
    int transposed[3][2];
    
    // Transpose: swap rows and columns
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            transposed[j][i] = original[i][j];
        }
    }
    
    std::cout << "Original (2x3):" << std::endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << original[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    std::cout << "Transposed (3x2):" << std::endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            std::cout << transposed[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    // --- Example 6: 3D Array ---
    std::cout << "\n--- Example 6: 3D Array ---" << std::endl;
    
    // 3D array: [depth][rows][columns]
    int cube[2][2][2] = {
        {{1, 2}, {3, 4}},
        {{5, 6}, {7, 8}}
    };
    
    std::cout << "3D Array (2x2x2):" << std::endl;
    for (int i = 0; i < 2; i++) {
        std::cout << "Layer " << i << ":" << std::endl;
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                std::cout << cube[i][j][k] << " ";
            }
            std::cout << std::endl;
        }
    }
    
    return 0;
}
