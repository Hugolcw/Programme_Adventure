#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::cout << "=== C++ 类型转换示例 ===" << std::endl;
    
    // 1. 隐式类型转换（自动转换）
    std::cout << "\n--- 隐式类型转换 ---" << std::endl;
    int i = 42;
    double d = i;        // int -> double (安全转换)
    float f = 3.14159;
    int truncated = f;   // float -> int (可能丢失精度)
    
    std::cout << "int i = " << i << std::endl;
    std::cout << "double d = i: " << d << std::endl;
    std::cout << "float f = " << f << std::endl;
    std::cout << "int truncated = f: " << truncated << " (小数部分被截断)" << std::endl;
    
    // 2. 显式类型转换（C++风格）
    std::cout << "\n--- 显式类型转换 (C++风格) ---" << std::endl;
    double pi = 3.14159;
    
    // static_cast: 编译时类型转换
    int pi_int = static_cast<int>(pi);
    std::cout << "static_cast<int>(" << pi << ") = " << pi_int << std::endl;
    
    // 字符与数字转换
    char digit = '5';
    int digit_value = digit - '0';  // 字符转数字的技巧
    std::cout << "字符 '" << digit << "' 转为数字: " << digit_value << std::endl;
    
    int number = 7;
    char number_char = '0' + number;  // 数字转字符的技巧
    std::cout << "数字 " << number << " 转为字符: '" << number_char << "'" << std::endl;
    
    // 3. 字符串与数字互转
    std::cout << "\n--- 字符串与数字互转 ---" << std::endl;
    
    // 数字转字符串
    int num = 12345;
    std::string num_str = std::to_string(num);
    std::cout << "数字 " << num << " 转为字符串: \"" << num_str << "\"" << std::endl;
    
    double decimal = 98.765;
    std::string decimal_str = std::to_string(decimal);
    std::cout << "小数 " << decimal << " 转为字符串: \"" << decimal_str << "\"" << std::endl;
    
    // 字符串转数字
    std::string str_num = "54321";
    int converted_int = std::stoi(str_num);
    std::cout << "字符串 \"" << str_num << "\" 转为数字: " << converted_int << std::endl;
    
    std::string str_double = "123.456";
    double converted_double = std::stod(str_double);
    std::cout << "字符串 \"" << str_double << "\" 转为小数: " << converted_double << std::endl;
    
    // 4. 使用stringstream进行转换
    std::cout << "\n--- 使用stringstream转换 ---" << std::endl;
    std::stringstream ss;
    
    // 多个值转为字符串
    ss << "年龄: " << 25 << ", 身高: " << 175.5 << "cm";
    std::string info = ss.str();
    std::cout << "组合字符串: " << info << std::endl;
    
    // 清空stringstream并重新使用
    ss.str("");  // 清空内容
    ss.clear();  // 清空状态标志
    
    ss << 42 << " " << 3.14 << " " << "hello";
    int a;
    double b;
    std::string c;
    ss >> a >> b >> c;
    std::cout << "从stringstream读取: a=" << a << ", b=" << b << ", c=" << c << std::endl;
    
    // 5. 类型转换的注意事项
    std::cout << "\n--- 类型转换注意事项 ---" << std::endl;
    
    // 溢出问题
    int big_num = 300;
    char overflow_char = static_cast<char>(big_num);
    std::cout << "300 转为 char: " << static_cast<int>(overflow_char) << " (发生溢出)" << std::endl;
    
    // 精度丢失
    double precise = 123.456789;
    float less_precise = static_cast<float>(precise);
    std::cout << "double: " << precise << std::endl;
    std::cout << "转为float: " << less_precise << " (精度可能丢失)" << std::endl;
    
    // 异常处理示例
    try {
        std::string invalid = "abc123";
        int result = std::stoi(invalid);  // 这会抛出异常
        std::cout << "转换结果: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cout << "转换失败: " << e.what() << std::endl;
    }
    
    return 0;
}
