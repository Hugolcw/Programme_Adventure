#include <iostream>

// === ARRAY AND POINTER RELATIONSHIP (数组与指针关系) ===

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void modifyArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;  // Double each element
    }
}

int main() {
    std::cout << "=== Day 4: Array and Pointer Relationship ===" << std::endl;
    
    // --- Example 1: Array Name as Pointer ---
    std::cout << "\n--- Example 1: Array Name is a Pointer ---" << std::endl;
    
    int arr[] = {10, 20, 30, 40, 50};
    
    std::cout << "arr (array name): " << arr << std::endl;
    std::cout << "&arr[0] (address of first element): " << &arr[0] << std::endl;
    std::cout << "They are the same!" << std::endl;
    
    // Array name can be used as pointer
    std::cout << "*arr = " << *arr << std::endl;  // Same as arr[0]
    std::cout << "*(arr + 1) = " << *(arr + 1) << std::endl;  // Same as arr[1]
    
    // --- Example 2: Array Indexing vs Pointer Notation ---
    std::cout << "\n--- Example 2: Equivalent Notations ---" << std::endl;
    
    int numbers[] = {5, 10, 15, 20, 25};
    int* ptr = numbers;
    
    std::cout << "Using array notation:" << std::endl;
    std::cout << "numbers[0] = " << numbers[0] << std::endl;
    std::cout << "numbers[2] = " << numbers[2] << std::endl;
    
    std::cout << "\nUsing pointer notation:" << std::endl;
    std::cout << "*(numbers + 0) = " << *(numbers + 0) << std::endl;
    std::cout << "*(numbers + 2) = " << *(numbers + 2) << std::endl;
    
    std::cout << "\nUsing pointer variable:" << std::endl;
    std::cout << "ptr[0] = " << ptr[0] << std::endl;
    std::cout << "ptr[2] = " << ptr[2] << std::endl;
    
    // --- Example 3: Passing Arrays to Functions ---
    std::cout << "\n--- Example 3: Arrays in Functions ---" << std::endl;
    
    int data[] = {1, 2, 3, 4, 5};
    int size = 5;
    
    std::cout << "Original array: ";
    printArray(data, size);
    
    modifyArray(data, size);
    
    std::cout << "After modification: ";
    printArray(data, size);
    
    // --- Example 4: Pointer to Array vs Array of Pointers ---
    std::cout << "\n--- Example 4: Pointer to Array ---" << std::endl;
    
    int values[] = {100, 200, 300};
    
    // Pointer to entire array
    int (*ptrToArray)[3] = &values;
    
    std::cout << "Using pointer to array:" << std::endl;
    std::cout << "(*ptrToArray)[0] = " << (*ptrToArray)[0] << std::endl;
    std::cout << "(*ptrToArray)[1] = " << (*ptrToArray)[1] << std::endl;
    
    // --- Example 5: 2D Array and Pointers ---
    std::cout << "\n--- Example 5: 2D Array as Pointer ---" << std::endl;
    
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    // matrix is a pointer to the first row
    std::cout << "matrix[0][0] = " << matrix[0][0] << std::endl;
    std::cout << "*(matrix[0] + 0) = " << *(matrix[0] + 0) << std::endl;
    std::cout << "*(*matrix + 0) = " << *(*matrix + 0) << std::endl;
    
    std::cout << "\nmatrix[1][2] = " << matrix[1][2] << std::endl;
    std::cout << "*(matrix[1] + 2) = " << *(matrix[1] + 2) << std::endl;
    std::cout << "*(*(matrix + 1) + 2) = " << *(*(matrix + 1) + 2) << std::endl;
    
    // --- Example 6: Pointer Arithmetic with 2D Arrays ---
    std::cout << "\n--- Example 6: Traversing 2D Array with Pointers ---" << std::endl;
    
    int grid[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    
    // Treat as 1D array
    int* flatPtr = &grid[0][0];
    
    std::cout << "Treating 2D array as 1D:" << std::endl;
    for (int i = 0; i < 6; i++) {
        std::cout << *(flatPtr + i) << " ";
    }
    std::cout << std::endl;
    
    // --- Example 7: Key Differences ---
    std::cout << "\n--- Example 7: Array vs Pointer Differences ---" << std::endl;
    
    int array[] = {1, 2, 3, 4, 5};
    int* pointer = array;
    
    std::cout << "sizeof(array) = " << sizeof(array) << " bytes" << std::endl;
    std::cout << "sizeof(pointer) = " << sizeof(pointer) << " bytes" << std::endl;
    
    std::cout << "\nKey difference:" << std::endl;
    std::cout << "- array is a constant pointer (cannot be reassigned)" << std::endl;
    std::cout << "- pointer is a variable (can be reassigned)" << std::endl;
    
    // array = pointer;  // ERROR: Cannot reassign array
    pointer = array;     // OK: Can reassign pointer
    
    pointer++;  // OK: Can modify pointer
    // array++;  // ERROR: Cannot modify array name
    
    std::cout << "\nAfter pointer++:" << std::endl;
    std::cout << "*pointer = " << *pointer << std::endl;
    
    return 0;
}
