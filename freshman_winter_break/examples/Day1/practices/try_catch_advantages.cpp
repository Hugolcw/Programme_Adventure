#include <iostream>
#include <string>
#include <vector>

// ❌ BAD: Without try/catch - Program crashes!
void parse_without_exception_handling(const std::string& csv) {
    std::cout << "=== WITHOUT try/catch (BAD) ===" << std::endl;
    std::cout << "Parsing: " << csv << std::endl;
    
    std::vector<int> result;
    std::string token = "abc";  // Simulate invalid token
    
    // This will CRASH the program!
    int number = std::stoi(token);  // CRASH! "abc" can't convert to int
    result.push_back(number);
    
    std::cout << "This line will NEVER execute!" << std::endl;
}

// ✅ GOOD: With try/catch - Program continues gracefully
void parse_with_exception_handling(const std::string& csv) {
    std::cout << "=== WITH try/catch (GOOD) ===" << std::endl;
    std::cout << "Parsing: " << csv << std::endl;
    
    std::vector<int> result;
    std::string tokens[] = {"10", "abc", "20", "xyz", "30"};
    
    for (const std::string& token : tokens) {
        try {
            int number = std::stoi(token);  // Might throw exception
            result.push_back(number);
            std::cout << "✅ Successfully converted: " << token << " -> " << number << std::endl;
        } catch (const std::exception& e) {
            std::cout << "⚠️  Skipped invalid token: '" << token << "' (" << e.what() << ")" << std::endl;
            // Program continues! No crash!
        }
    }
    
    std::cout << "Final result has " << result.size() << " valid numbers" << std::endl;
    std::cout << "Program continues normally!" << std::endl;
}

// Demonstrate different error handling approaches
void demonstrate_error_handling_approaches() {
    std::cout << "\n=== Different Error Handling Approaches ===" << std::endl;
    
    std::string test_inputs[] = {"123", "abc", "456", "xyz"};
    
    // Approach 1: Manual checking (tedious and error-prone)
    std::cout << "\n--- Approach 1: Manual Checking ---" << std::endl;
    for (const std::string& input : test_inputs) {
        bool is_valid = true;
        for (char c : input) {
            if (!std::isdigit(c)) {
                is_valid = false;
                break;
            }
        }
        
        if (is_valid) {
            int number = std::stoi(input);  // Still risky! What if number is too big?
            std::cout << "✅ Valid: " << input << " -> " << number << std::endl;
        } else {
            std::cout << "❌ Invalid: " << input << std::endl;
        }
    }
    
    // Approach 2: try/catch (clean and robust)
    std::cout << "\n--- Approach 2: try/catch (Recommended) ---" << std::endl;
    for (const std::string& input : test_inputs) {
        try {
            int number = std::stoi(input);
            std::cout << "✅ Valid: " << input << " -> " << number << std::endl;
        } catch (const std::invalid_argument&) {
            std::cout << "❌ Invalid format: " << input << std::endl;
        } catch (const std::out_of_range&) {
            std::cout << "❌ Number too large: " << input << std::endl;
        }
    }
}

// Show what happens with different types of errors
void demonstrate_different_exceptions() {
    std::cout << "\n=== Different Types of Exceptions ===" << std::endl;
    
    std::string test_cases[] = {
        "123",                    // Valid
        "abc",                    // Invalid format
        "999999999999999999999",  // Too large for int
        "",                       // Empty string
        "  456  "                 // Valid with spaces
    };
    
    for (const std::string& test : test_cases) {
        std::cout << "\nTesting: '" << test << "'" << std::endl;
        
        try {
            int result = std::stoi(test);
            std::cout << "✅ Success: " << result << std::endl;
        } catch (const std::invalid_argument& e) {
            std::cout << "❌ Invalid argument: " << e.what() << std::endl;
        } catch (const std::out_of_range& e) {
            std::cout << "❌ Out of range: " << e.what() << std::endl;
        } catch (const std::exception& e) {
            std::cout << "❌ Other error: " << e.what() << std::endl;
        }
    }
}

// Real-world example: File processing
void simulate_file_processing() {
    std::cout << "\n=== Real-world Example: Processing Data File ===" << std::endl;
    
    // Simulate reading lines from a data file
    std::vector<std::string> file_lines = {
        "100",      // Valid
        "200",      // Valid  
        "invalid",  // Invalid
        "300",      // Valid
        "",         // Empty line
        "400"       // Valid
    };
    
    std::vector<int> valid_numbers;
    int line_number = 1;
    
    std::cout << "Processing data file..." << std::endl;
    
    for (const std::string& line : file_lines) {
        std::cout << "Line " << line_number << ": '" << line << "' -> ";
        
        try {
            if (line.empty()) {
                std::cout << "Skipped (empty line)" << std::endl;
                line_number++;
                continue;
            }
            
            int number = std::stoi(line);
            valid_numbers.push_back(number);
            std::cout << "✅ Added: " << number << std::endl;
            
        } catch (const std::exception& e) {
            std::cout << "⚠️  Skipped: " << e.what() << std::endl;
        }
        
        line_number++;
    }
    
    std::cout << "\nFile processing completed!" << std::endl;
    std::cout << "Valid numbers found: " << valid_numbers.size() << std::endl;
    std::cout << "Program continues normally despite errors!" << std::endl;
}

int main() {
    std::cout << "=== Advantages of try/catch ===" << std::endl;
    
    // Demonstrate graceful error handling
    parse_with_exception_handling("10,abc,20,xyz,30");
    
    // Show different approaches
    demonstrate_error_handling_approaches();
    
    // Show different exception types
    demonstrate_different_exceptions();
    
    // Real-world example
    simulate_file_processing();
    
    std::cout << "\n=== Summary of try/catch Advantages ===" << std::endl;
    std::cout << "1. ✅ Program doesn't crash on errors" << std::endl;
    std::cout << "2. ✅ Can handle different types of errors differently" << std::endl;
    std::cout << "3. ✅ Clean separation of normal code and error handling" << std::endl;
    std::cout << "4. ✅ Can provide meaningful error messages" << std::endl;
    std::cout << "5. ✅ Allows program to continue processing other data" << std::endl;
    
    // WARNING: Don't run this - it will crash!
    // parse_without_exception_handling("10,abc,20");
    std::cout << "\n⚠️  Note: The 'without try/catch' example is commented out" << std::endl;
    std::cout << "    because it would crash the program!" << std::endl;
    
    return 0;
}