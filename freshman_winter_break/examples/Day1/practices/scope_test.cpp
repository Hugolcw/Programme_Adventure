#include <iostream>

// Global variable
int MAX_STUDENTS = 100;

void test_nested_scope_access() {
    std::cout << "=== Testing :: in Nested Scopes ===" << std::endl;
    
    // Function scope
    int MAX_STUDENTS = 50;  // Shadows global
    std::cout << "Function scope MAX_STUDENTS: " << MAX_STUDENTS << std::endl;
    std::cout << "Global MAX_STUDENTS (::): " << ::MAX_STUDENTS << std::endl;
    
    {
        // First block scope
        int MAX_STUDENTS = 25;  // Shadows both global and function
        std::cout << "\n--- First Block Scope ---" << std::endl;
        std::cout << "Block MAX_STUDENTS: " << MAX_STUDENTS << std::endl;
        std::cout << "Global MAX_STUDENTS (::): " << ::MAX_STUDENTS << std::endl;
        
        {
            // Second nested block scope
            int MAX_STUDENTS = 10;  // Shadows all outer scopes
            std::cout << "\n--- Second Nested Block Scope ---" << std::endl;
            std::cout << "Innermost MAX_STUDENTS: " << MAX_STUDENTS << std::endl;
            std::cout << "Global MAX_STUDENTS (::): " << ::MAX_STUDENTS << std::endl;
            
            {
                // Third nested block scope
                int MAX_STUDENTS = 5;  // Shadows everything
                std::cout << "\n--- Third Nested Block Scope ---" << std::endl;
                std::cout << "Deepest MAX_STUDENTS: " << MAX_STUDENTS << std::endl;
                std::cout << "Global MAX_STUDENTS (::): " << ::MAX_STUDENTS << std::endl;
                
                // :: ALWAYS goes to global, no matter how deep!
                std::cout << ":: always reaches global: " << ::MAX_STUDENTS << std::endl;
            }
            
            std::cout << "\n--- Back to Second Block ---" << std::endl;
            std::cout << "Second block MAX_STUDENTS: " << MAX_STUDENTS << std::endl;
            std::cout << "Global (::): " << ::MAX_STUDENTS << std::endl;
        }
        
        std::cout << "\n--- Back to First Block ---" << std::endl;
        std::cout << "First block MAX_STUDENTS: " << MAX_STUDENTS << std::endl;
        std::cout << "Global (::): " << ::MAX_STUDENTS << std::endl;
    }
    
    std::cout << "\n--- Back to Function Scope ---" << std::endl;
    std::cout << "Function MAX_STUDENTS: " << MAX_STUDENTS << std::endl;
    std::cout << "Global (::): " << ::MAX_STUDENTS << std::endl;
}

// Let's also test with different variable names to make it clearer
void demonstrate_scope_layers() {
    std::cout << "\n\n=== Scope Layers Visualization ===" << std::endl;
    
    int level = 1;  // Function level
    std::cout << "Function level: " << level << std::endl;
    std::cout << "Global MAX_STUDENTS: " << ::MAX_STUDENTS << std::endl;
    
    {
        int level = 2;  // Block level 1
        std::cout << "\nBlock level 1: " << level << std::endl;
        std::cout << "Global MAX_STUDENTS: " << ::MAX_STUDENTS << std::endl;
        
        {
            int level = 3;  // Block level 2
            std::cout << "\nBlock level 2: " << level << std::endl;
            std::cout << "Global MAX_STUDENTS: " << ::MAX_STUDENTS << std::endl;
            
            {
                int level = 4;  // Block level 3
                std::cout << "\nBlock level 3: " << level << std::endl;
                std::cout << "Global MAX_STUDENTS: " << ::MAX_STUDENTS << std::endl;
                
                // No matter how deep, :: always reaches the global scope!
                std::cout << ":: reaches through ALL layers to global!" << std::endl;
            }
        }
    }
}

int main() {
    test_nested_scope_access();
    demonstrate_scope_layers();
    return 0;
}