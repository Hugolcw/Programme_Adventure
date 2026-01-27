#include <iostream>

// === Practice 3: Function Pointer Basics (函数指针基础) ===
// Learn how to use pointers to functions

// TODO: Task 1 - Basic function pointers
// Create three simple math functions: add, subtract, multiply
// Each takes two ints and returns an int
// Then create a function pointer and use it to call each function

// Your code here for math functions
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

// Note: These global pointers are not needed for the tasks
// You'll create pointers in main() instead

// TODO: Task 2 - Function pointer as parameter
// Create a function calculate() that takes:
//   - Two integers (a, b)
//   - A function pointer to an operation (add, subtract, multiply)
// calculate() should call the operation and return result

// Your code here for calculate() function
int calculate(int a, int b, int (*function_pointer)(int, int)) {
    return function_pointer(a, b);
}

// TODO: Task 3 - Array of function pointers
// Create an array of function pointers to your math functions
// Use a loop to call each function with the same inputs

// This will be implemented in main()

// TODO: Task 4 - Calculator with function pointers
// Create a simple calculator that:
//   - Takes two numbers and an operation choice (0=add, 1=sub, 2=mul)
//   - Uses function pointer array to call the correct operation

// Your code here for calculator() function
int calculator(int a, int b, int choice) {
    int (*operations[3])(int, int) = {add, subtract, multiply};
    return operations[choice](a, b);  // ✅ Call the function!
}


int main() {
    std::cout << "=== Practice 3: Function Pointer Basics ===" << std::endl;
    
    // --- Test Task 1: Basic function pointers ---
    std::cout << "\n--- Task 1: Basic Function Pointers ---" << std::endl;
    int (*operation)(int, int);  // Declare function pointer
    
    operation = add;             // Point to add function
    std::cout << "add(5, 3) = " << operation(5, 3) << std::endl;
    
    operation = subtract;        // Point to subtract function
    std::cout << "subtract(5, 3) = " << operation(5, 3) << std::endl;
    
    operation = multiply;        // Point to multiply function
    std::cout << "multiply(5, 3) = " << operation(5, 3) << std::endl;
    
    // --- Test Task 2: Function pointer as parameter ---
    std::cout << "\n--- Task 2: Function Pointer as Parameter ---" << std::endl;
    std::cout << "calculate(10, 5, add) = " << calculate(10, 5, add) << std::endl;
    std::cout << "calculate(10, 5, subtract) = " << calculate(10, 5, subtract) << std::endl;
    std::cout << "calculate(10, 5, multiply) = " << calculate(10, 5, multiply) << std::endl;
    
    // --- Test Task 3: Array of function pointers ---
    std::cout << "\n--- Task 3: Array of Function Pointers ---" << std::endl;
    int (*operations[3])(int, int) = {add, subtract, multiply};
    const char* names[3] = {"add", "subtract", "multiply"};  // Better output
    for (int i = 0; i < 3; i++) {
        std::cout << names[i] << "(10, 5) = " << operations[i](10, 5) << std::endl;
    }
    
    // --- Test Task 4: Calculator ---
    std::cout << "\n--- Task 4: Calculator with Function Pointers ---" << std::endl;
    std::cout << "calculator(10, 5, 0) = " << calculator(10, 5, 0) << std::endl;  // add
    std::cout << "calculator(10, 5, 1) = " << calculator(10, 5, 1) << std::endl;  // subtract
    std::cout << "calculator(10, 5, 2) = " << calculator(10, 5, 2) << std::endl;  // multiply
    
    return 0;
}
