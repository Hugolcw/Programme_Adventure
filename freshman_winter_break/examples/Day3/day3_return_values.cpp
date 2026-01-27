#include <iostream>

// === INLINE FUNCTIONS (内联函数) ===
// Inline suggests compiler to replace function call with function body
// Benefits: Eliminates function call overhead
// Use for: Small, frequently called functions

// Regular function (has call overhead)
int regularAdd(int a, int b) {
    return a + b;
}

// Inline function (compiler may replace call with code)
inline int inlineAdd(int a, int b) {
    return a + b;
}

// Inline function for max
inline int max(int a, int b) {
    return (a > b) ? a : b;
}

// Inline function for square
inline int square(int x) {
    return x * x;
}

// === WHEN TO USE INLINE ===
// Good: Small, simple functions
inline bool isPositive(int x) {
    return x > 0;
}

// Bad: Large functions (compiler will likely ignore inline)
inline void printLargeTable() {
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            std::cout << i * j << "\t";
        }
        std::cout << std::endl;
    }
}

// Bad: Recursive functions (cannot be inlined)
inline int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

// === INLINE VS MACRO ===
// Old C-style macro (avoid in C++)
#define MACRO_SQUARE(x) ((x) * (x))

// Better: Inline function (type-safe)
inline int inlineSquare(int x) {
    return x * x;
}

int main() {
    std::cout << "=== Day 3: Inline Functions ===" << std::endl;
    
    // --- Example 1: Regular vs Inline ---
    std::cout << "\n--- Example 1: Regular vs Inline ---" << std::endl;
    int a = 5, b = 3;
    std::cout << "regularAdd(5, 3) = " << regularAdd(a, b) << std::endl;
    std::cout << "inlineAdd(5, 3) = " << inlineAdd(a, b) << std::endl;
    // Both produce same result, but inline may be faster
    
    // --- Example 2: Inline utility functions ---
    std::cout << "\n--- Example 2: Inline Utilities ---" << std::endl;
    std::cout << "max(10, 20) = " << max(10, 20) << std::endl;
    std::cout << "square(7) = " << square(7) << std::endl;
    std::cout << "isPositive(-5) = " << isPositive(-5) << std::endl;
    std::cout << "isPositive(5) = " << isPositive(5) << std::endl;
    
    // --- Example 3: Performance consideration ---
    std::cout << "\n--- Example 3: Performance Test ---" << std::endl;
    int sum = 0;
    // Inline functions are good for loops (no call overhead)
    for (int i = 0; i < 10; i++) {
        sum += inlineAdd(i, i);  // Compiler may replace with: sum += i + i
    }
    std::cout << "Sum using inline: " << sum << std::endl;
    
    // --- Example 4: Inline vs Macro ---
    std::cout << "\n--- Example 4: Inline vs Macro ---" << std::endl;
    int x = 5;
    std::cout << "MACRO_SQUARE(5) = " << MACRO_SQUARE(x) << std::endl;
    std::cout << "inlineSquare(5) = " << inlineSquare(x) << std::endl;
    
    // Macro problem: MACRO_SQUARE(x++) expands to ((x++) * (x++)) - WRONG!
    // Inline function: inlineSquare(x++) is safe
    
    // --- Example 5: When inline is ignored ---
    std::cout << "\n--- Example 5: Compiler May Ignore Inline ---" << std::endl;
    printLargeTable();  // Too large, compiler won't inline
    std::cout << "factorial(5) = " << factorial(5) << std::endl;  // Recursive, can't inline
    
    return 0;
}
