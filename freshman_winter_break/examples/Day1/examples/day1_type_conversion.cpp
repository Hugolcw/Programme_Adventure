#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::cout << "=== C++ Type Conversion Examples ===" << std::endl;
    
    // 1. Implicit type conversion (automatic conversion)
    std::cout << "\n--- Implicit Type Conversion ---" << std::endl;
    int i = 42;
    double d = i;        // int -> double (safe conversion)
    float f = 3.14159;
    int truncated = f;   // float -> int (may lose precision)
    
    std::cout << "int i = " << i << std::endl;
    std::cout << "double d = i: " << d << std::endl;
    std::cout << "float f = " << f << std::endl;
    std::cout << "int truncated = f: " << truncated << " (decimal part truncated)" << std::endl;
    
    // 2. Explicit type conversion (C++ style)
    std::cout << "\n--- Explicit Type Conversion (C++ Style) ---" << std::endl;
    double pi = 3.14159;
    
    // static_cast: compile-time type conversion
    int pi_int = static_cast<int>(pi);
    std::cout << "static_cast<int>(" << pi << ") = " << pi_int << std::endl;
    
    // Character and number conversion
    char digit = '5';
    int digit_value = digit - '0';  // Character to number trick
    std::cout << "Character '" << digit << "' to number: " << digit_value << std::endl;
    
    int number = 7;
    char number_char = '0' + number;  // Number to character trick
    std::cout << "Number " << number << " to character: '" << number_char << "'" << std::endl;
    
    // 3. String and number conversion
    std::cout << "\n--- String and Number Conversion ---" << std::endl;
    
    // Number to string
    int num = 12345;
    std::string num_str = std::to_string(num);
    std::cout << "Number " << num << " to string: \"" << num_str << "\"" << std::endl;
    
    double decimal = 98.765;
    std::string decimal_str = std::to_string(decimal);
    std::cout << "Decimal " << decimal << " to string: \"" << decimal_str << "\"" << std::endl;
    
    // String to number
    std::string str_num = "54321";
    int converted_int = std::stoi(str_num);
    std::cout << "String \"" << str_num << "\" to number: " << converted_int << std::endl;
    
    std::string str_double = "123.456";
    double converted_double = std::stod(str_double);
    std::cout << "String \"" << str_double << "\" to decimal: " << converted_double << std::endl;
    
    // 4. Using stringstream for conversion
    std::cout << "\n--- Using stringstream for Conversion ---" << std::endl;
    std::stringstream ss;
    
    // Multiple values to string
    ss << "Age: " << 25 << ", Height: " << 175.5 << "cm";
    std::string info = ss.str();
    std::cout << "Combined string: " << info << std::endl;
    
    // Clear stringstream and reuse
    ss.str("");  // Clear content
    ss.clear();  // Clear state flags
    
    ss << 42 << " " << 3.14 << " " << "hello";
    int a;
    double b;
    std::string c;
    ss >> a >> b >> c;
    std::cout << "Read from stringstream: a=" << a << ", b=" << b << ", c=" << c << std::endl;
    
    // 5. Type conversion considerations
    std::cout << "\n--- Type Conversion Considerations ---" << std::endl;
    
    // Overflow issue
    int big_num = 300;
    char overflow_char = static_cast<char>(big_num);
    std::cout << "300 to char: " << static_cast<int>(overflow_char) << " (overflow occurred)" << std::endl;
    
    // Precision loss
    double precise = 123.456789;
    float less_precise = static_cast<float>(precise);
    std::cout << "double: " << precise << std::endl;
    std::cout << "to float: " << less_precise << " (precision may be lost)" << std::endl;
    
    // Exception handling example
    try {
        std::string invalid = "abc123";
        int result = std::stoi(invalid);  // This will throw an exception
        std::cout << "Conversion result: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Conversion failed: " << e.what() << std::endl;
    }
    
    return 0;
}
