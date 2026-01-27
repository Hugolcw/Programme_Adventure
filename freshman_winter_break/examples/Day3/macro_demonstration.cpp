#include <iostream>

// === WHAT IS A MACRO? (什么是宏?) ===
// A macro is a preprocessor directive that does TEXT REPLACEMENT
// Before compilation, the preprocessor replaces macro names with their definitions
// Macros are defined using #define

// === SIMPLE MACROS (简单宏) ===
#define PI 3.14159
#define MAX_SIZE 100
#define GREETING "Hello, World!"

// === FUNCTION-LIKE MACROS (函数式宏) ===
// These look like functions but are just text replacement
#define SQUARE(x) ((x) * (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

// === MACRO PROBLEMS (宏的问题) ===
// Problem 1: No type checking
#define ADD(a, b) ((a) + (b))

// Problem 2: Multiple evaluation (dangerous!)
#define DANGEROUS_SQUARE(x) (x * x)  // Missing parentheses!

// Problem 3: Side effects
#define INCREMENT(x) ((x) + 1)

// === INLINE FUNCTION (Better alternative) ===
inline int inlineSquare(int x) {
    return x * x;
}

inline int inlineMax(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    std::cout << "=== Macro Demonstration ===" << std::endl;
    
    // --- Example 1: Simple macros (constant replacement) ---
    std::cout << "\n--- Example 1: Simple Macros ---" << std::endl;
    std::cout << "PI = " << PI << std::endl;
    std::cout << "MAX_SIZE = " << MAX_SIZE << std::endl;
    std::cout << "GREETING = " << GREETING << std::endl;
    
    // What happens: Preprocessor replaces PI with 3.14159 before compilation
    // double radius = 5.0;
    // double area = PI * radius * radius;
    // Becomes: double area = 3.14159 * radius * radius;
    
    // --- Example 2: Function-like macros ---
    std::cout << "\n--- Example 2: Function-like Macros ---" << std::endl;
    int num = 5;
    std::cout << "SQUARE(5) = " << SQUARE(num) << std::endl;
    std::cout << "MAX(10, 20) = " << MAX(10, 20) << std::endl;
    std::cout << "MIN(10, 20) = " << MIN(10, 20) << std::endl;
    
    // What happens: SQUARE(5) is replaced with ((5) * (5))
    // The preprocessor does TEXT REPLACEMENT, not function call
    
    // --- Example 3: Macro expansion demonstration ---
    std::cout << "\n--- Example 3: How Macros Expand ---" << std::endl;
    int x = 3;
    int result = SQUARE(x + 1);  // Expands to: ((x + 1) * (x + 1))
    std::cout << "SQUARE(x + 1) where x=3: " << result << std::endl;
    std::cout << "Expected: 16, Got: " << result << std::endl;
    
    // --- Example 4: DANGEROUS macro without parentheses ---
    std::cout << "\n--- Example 4: Dangerous Macro (No Parentheses) ---" << std::endl;
    int y = 3;
    int bad_result = DANGEROUS_SQUARE(y + 1);  // Expands to: (y + 1 * y + 1)
    std::cout << "DANGEROUS_SQUARE(y + 1) where y=3: " << bad_result << std::endl;
    std::cout << "Expected: 16, Got: " << bad_result << " (WRONG!)" << std::endl;
    // Why wrong? y + 1 * y + 1 = 3 + 1*3 + 1 = 3 + 3 + 1 = 7 (operator precedence!)
    
    // --- Example 5: Side effect problem ---
    std::cout << "\n--- Example 5: Side Effect Problem ---" << std::endl;
    int counter = 5;
    std::cout << "counter = " << counter << std::endl;
    
    // Using macro with side effect
    int macro_result = SQUARE(counter++);  // Expands to: ((counter++) * (counter++))
    std::cout << "SQUARE(counter++) = " << macro_result << std::endl;
    std::cout << "counter after macro = " << counter << std::endl;
    // counter++ is evaluated TWICE! counter becomes 7, not 6
    
    // Using inline function (safe)
    counter = 5;
    int inline_result = inlineSquare(counter++);  // counter++ evaluated ONCE
    std::cout << "inlineSquare(counter++) = " << inline_result << std::endl;
    std::cout << "counter after inline = " << counter << std::endl;
    // counter++ is evaluated ONCE, counter becomes 6 (correct!)
    
    // --- Example 6: No type checking in macros ---
    std::cout << "\n--- Example 6: No Type Checking ---" << std::endl;
    std::cout << "ADD(5, 3) = " << ADD(5, 3) << std::endl;
    std::cout << "ADD(5.5, 3.2) = " << ADD(5.5, 3.2) << std::endl;
    std::cout << "ADD(\"Hello\", \"World\") won't compile but macro accepts it" << std::endl;
    // Macros don't check types - they just replace text!
    
    // --- Example 7: Macro vs Inline comparison ---
    std::cout << "\n--- Example 7: Macro vs Inline Function ---" << std::endl;
    int a = 10, b = 20;
    std::cout << "MAX macro(10, 20) = " << MAX(a, b) << std::endl;
    std::cout << "inlineMax function(10, 20) = " << inlineMax(a, b) << std::endl;
    // Both give same result, but inline function is safer!
    
    // --- Summary ---
    std::cout << "\n--- Summary ---" << std::endl;
    std::cout << "Macros:" << std::endl;
    std::cout << "  + Fast (no function call overhead)" << std::endl;
    std::cout << "  + Work with any type" << std::endl;
    std::cout << "  - No type checking" << std::endl;
    std::cout << "  - Can cause side effects" << std::endl;
    std::cout << "  - Hard to debug" << std::endl;
    std::cout << "  - Text replacement can be unexpected" << std::endl;
    std::cout << "\nInline Functions:" << std::endl;
    std::cout << "  + Type safe" << std::endl;
    std::cout << "  + No side effects" << std::endl;
    std::cout << "  + Easy to debug" << std::endl;
    std::cout << "  + Behave like normal functions" << std::endl;
    std::cout << "  - Only work with specific types (unless template)" << std::endl;
    
    return 0;
}

// === HOW PREPROCESSOR WORKS ===
// Step 1: Preprocessor runs BEFORE compilation
// Step 2: It replaces all macros with their definitions (text replacement)
// Step 3: Then the compiler compiles the modified code

// Example of preprocessor output:
// Original code:    int area = SQUARE(5);
// After preprocessor: int area = ((5) * (5));
// Then compiler sees: int area = ((5) * (5));
