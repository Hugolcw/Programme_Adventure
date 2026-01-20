#include <iostream>
#include <string>
#include <climits>
#include <cfloat>
#include <iomanip>

int main() {
    std::cout << "=== C++ 基本数据类型示例 ===" << std::endl;
    
    // 1. 整数类型
    std::cout << "\n--- 整数类型 ---" << std::endl;
    char c = 'A';
    short s = 32767;
    int i = 2147483647;
    long l = 9223372036854775807L;
    long long ll = 9223372036854775807LL;
    
    std::cout << "char: " << c << " (ASCII: " << static_cast<int>(c) << ")" << std::endl;
    std::cout << "short: " << s << " (范围: " << SHRT_MIN << " 到 " << SHRT_MAX << ")" << std::endl;
    std::cout << "int: " << i << " (范围: " << INT_MIN << " 到 " << INT_MAX << ")" << std::endl;
    std::cout << "long: " << l << std::endl;
    std::cout << "long long: " << ll << std::endl;
    
    // 2. 无符号整数类型
    std::cout << "\n--- 无符号整数类型 ---" << std::endl;
    unsigned char uc = 255;
    unsigned short us = 65535;
    unsigned int ui = 4294967295U;
    unsigned long ul = 18446744073709551615UL;
    
    std::cout << "unsigned char: " << static_cast<int>(uc) << std::endl;
    std::cout << "unsigned short: " << us << std::endl;
    std::cout << "unsigned int: " << ui << std::endl;
    std::cout << "unsigned long: " << ul << std::endl;
    
    // 3. 浮点类型
    std::cout << "\n--- 浮点类型 ---" << std::endl;
    float f = 3.14159f;
    double d = 3.141592653589793;
    long double ld = 3.141592653589793238L;
    
    std::cout << std::fixed << std::setprecision(10);
    std::cout << "float: " << f << " (精度约7位)" << std::endl;
    std::cout << "double: " << d << " (精度约15位)" << std::endl;
    std::cout << "long double: " << ld << " (精度约19位)" << std::endl;
    
    // 4. 布尔类型
    std::cout << "\n--- 布尔类型 ---" << std::endl;
    bool flag1 = true;
    bool flag2 = false;
    bool flag3 = 42;  // 非零值为true
    bool flag4 = 0;   // 零值为false
    
    std::cout << std::boolalpha;  // 显示true/false而不是1/0
    std::cout << "flag1 (true): " << flag1 << std::endl;
    std::cout << "flag2 (false): " << flag2 << std::endl;
    std::cout << "flag3 (42): " << flag3 << std::endl;
    std::cout << "flag4 (0): " << flag4 << std::endl;
    
    // 5. 字符串类型
    std::cout << "\n--- 字符串类型 ---" << std::endl;
    const char* c_str = "Hello, C-style string!";
    std::string cpp_str = "Hello, C++ string!";
    std::string empty_str;
    
    std::cout << "C风格字符串: " << c_str << std::endl;
    std::cout << "C++字符串: " << cpp_str << std::endl;
    std::cout << "字符串长度: " << cpp_str.length() << std::endl;
    std::cout << "空字符串是否为空: " << empty_str.empty() << std::endl;
    
    return 0;
}
