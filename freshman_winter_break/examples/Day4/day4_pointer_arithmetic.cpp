#include <iostream>

// === POINTER ARITHMETIC (指针运算) ===

int main() {
    std::cout << "=== Day 4: Pointer Arithmetic ===" << std::endl;
    
    // --- Example 1: Basic Pointer Arithmetic ---
    std::cout << "\n--- Example 1: Pointer Increment/Decrement ---" << std::endl;
    
    int arr[] = {10, 20, 30, 40, 50};
    int* ptr = arr;  // Points to first element
    
    std::cout << "ptr points to: " << *ptr << std::endl;  // 10
    
    ptr++;  // Move to next element
    std::cout << "After ptr++: " << *ptr << std::endl;  // 20
    
    ptr += 2;  // Move forward 2 elements
    std::cout << "After ptr += 2: " << *ptr << std::endl;  // 40
    
    ptr--;  // Move back 1 element
    std::cout << "After ptr--: " << *ptr << std::endl;  // 30
    
    // --- Example 2: Pointer Arithmetic with Different Types ---
    std::cout << "\n--- Example 2: Different Data Types ---" << std::endl;
    
    int intArr[] = {1, 2, 3};
    double doubleArr[] = {1.1, 2.2, 3.3};
    char charArr[] = {'A', 'B', 'C'};
    
    int* intPtr = intArr;
    double* doublePtr = doubleArr;
    char* charPtr = charArr;
    
    std::cout << "int pointer address: " << intPtr << std::endl;
    std::cout << "int pointer + 1: " << (intPtr + 1) << std::endl;
    std::cout << "Difference: " << (intPtr + 1) - intPtr << " elements" << std::endl;
    std::cout << "Size of int: " << sizeof(int) << " bytes" << std::endl;
    
    std::cout << "\ndouble pointer address: " << doublePtr << std::endl;
    std::cout << "double pointer + 1: " << (doublePtr + 1) << std::endl;
    std::cout << "Size of double: " << sizeof(double) << " bytes" << std::endl;
    
    // --- Example 3: Pointer Subtraction ---
    std::cout << "\n--- Example 3: Pointer Subtraction ---" << std::endl;
    
    int numbers[] = {5, 10, 15, 20, 25};
    int* start = numbers;
    int* end = numbers + 4;  // Points to last element
    
    std::cout << "Distance between pointers: " << (end - start) << " elements" << std::endl;
    std::cout << "First element: " << *start << std::endl;
    std::cout << "Last element: " << *end << std::endl;
    
    // --- Example 4: Pointer Comparison ---
    std::cout << "\n--- Example 4: Pointer Comparison ---" << std::endl;
    
    int data[] = {100, 200, 300};
    int* p1 = data;
    int* p2 = data + 2;
    
    if (p1 < p2) {
        std::cout << "p1 comes before p2 in memory" << std::endl;
    }
    
    if (p2 > p1) {
        std::cout << "p2 comes after p1 in memory" << std::endl;
    }
    
    // --- Example 5: Array Traversal with Pointers ---
    std::cout << "\n--- Example 5: Array Traversal ---" << std::endl;
    
    int values[] = {2, 4, 6, 8, 10};
    int size = 5;
    
    // Method 1: Using array index
    std::cout << "Method 1 (index): ";
    for (int i = 0; i < size; i++) {
        std::cout << values[i] << " ";
    }
    std::cout << std::endl;
    
    // Method 2: Using pointer arithmetic
    std::cout << "Method 2 (pointer): ";
    for (int* p = values; p < values + size; p++) {
        std::cout << *p << " ";
    }
    std::cout << std::endl;
    
    // --- Example 6: Pointer Offset Notation ---
    std::cout << "\n--- Example 6: Pointer Offset Notation ---" << std::endl;
    
    int seq[] = {11, 22, 33, 44, 55};
    int* base = seq;
    
    // These are equivalent:
    std::cout << "base[0] = " << base[0] << std::endl;
    std::cout << "*(base + 0) = " << *(base + 0) << std::endl;
    
    std::cout << "base[2] = " << base[2] << std::endl;
    std::cout << "*(base + 2) = " << *(base + 2) << std::endl;
    
    // --- Example 7: Reverse Array with Pointers ---
    std::cout << "\n--- Example 7: Reverse Array ---" << std::endl;
    
    int original[] = {1, 2, 3, 4, 5};
    int n = 5;
    
    std::cout << "Original: ";
    for (int i = 0; i < n; i++) {
        std::cout << original[i] << " ";
    }
    std::cout << std::endl;
    
    // Reverse using two pointers
    int* left = original;
    int* right = original + n - 1;
    
    while (left < right) {
        // Swap
        int temp = *left;
        *left = *right;
        *right = temp;
        
        left++;
        right--;
    }
    
    std::cout << "Reversed: ";
    for (int i = 0; i < n; i++) {
        std::cout << original[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
