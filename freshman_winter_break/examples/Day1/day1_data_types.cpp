#include <iostream>
#include <string>
#include <climits>
#include <cfloat>
#include <iomanip>

int main() {
    std::cout << "=== C++ Basic Data Types Examples ===" << std::endl;
    
    // 1. Integer types
    std::cout << "\n--- Integer Types ---" << std::endl;
    char c = 'A';
    short s = 32767;
    int i = 2147483647;
    long l = 9223372036854775807L;
    long long ll = 9223372036854775807LL;
    
    std::cout << "char: " << c << " (ASCII: " << static_cast<int>(c) << ")" << std::endl;
    std::cout << "short: " << s << " (range: " << SHRT_MIN << " to " << SHRT_MAX << ")" << std::endl;
    std::cout << "int: " << i << " (range: " << INT_MIN << " to " << INT_MAX << ")" << std::endl;
    std::cout << "long: " << l << std::endl;
    std::cout << "long long: " << ll << std::endl;
    
    // 2. Unsigned integer types
    std::cout << "\n--- Unsigned Integer Types ---" << std::endl;
    unsigned char uc = 255;
    unsigned short us = 65535;
    unsigned int ui = 4294967295U;
    unsigned long ul = 18446744073709551615UL;
    
    std::cout << "unsigned char: " << static_cast<int>(uc) << std::endl;
    std::cout << "unsigned short: " << us << std::endl;
    std::cout << "unsigned int: " << ui << std::endl;
    std::cout << "unsigned long: " << ul << std::endl;
    
    // 3. Floating point types
    std::cout << "\n--- Floating Point Types ---" << std::endl;
    float f = 3.14159f;
    double d = 3.141592653589793;
    long double ld = 3.141592653589793238L;
    
    std::cout << std::fixed << std::setprecision(10);
    std::cout << "float: " << f << " (precision ~7 digits)" << std::endl;
    std::cout << "double: " << d << " (precision ~15 digits)" << std::endl;
    std::cout << "long double: " << ld << " (precision ~19 digits)" << std::endl;
    
    // 4. Boolean type
    std::cout << "\n--- Boolean Type ---" << std::endl;
    bool flag1 = true;
    bool flag2 = false;
    bool flag3 = 42;  // Non-zero value becomes true
    bool flag4 = 0;   // Zero value becomes false
    
    std::cout << std::boolalpha;  // Display true/false instead of 1/0
    std::cout << "flag1 (true): " << flag1 << std::endl;
    std::cout << "flag2 (false): " << flag2 << std::endl;
    std::cout << "flag3 (42): " << flag3 << std::endl;
    std::cout << "flag4 (0): " << flag4 << std::endl;
    
    // 5. String types
    std::cout << "\n--- String Types ---" << std::endl;
    const char* c_str = "Hello, C-style string!";
    std::string cpp_str = "Hello, C++ string!";
    std::string empty_str;
    
    std::cout << "C-style string: " << c_str << std::endl;
    std::cout << "C++ string: " << cpp_str << std::endl;
    std::cout << "String length: " << cpp_str.length() << std::endl;
    std::cout << "Is empty string empty: " << empty_str.empty() << std::endl;
    
    return 0;
}
