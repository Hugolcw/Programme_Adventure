#include <iostream>

void demonstrate_scope_access_problem() {
    std::cout << "=== Scope Access Problem ===" << std::endl;
    
    {
        // Block 1
        int value = 100;  // Block 1's variable
        std::cout << "Block 1 - value: " << value << std::endl;
        
        {
            // Block 2
            int value = 200;  // Block 2's variable (shadows Block 1's)
            std::cout << "Block 2 - value: " << value << std::endl;
            
            // ❌ PROBLEM: How to access Block 1's value (100) from here?
            // There's NO direct way to access Block 1's 'value' variable!
            
            std::cout << "Can I access Block 1's value? NO! 😞" << std::endl;
            // The name 'value' now refers to Block 2's variable (200)
        }
    }
}

// Solution 1: Use different variable names
void solution1_different_names() {
    std::cout << "\n=== Solution 1: Different Variable Names ===" << std::endl;
    
    {
        // Block 1
        int block1_value = 100;
        std::cout << "Block 1 - block1_value: " << block1_value << std::endl;
        
        {
            // Block 2
            int block2_value = 200;
            std::cout << "Block 2 - block2_value: " << block2_value << std::endl;
            
            // ✅ Now I can access both!
            std::cout << "Accessing Block 1's value: " << block1_value << std::endl;
            std::cout << "Accessing Block 2's value: " << block2_value << std::endl;
        }
    }
}

// Solution 2: Copy the value before entering inner scope
void solution2_copy_value() {
    std::cout << "\n=== Solution 2: Copy Before Shadowing ===" << std::endl;
    
    {
        // Block 1
        int value = 100;
        std::cout << "Block 1 - value: " << value << std::endl;
        
        // Copy the value before it gets shadowed
        int outer_value = value;
        
        {
            // Block 2
            int value = 200;  // Shadows Block 1's value
            std::cout << "Block 2 - value: " << value << std::endl;
            
            // ✅ Access Block 1's value through the copy
            std::cout << "Block 1's value (via copy): " << outer_value << std::endl;
            std::cout << "Block 2's value: " << value << std::endl;
        }
    }
}

// Solution 3: Use references to preserve access
void solution3_references() {
    std::cout << "\n=== Solution 3: Using References ===" << std::endl;
    
    {
        // Block 1
        int value = 100;
        std::cout << "Block 1 - value: " << value << std::endl;
        
        // Create a reference to Block 1's value
        int& outer_ref = value;
        
        {
            // Block 2
            int value = 200;  // Shadows Block 1's value
            std::cout << "Block 2 - value: " << value << std::endl;
            
            // ✅ Access Block 1's value through the reference
            std::cout << "Block 1's value (via reference): " << outer_ref << std::endl;
            std::cout << "Block 2's value: " << value << std::endl;
            
            // Can even modify Block 1's value through reference
            outer_ref = 150;
            std::cout << "Modified Block 1's value to: " << outer_ref << std::endl;
        }
        
        std::cout << "Back in Block 1 - value is now: " << value << std::endl;
    }
}

// Solution 4: Restructure code to avoid the problem
void solution4_restructure() {
    std::cout << "\n=== Solution 4: Code Restructuring ===" << std::endl;
    
    // Instead of nested blocks with same variable names,
    // use separate blocks or functions
    
    int block1_result;
    {
        // Block 1 - do some work
        int value = 100;
        std::cout << "Block 1 processing: " << value << std::endl;
        block1_result = value * 2;  // Save result
    }
    
    int block2_result;
    {
        // Block 2 - do different work
        int value = 200;
        std::cout << "Block 2 processing: " << value << std::endl;
        block2_result = value * 3;  // Save result
    }
    
    // Now use both results
    std::cout << "Block 1 result: " << block1_result << std::endl;
    std::cout << "Block 2 result: " << block2_result << std::endl;
    std::cout << "Combined: " << (block1_result + block2_result) << std::endl;
}

// Demonstration of what C++ scope resolution can and cannot do
void scope_resolution_limits() {
    std::cout << "\n=== Scope Resolution Operator Limitations ===" << std::endl;
    
    int global_var = 999;  // Global scope
    
    {
        int global_var = 100;  // Function/Block scope (shadows global)
        std::cout << "Local global_var: " << global_var << std::endl;
        std::cout << "Global global_var: " << ::global_var << std::endl;
        
        {
            int global_var = 50;  // Inner block (shadows outer block)
            std::cout << "Inner global_var: " << global_var << std::endl;
            std::cout << "Global global_var: " << ::global_var << std::endl;
            
            // ❌ There's NO operator to access the outer block's variable!
            // :: only goes to global scope
            // There's no "one level up" operator
            
            std::cout << "Cannot access outer block's global_var directly!" << std::endl;
        }
    }
}

int main() {
    demonstrate_scope_access_problem();
    solution1_different_names();
    solution2_copy_value();
    solution3_references();
    solution4_restructure();
    scope_resolution_limits();
    
    return 0;
}