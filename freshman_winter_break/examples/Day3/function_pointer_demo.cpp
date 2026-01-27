#include <iostream>

// === WHAT IS A FUNCTION POINTER? (什么是函数指针?) ===
// A function pointer is a variable that stores the ADDRESS of a function
// You can use it to call the function indirectly

// === STEP 1: Create some simple functions ===
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

// === STEP 2: Function that takes function pointer as parameter ===
int calculate(int x, int y, int (*operation)(int, int)) {
    // operation is a function pointer
    // We call the function it points to
    return operation(x, y);
}

// === STEP 3: Function that prints using any operation ===
void printOperation(int a, int b, int (*func)(int, int), const char* name) {
    int result = func(a, b);
    std::cout << name << "(" << a << ", " << b << ") = " << result << std::endl;
}

int main() {
    std::cout << "=== Function Pointer Demonstration ===" << std::endl;
    
    // --- Example 1: Declare and use a function pointer ---
    std::cout << "\n--- Example 1: Basic Function Pointer ---" << std::endl;
    
    // Syntax: return_type (*pointer_name)(parameter_types)
    int (*operation)(int, int);  // Declare a function pointer
    
    // Point to the add function
    operation = add;  // or: operation = &add; (both work)
    
    // Call the function through the pointer
    int result1 = operation(5, 3);  // Calls add(5, 3)
    std::cout << "operation(5, 3) = " << result1 << std::endl;
    
    // Alternative calling syntax (both work the same)
    int result2 = (*operation)(5, 3);  // Also calls add(5, 3)
    std::cout << "(*operation)(5, 3) = " << result2 << std::endl;
    
    // --- Example 2: Change what the pointer points to ---
    std::cout << "\n--- Example 2: Changing Function Pointer ---" << std::endl;
    
    operation = add;
    std::cout << "operation points to add: " << operation(10, 5) << std::endl;
    
    operation = subtract;
    std::cout << "operation points to subtract: " << operation(10, 5) << std::endl;
    
    operation = multiply;
    std::cout << "operation points to multiply: " << operation(10, 5) << std::endl;
    
    // --- Example 3: Pass function pointer to another function ---
    std::cout << "\n--- Example 3: Function Pointer as Parameter ---" << std::endl;
    
    std::cout << "calculate(10, 5, add) = " << calculate(10, 5, add) << std::endl;
    std::cout << "calculate(10, 5, subtract) = " << calculate(10, 5, subtract) << std::endl;
    std::cout << "calculate(10, 5, multiply) = " << calculate(10, 5, multiply) << std::endl;
    
    // --- Example 4: Array of function pointers ---
    std::cout << "\n--- Example 4: Array of Function Pointers ---" << std::endl;
    
    // Create an array of function pointers
    int (*operations[3])(int, int) = {add, subtract, multiply};
    const char* names[3] = {"add", "subtract", "multiply"};
    
    // Use a loop to call each function
    for (int i = 0; i < 3; i++) {
        int result = operations[i](20, 4);  // Call through pointer
        std::cout << names[i] << "(20, 4) = " << result << std::endl;
    }
    
    // --- Example 5: Using helper function ---
    std::cout << "\n--- Example 5: Helper Function with Function Pointer ---" << std::endl;
    
    printOperation(15, 3, add, "add");
    printOperation(15, 3, subtract, "subtract");
    printOperation(15, 3, multiply, "multiply");
    
    // --- Example 6: Simple calculator using function pointers ---
    std::cout << "\n--- Example 6: Simple Calculator ---" << std::endl;
    
    int (*calc_operations[3])(int, int) = {add, subtract, multiply};
    const char* symbols[3] = {"+", "-", "*"};
    
    int a = 12, b = 4;
    for (int i = 0; i < 3; i++) {
        std::cout << a << " " << symbols[i] << " " << b << " = " 
                  << calc_operations[i](a, b) << std::endl;
    }
    
    // --- Example 7: Menu-driven calculator ---
    std::cout << "\n--- Example 7: Menu-Driven Calculator ---" << std::endl;
    
    std::cout << "Choose operation:" << std::endl;
    std::cout << "0: Add" << std::endl;
    std::cout << "1: Subtract" << std::endl;
    std::cout << "2: Multiply" << std::endl;
    
    int choice = 1;  // Let's choose subtract
    std::cout << "Choice: " << choice << std::endl;
    
    if (choice >= 0 && choice < 3) {
        int result = calc_operations[choice](100, 25);
        std::cout << "Result: " << result << std::endl;
    }
    
    return 0;
}

// === KEY POINTS ===
// 1. Function pointer syntax: return_type (*pointer_name)(parameter_types)
// 2. Assign function to pointer: pointer = function_name;
// 3. Call through pointer: pointer(args) or (*pointer)(args)
// 4. Use case: When you want to choose which function to call at runtime
