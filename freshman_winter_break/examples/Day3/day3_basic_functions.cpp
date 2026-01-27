#include <iostream>
#include <string>

// === FUNCTION OVERLOADING (函数重载) ===
// Functions with same name but different parameters

// Overload 1: Print integer
void print(int value) {
    std::cout << "Integer: " << value << std::endl;
}

// Overload 2: Print double
void print(double value) {
    std::cout << "Double: " << value << std::endl;
}

// Overload 3: Print string
void print(std::string value) {
    std::cout << "String: " << value << std::endl;
}

// Overload 4: Print two integers
void print(int a, int b) {
    std::cout << "Two integers: " << a << ", " << b << std::endl;
}

// === OVERLOADING WITH DIFFERENT PARAMETER COUNTS ===
int add(int a, int b) {
    return a + b;
}

int add(int a, int b, int c) {
    return a + b + c;
}

double add(double a, double b) {
    return a + b;
}

// === OVERLOADING RULES ===
// 1. Different number of parameters
// 2. Different types of parameters
// 3. Different order of parameter types
// NOTE: Return type alone is NOT enough for overloading!

int main() {
    std::cout << "=== Day 3: Function Overloading ===" << std::endl;
    
    // --- Example 1: Overloading with different types ---
    std::cout << "\n--- Example 1: Different Types ---" << std::endl;
    print(42);              // Calls print(int)
    print(3.14);            // Calls print(double)
    print("Hello");         // Calls print(string)
    
    // --- Example 2: Overloading with different parameter counts ---
    std::cout << "\n--- Example 2: Different Parameter Counts ---" << std::endl;
    print(10, 20);          // Calls print(int, int)
    
    // --- Example 3: Overloaded add functions ---
    std::cout << "\n--- Example 3: Overloaded add() ---" << std::endl;
    std::cout << "add(5, 3) = " << add(5, 3) << std::endl;           // Calls add(int, int)
    std::cout << "add(5, 3, 2) = " << add(5, 3, 2) << std::endl;     // Calls add(int, int, int)
    std::cout << "add(2.5, 3.7) = " << add(2.5, 3.7) << std::endl;   // Calls add(double, double)
    
    // --- Example 4: Compiler chooses best match ---
    std::cout << "\n--- Example 4: Type Matching ---" << std::endl;
    print(100);             // Exact match: int
    print(100.0);           // Exact match: double
    print(100.0f);          // float converts to double
    
    return 0;
}
