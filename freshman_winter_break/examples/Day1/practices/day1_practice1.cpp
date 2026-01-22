#include <iostream>
#include <string>
#include <stdexcept>
#include <cmath>        // For floating point comparison
#include <limits>       // For numeric limits

// Constants for better maintainability
namespace Calculator {
    constexpr double EPSILON = 1e-9;  // For floating point comparison
}

// Optimized calculate function with better error handling
double calculate(const char operation, const double num1, const double num2) {
    switch(operation) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            // Better floating point zero comparison
            if (std::abs(num2) < Calculator::EPSILON) {
                throw std::invalid_argument("Division by zero");
            }
            return num1 / num2;
        default:
            throw std::invalid_argument("Invalid operation. Use +, -, *, /");
    }
}

// Optimized string conversion with better validation
bool safe_string_to_double(const std::string& str, double& result) {
    // Input validation - check for empty string
    if (str.empty()) {
        return false;
    }
    
    try {
        size_t pos = 0;
        result = std::stod(str, &pos);
        
        // Check if entire string was consumed (no trailing characters)
        if (pos != str.length()) {
            return false;  // Partial conversion (e.g., "123abc")
        }
        
        // Check if result is finite (not infinity or NaN)
        if (!std::isfinite(result)) {
            return false;
        }
        
        return true;  // Success
    } catch (const std::invalid_argument&) {
        return false;  // Invalid format
    } catch (const std::out_of_range&) {
        return false;  // Number too large
    }
}

int main() {
    std::cout << "=== Optimized Simple Calculator ===" << std::endl;
    
    // Test basic operations
    std::cout << "\n--- Basic Operations ---" << std::endl;
    try {
        std::cout << "5 + 3 = " << calculate('+', 5.0, 3.0) << std::endl;
        std::cout << "10 - 4 = " << calculate('-', 10.0, 4.0) << std::endl;
        std::cout << "6 * 7 = " << calculate('*', 6.0, 7.0) << std::endl;
        std::cout << "15 / 3 = " << calculate('/', 15.0, 3.0) << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error in basic operations: " << e.what() << std::endl;
    }
    
    // Test error cases
    std::cout << "\n--- Error Handling Tests ---" << std::endl;
    
    // Test division by zero
    try {
        std::cout << "10 / 0 = " << calculate('/', 10.0, 0.0) << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Division by zero caught: " << e.what() << std::endl;
    }
    
    // Test invalid operation
    try {
        std::cout << "5 ^ 2 = " << calculate('^', 5.0, 2.0) << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Invalid operation caught: " << e.what() << std::endl;
    }
    
    // Test very small divisor (close to zero)
    try {
        std::cout << "10 / 1e-15 = " << calculate('/', 10.0, 1e-15) << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Very small divisor caught: " << e.what() << std::endl;
    }
    
    // Test string conversion
    std::cout << "\n--- String Conversion Tests ---" << std::endl;
    double result;
    
    // Valid conversions
    if (safe_string_to_double("123.45", result)) {
        std::cout << "Converted '123.45': " << result << std::endl;
    }
    
    if (safe_string_to_double("-67.89", result)) {
        std::cout << "Converted '-67.89': " << result << std::endl;
    }
    
    if (safe_string_to_double("0", result)) {
        std::cout << "Converted '0': " << result << std::endl;
    }
    
    // Invalid conversions
    std::cout << "\n--- Invalid String Tests ---" << std::endl;
    if (!safe_string_to_double("invalid", result)) {
        std::cout << "Failed to convert 'invalid' (expected)" << std::endl;
    }
    
    if (!safe_string_to_double("123abc", result)) {
        std::cout << "Failed to convert '123abc' (expected)" << std::endl;
    }
    
    if (!safe_string_to_double("", result)) {
        std::cout << "Failed to convert empty string (expected)" << std::endl;
    }
    
    if (!safe_string_to_double("1.23.45", result)) {
        std::cout << "Failed to convert '1.23.45' (expected)" << std::endl;
    }
    
    return 0;
}
