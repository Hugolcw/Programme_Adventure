#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>  // For std::setprecision

// TODO: Implement this function
// Requirements:
// 1. Parse a string like "10,20,30,40" into vector of integers
// 2. Use stringstream for parsing
// 3. Handle invalid numbers gracefully
// 4. Use const string parameter
std::vector<int> parse_csv_numbers(const std::string& csv_string) {
    // Your implementation here
    // Hint: Use stringstream, getline with ',' delimiter, and stoi
    std::vector<int> result;
    std::stringstream ss(csv_string);
    std::string token;

    while (std::getline(ss, token, ',')) {
        try {
            int number = std::stoi(token);
            result.push_back(number);
        } catch (const std::exception&) {
            std::cout << "Skipping invalid token: '" << token << "'" << std::endl;
        }
    }

    return result;
}

// TODO: Implement this function
// Requirements:
// 1. Convert vector of numbers to formatted string
// 2. Use const vector parameter
// 3. Format: "Numbers: [1, 2, 3, 4]"
std::string format_numbers(const std::vector<int>& numbers) {
    // Your implementation here
    // Hint: Use stringstream to build the string
    std::stringstream ss;
    ss << "Numbers: [";

    for (size_t i = 0; i < numbers.size(); ++i) {
        ss << numbers[i];
        if (i < numbers.size() - 1) {
            ss << ", ";
        }
    }

    ss << "]";
    return ss.str();
}

// TODO: Implement this function
// Requirements:
// 1. Demonstrate different static_cast conversions
// 2. Show precision loss examples
// 3. Use const parameters
void demonstrate_casting(const double value) {
    // Your implementation here
    // Show conversions to int, float, char
    // Demonstrate precision differences
    std::cout << "\n=== Casting Demonstrations ===" << std::endl;
    std::cout << "Original double value: " << value << std::endl;

    // 1. Double to int (truncation)
    int int_value = static_cast<int>(value);
    std::cout << "static_cast<int>: " << int_value << " (decimal part lost) " << std::endl;

    // 2. Double to float (precision loss)
    float float_value = static_cast<float>(value);
    std::cout << "static_cast<float>: " << float_value << " (precision may be lost) " << std::endl;

    // 3. Double to char (only if small enough)
    if (value >= 0 && value <= 127) {
        char char_value = static_cast<char>(value);
        std::cout << "static_cast<char>: '" << char_value << "' (ASCII: " << static_cast<int>(char_value) << ")" << std::endl;
    } else {
        std::cout << "Value too large for safe char conversion" << std::endl;
    }

    std::cout << "Precision comparison:" << std::endl;
    std::cout << "  double: " << std::setprecision(15) << value << std::endl;
    std::cout << "  float:  " << std::setprecision(15) << float_value << std::endl;
}

int main() {
    std::cout << "=== Advanced Type Conversion ===" << std::endl;
    
    // Test CSV parsing
    std::string csv = "10,20,30,40,50";
    auto numbers = parse_csv_numbers(csv);
    std::cout << "Parsed: " << format_numbers(numbers) << std::endl;
    
    // Test with invalid data
    std::string invalid_csv = "10,abc,30,xyz,50";
    auto partial_numbers = parse_csv_numbers(invalid_csv);
    std::cout << "Partial parse: " << format_numbers(partial_numbers) << std::endl;
    
    // Test casting demonstrations
    demonstrate_casting(123.456789);
    
    return 0;
}
