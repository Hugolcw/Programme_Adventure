#include <iostream>
#include <string>

// Global variables and constants
int global_var = 100;
const int GLOBAL_CONSTANT = 42;
const std::string COMPANY_NAME = "TechCorp";

// Function to demonstrate local scope
void demonstrate_local_scope() {
    std::cout << "\n--- Local Scope Demo ---" << std::endl;
    
    int local_var = 10;
    const int LOCAL_CONSTANT = 20;
    
    std::cout << "Local variable: " << local_var << std::endl;
    std::cout << "Local constant: " << LOCAL_CONSTANT << std::endl;
    
    // Block scope
    {
        int block_var = 30;
        std::cout << "Block variable: " << block_var << std::endl;
        std::cout << "Can access local_var from outer scope: " << local_var << std::endl;
    }
    // block_var is not accessible here
    // std::cout << block_var; // This would cause an error
}

// Function to demonstrate parameter scope
void demonstrate_parameters(int param1, const int param2) {
    std::cout << "\n--- Parameter Scope Demo ---" << std::endl;
    std::cout << "Parameter 1: " << param1 << std::endl;
    std::cout << "Parameter 2 (const): " << param2 << std::endl;
    
    param1 = 999;  // OK - can modify non-const parameter
    // param2 = 888;  // Error - cannot modify const parameter
    
    std::cout << "Modified param1: " << param1 << std::endl;
}

int main() {
    std::cout << "=== C++ Constants and Scope Examples ===" << std::endl;
    
    // 1. Different types of constants
    std::cout << "\n--- Types of Constants ---" << std::endl;
    
    // Literal constants
    const int MAX_STUDENTS = 50;
    const double PI = 3.14159;
    const char GRADE_A = 'A';
    const std::string WELCOME_MSG = "Welcome to C++ Learning!";
    
    std::cout << "Max students: " << MAX_STUDENTS << std::endl;
    std::cout << "PI value: " << PI << std::endl;
    std::cout << "Grade A: " << GRADE_A << std::endl;
    std::cout << "Welcome message: " << WELCOME_MSG << std::endl;
    
    // 2. const vs non-const variables
    std::cout << "\n--- const vs non-const ---" << std::endl;
    
    int mutable_var = 10;
    const int immutable_var = 20;
    
    std::cout << "Before: mutable = " << mutable_var << ", immutable = " << immutable_var << std::endl;
    
    mutable_var = 15;  // OK
    // immutable_var = 25;  // Error - cannot modify const variable
    
    std::cout << "After: mutable = " << mutable_var << ", immutable = " << immutable_var << std::endl;
    
    // 3. Global vs local scope
    std::cout << "\n--- Global vs Local Scope ---" << std::endl;
    
    std::cout << "Global variable: " << global_var << std::endl;
    std::cout << "Global constant: " << GLOBAL_CONSTANT << std::endl;
    std::cout << "Company name: " << COMPANY_NAME << std::endl;
    
    // Local variable with same name as global
    int global_var = 200;  // This shadows the global variable
    std::cout << "Local global_var (shadows global): " << global_var << std::endl;
    std::cout << "Access global using ::: " << ::global_var << std::endl;
    
    // 4. Function scope demonstrations
    demonstrate_local_scope();
    demonstrate_parameters(100, 200);
    
    // 5. Static variables
    std::cout << "\n--- Static Variables ---" << std::endl;
    
    for (int i = 0; i < 3; ++i) {
        static int static_counter = 0;  // Initialized only once
        int normal_counter = 0;         // Initialized every iteration
        
        static_counter++;
        normal_counter++;
        
        std::cout << "Iteration " << i + 1 << ": ";
        std::cout << "static_counter = " << static_counter << ", ";
        std::cout << "normal_counter = " << normal_counter << std::endl;
    }
    
    // 6. Auto keyword for type deduction
    std::cout << "\n--- Auto Keyword ---" << std::endl;
    
    auto auto_int = 42;           // Deduced as int
    auto auto_double = 3.14;      // Deduced as double
    auto auto_string = "Hello";   // Deduced as const char*
    auto auto_cpp_string = std::string("World");  // Deduced as std::string
    
    std::cout << "auto_int: " << auto_int << " (type: int)" << std::endl;
    std::cout << "auto_double: " << auto_double << " (type: double)" << std::endl;
    std::cout << "auto_string: " << auto_string << " (type: const char*)" << std::endl;
    std::cout << "auto_cpp_string: " << auto_cpp_string << " (type: std::string)" << std::endl;
    
    // 7. Const with pointers
    std::cout << "\n--- Const with Pointers ---" << std::endl;
    
    int value1 = 10, value2 = 20;
    
    // Pointer to const int
    const int* ptr_to_const = &value1;
    std::cout << "Pointer to const: " << *ptr_to_const << std::endl;
    // *ptr_to_const = 15;  // Error - cannot modify value through this pointer
    ptr_to_const = &value2;  // OK - can change what pointer points to
    std::cout << "After changing pointer: " << *ptr_to_const << std::endl;
    
    // Const pointer to int
    int* const const_ptr = &value1;
    std::cout << "Const pointer: " << *const_ptr << std::endl;
    *const_ptr = 15;  // OK - can modify value
    // const_ptr = &value2;  // Error - cannot change what pointer points to
    std::cout << "After modifying value: " << *const_ptr << std::endl;
    
    // Const pointer to const int
    const int* const const_ptr_to_const = &value2;
    std::cout << "Const pointer to const: " << *const_ptr_to_const << std::endl;
    // *const_ptr_to_const = 25;  // Error - cannot modify value
    // const_ptr_to_const = &value1;  // Error - cannot change pointer
    
    return 0;
}
