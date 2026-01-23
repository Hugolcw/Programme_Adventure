#include <iostream>

int main() {
    std::cout << "=== Practice 3: Pattern Printing ===" << std::endl;
    
    // TODO: Implement the following patterns using nested loops
    
    // Task 1: Print a square of stars
    std::cout << "\n--- Task 1: Square (5x5) ---" << std::endl;
    // Expected output:
    // *****
    // *****
    // *****
    // *****
    // *****
    
    // Your code here: Use nested for loops
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << '*';
        }
        std::cout << std::endl;
    }
    
    // Task 2: Print a right triangle
    std::cout << "\n--- Task 2: Right Triangle ---" << std::endl;
    // Expected output:
    // *
    // **
    // ***
    // ****
    // *****
    
    // Your code here: Use nested for loops
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j <= i; j++) {
            std::cout << '*';
        }
        std::cout << std::endl;
    }
    
    // Task 3: Print numbers in rows
    std::cout << "\n--- Task 3: Number Rows ---" << std::endl;
    // Expected output:
    // 1
    // 1 2
    // 1 2 3
    // 1 2 3 4
    // 1 2 3 4 5
    
    // Your code here: Use nested for loops
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= i; j++) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
    
    // Task 4: Print a simple multiplication table (3x3)
    std::cout << "\n--- Task 4: Multiplication Table (3x3) ---" << std::endl;
    // Expected output:
    // 1  2  3
    // 2  4  6
    // 3  6  9
    
    // Your code here: Use nested for loops
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            std::cout << i * j << "  ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}