#include <iostream>

// Global constants
const int MAX_STUDENTS = 100;
const double PI = 3.14159;

// TODO: Implement this function
// Requirements:
// 1. Use static variable to count function calls
// 2. Use const parameter
// 3. Demonstrate local vs global scope
void demonstrate_scope(const std::string& message) {
    // Static variable - retains value between function calls
    static int call_count = 0;  // Initialized only once!
    call_count++;  // Increment each time function is called
    
    // Local variable - created fresh each time
    int local_var = 42;
    
    std::cout << "\n--- Function Call #" << call_count << " ---" << std::endl;
    std::cout << "Message: " << message << std::endl;
    std::cout << "Local variable: " << local_var << std::endl;
    std::cout << "Global MAX_STUDENTS: " << MAX_STUDENTS << std::endl;
    std::cout << "Global PI: " << PI << std::endl;
    
    // Demonstrate that local_var is recreated each time
    local_var = 999;
    std::cout << "Modified local_var to: " << local_var << std::endl;
    std::cout << "Static call_count will persist: " << call_count << std::endl;
}

// TODO: Implement this function
// Requirements:
// 1. Create local variables that shadow global ones
// 2. Show how to access global variables using ::
// 3. Use block scope for temporary calculations
void scope_shadowing_demo() {
    std::cout << "\n=== Scope Shadowing Demo ===" << std::endl;
    
    // Create local variables with same names as globals (shadowing)
    int MAX_STUDENTS = 50;      // Shadows global MAX_STUDENTS
    double PI = 2.71828;        // Shadows global PI (using e instead)
    
    std::cout << "Local MAX_STUDENTS: " << MAX_STUDENTS << std::endl;
    std::cout << "Global MAX_STUDENTS (using ::): " << ::MAX_STUDENTS << std::endl;
    std::cout << "Local PI: " << PI << std::endl;
    std::cout << "Global PI (using ::): " << ::PI << std::endl;
    
    // Block scope for temporary calculations
    {
        std::cout << "\n--- Inside Block Scope ---" << std::endl;
        
        // Temporary variables for calculation
        int temp1 = MAX_STUDENTS * 2;           // Uses local MAX_STUDENTS (50)
        int temp2 = ::MAX_STUDENTS * 2;         // Uses global MAX_STUDENTS (100)
        double temp3 = PI * 2;                  // Uses local PI (2.71828)
        double temp4 = ::PI * 2;                // Uses global PI (3.14159)
        
        std::cout << "temp1 (local MAX_STUDENTS * 2): " << temp1 << std::endl;
        std::cout << "temp2 (global MAX_STUDENTS * 2): " << temp2 << std::endl;
        std::cout << "temp3 (local PI * 2): " << temp3 << std::endl;
        std::cout << "temp4 (global PI * 2): " << temp4 << std::endl;
        
        // Even more nested scope
        {
            std::cout << "\n--- Nested Block Scope ---" << std::endl;
            int MAX_STUDENTS = 25;  // Shadows both global and outer local
            std::cout << "Innermost MAX_STUDENTS: " << MAX_STUDENTS << std::endl;
            std::cout << "Still can access global: " << ::MAX_STUDENTS << std::endl;
        }
        
        std::cout << "\n--- Back to First Block ---" << std::endl;
        std::cout << "Block MAX_STUDENTS: " << MAX_STUDENTS << " (outer local)" << std::endl;
        
    } // temp1, temp2, temp3, temp4 are destroyed here
    
    std::cout << "\n--- Back to Function Scope ---" << std::endl;
    std::cout << "Function MAX_STUDENTS: " << MAX_STUDENTS << " (local)" << std::endl;
    std::cout << "Global MAX_STUDENTS: " << ::MAX_STUDENTS << std::endl;
    
    // temp1, temp2, temp3, temp4 no longer exist here
    // std::cout << temp1;  // This would be an error!
}

int main() {
    std::cout << "=== Scope and Constants Demo ===" << std::endl;
    
    // Test demonstrate_scope multiple times
    demonstrate_scope("First call");
    demonstrate_scope("Second call");
    demonstrate_scope("Third call");
    
    // Test scope shadowing
    scope_shadowing_demo();
    
    return 0;
}
