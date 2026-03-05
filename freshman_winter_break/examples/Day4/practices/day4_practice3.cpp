#include <iostream>

// === Practice 3: Dynamic Array Implementation (动态数组实现) ===

// TODO: Task 1 - Create Dynamic Array
// Create a function that allocates a dynamic array of given size
// Parameters: int size
// Return: int* (pointer to allocated array)
// Use: new int[size]

// Your code here


// TODO: Task 2 - Initialize Dynamic Array
// Create a function that initializes all elements to a given value
// Parameters: int* arr, int size, int value
// Return: void

// Your code here


// TODO: Task 3 - Resize Dynamic Array
// Create a function that resizes a dynamic array
// Steps:
//   1. Allocate new array with new size
//   2. Copy old elements to new array
//   3. Delete old array
//   4. Return new array pointer
// Parameters: int* oldArr, int oldSize, int newSize
// Return: int* (pointer to new array)

// Your code here


// TODO: Task 4 - Find Element in Dynamic Array
// Create a function that finds an element and returns its index
// Parameters: int* arr, int size, int target
// Return: int (index if found, -1 if not found)

// Your code here


// TODO: Task 5 - Delete Dynamic Array
// Create a function that properly deallocates dynamic array
// Parameters: int* arr
// Return: void
// Use: delete[] arr

// Your code here


// TODO: Task 6 - Dynamic 2D Array
// Create a function that allocates a dynamic 2D array
// Parameters: int rows, int cols
// Return: int** (pointer to array of pointers)
// Steps:
//   1. Allocate array of row pointers: new int*[rows]
//   2. For each row, allocate column array: new int[cols]

// Your code here


// TODO: Task 7 - Delete Dynamic 2D Array
// Create a function that deallocates dynamic 2D array
// Parameters: int** arr, int rows
// Return: void
// Steps:
//   1. Delete each row: delete[] arr[i]
//   2. Delete row pointer array: delete[] arr

// Your code here


int main() {
    std::cout << "=== Practice 3: Dynamic Array Implementation ===" << std::endl;
    
    // --- Test Task 1 & 2: Create and Initialize ---
    std::cout << "\n--- Task 1 & 2: Create and Initialize ---" << std::endl;
    // TODO: Test your create and initialize functions
    // int size = 5;
    // int* arr = createArray(size);
    // initializeArray(arr, size, 10);
    // std::cout << "Array elements: ";
    // for (int i = 0; i < size; i++) {
    //     std::cout << arr[i] << " ";
    // }
    // std::cout << std::endl;
    
    // --- Test Task 3: Resize Array ---
    std::cout << "\n--- Task 3: Resize Array ---" << std::endl;
    // TODO: Test your resize function
    // int newSize = 8;
    // arr = resizeArray(arr, size, newSize);
    // std::cout << "After resize to " << newSize << ": ";
    // for (int i = 0; i < newSize; i++) {
    //     std::cout << arr[i] << " ";
    // }
    // std::cout << std::endl;
    
    // --- Test Task 4: Find Element ---
    std::cout << "\n--- Task 4: Find Element ---" << std::endl;
    // TODO: Test your find function
    // int target = 10;
    // int index = findElement(arr, newSize, target);
    // if (index != -1) {
    //     std::cout << "Found " << target << " at index " << index << std::endl;
    // } else {
    //     std::cout << target << " not found" << std::endl;
    // }
    
    // --- Test Task 5: Delete Array ---
    std::cout << "\n--- Task 5: Delete Array ---" << std::endl;
    // TODO: Test your delete function
    // deleteArray(arr);
    // std::cout << "Array deleted successfully" << std::endl;
    
    // --- Test Task 6 & 7: Dynamic 2D Array ---
    std::cout << "\n--- Task 6 & 7: Dynamic 2D Array ---" << std::endl;
    // TODO: Test your 2D array functions
    // int rows = 3, cols = 4;
    // int** matrix = create2DArray(rows, cols);
    // 
    // // Fill with values
    // int value = 1;
    // for (int i = 0; i < rows; i++) {
    //     for (int j = 0; j < cols; j++) {
    //         matrix[i][j] = value++;
    //     }
    // }
    // 
    // // Print matrix
    // std::cout << "2D Array:" << std::endl;
    // for (int i = 0; i < rows; i++) {
    //     for (int j = 0; j < cols; j++) {
    //         std::cout << matrix[i][j] << "\t";
    //     }
    //     std::cout << std::endl;
    // }
    // 
    // // Delete matrix
    // delete2DArray(matrix, rows);
    // std::cout << "2D Array deleted successfully" << std::endl;
    
    return 0;
}
