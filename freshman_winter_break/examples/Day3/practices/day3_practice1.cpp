#include <iostream>
#include <string>

// === Practice 1: Overloaded Operator Functions (重载运算符函数) ===
// Create overloaded functions that work like operators

// TODO: Task 1 - Create overloaded max() functions
// Implement max() for: int, double, and three integers
// Example: max(5, 3) should return 5
//          max(5.5, 3.2) should return 5.5
//          max(5, 10, 3) should return 10

// Your code here for max() functions
int max(int a, int b) {
    return (a > b) ? a : b;
}

double max(double a, double b) {
    return (a > b) ? a : b;
}

// Optimized: Use existing max() function
int max(int a, int b, int c) {
    int temp = max(a, b);  // Find max of first two
    return max(temp, c);   // Compare with third
}

// TODO: Task 2 - Create overloaded compare() functions
// Implement compare() that returns:
//   -1 if first < second
//    0 if first == second
//    1 if first > second
// Implement for: int, double, string (alphabetical comparison)

// Your code here for compare() functions
// Optimized: Simplified logic
int compare(int a, int b) {
    if (a < b) return -1;
    if (a > b) return 1;
    return 0;  // Must be equal
}

int compare(double a, double b) {
    if (a < b) return -1;
    if (a > b) return 1;
    return 0;
}

int compare(std::string a, std::string b) {
    if (a < b) return -1;
    if (a > b) return 1;
    return 0;
}

// TODO: Task 3 - Create overloaded print() functions
// Implement print() for:
//   - Single value (int, double, string)
//   - Array of integers with size
//   - Two values with a separator

// Your code here for print() functions
void print(int a) {
    std::cout << a << std::endl;
}

void print(double a) {
    std::cout << a << std::endl;
}

void print(std::string a) {
    std::cout << a << std::endl;
}

// Fixed: Loop through array elements, not print address
void print(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i];
        if (i < size - 1) std::cout << " ";  // Space between elements
    }
    std::cout << std::endl;
}

void print(int a, int b, std::string separator) {
    std::cout << a << separator << b << std::endl;
}

int main() {
    std::cout << "=== Practice 1: Overloaded Operator Functions ===" << std::endl;
    
    // --- Test Task 1: max() ---
    std::cout << "\n--- Task 1: max() functions ---" << std::endl;
    std::cout << "max(5, 3) = " << max(5, 3) << std::endl;
    std::cout << "max(5.5, 3.2) = " << max(5.5, 3.2) << std::endl;
    std::cout << "max(5, 10, 3) = " << max(5, 10, 3) << std::endl;
    
    // --- Test Task 2: compare() ---
    std::cout << "\n--- Task 2: compare() functions ---" << std::endl;
    std::cout << "compare(5, 3) = " << compare(5, 3) << std::endl;
    std::cout << "compare(3.2, 5.5) = " << compare(3.2, 5.5) << std::endl;
    std::cout << "compare(\"apple\", \"banana\") = " << compare("apple", "banana") << std::endl;
    
    // --- Test Task 3: print() ---
    std::cout << "\n--- Task 3: print() functions ---" << std::endl;
    print(42);
    print(3.14);
    print("Hello");
    int arr[] = {1, 2, 3, 4, 5};
    print(arr, 5);
    print(10, 20, " + ");
    
    return 0;
}
