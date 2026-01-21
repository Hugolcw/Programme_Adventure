#include <iostream>

// 1. 基本数据类型转换示例
void basic_type_conversion() {
    std::cout << "=== 基本数据类型转换 ===" << std::endl;
    
    // 数值类型转换
    int i = 10;
    double d = static_cast<double>(i);  // int -> double
    std::cout << "int to double: " << d << std::endl;
    
    // 浮点数转整数（会截断小数部分）
    double pi = 3.14159;
    int int_pi = static_cast<int>(pi);  // double -> int
    std::cout << "double to int: " << int_pi << std::endl;
    
    // 字符和数字转换
    char c = 'A';
    int ascii = static_cast<int>(c);  // char -> int
    std::cout << "char to int: " << ascii << std::endl;
}

// 2. 处理函数重载的示例
struct Test {
    void func() {
        std::cout << "无参数版本" << std::endl;
    }
    
    void func(int n) {
        std::cout << "有参数版本: " << n << std::endl;
    }
};

void function_overload_resolution() {
    std::cout << "\n=== 函数重载解析 ===" << std::endl;
    
    Test t;
    
    // 使用 static_cast 明确指定函数签名
    auto ptr1 = static_cast<void(Test::*)()>(&Test::func);        // 无参版本
    auto ptr2 = static_cast<void(Test::*)(int)>(&Test::func);     // 有参版本
    
    (t.*ptr1)();     // 调用无参数版本
    (t.*ptr2)(42);   // 调用有参数版本
}

// 3. 指针类型转换示例
class Base {
public:
    virtual void show() { std::cout << "Base" << std::endl; }
};

class Derived : public Base {
public:
    void show() override { std::cout << "Derived" << std::endl; }
    void derived_only() { std::cout << "Derived only method" << std::endl; }
};

void pointer_conversion() {
    std::cout << "\n=== 指针类型转换 ===" << std::endl;
    
    // 向上转换（安全）
    Derived d;
    Base* base_ptr = static_cast<Base*>(&d);
    base_ptr->show();  // 输出: Derived
    
    // 向下转换（需要确保安全）
    Base* b = &d;
    Derived* derived_ptr = static_cast<Derived*>(b);
    derived_ptr->derived_only();  // 输出: Derived only method
}

// 4. 枚举类型转换示例
enum Color { RED = 1, GREEN = 2, BLUE = 3 };
enum class Status { ACTIVE = 1, INACTIVE = 2 };

void enum_conversion() {
    std::cout << "\n=== 枚举类型转换 ===" << std::endl;
    
    // 枚举转整数
    Color c = RED;
    int color_value = static_cast<int>(c);
    std::cout << "Color to int: " << color_value << std::endl;
    
    // 整数转枚举
    int num = 2;
    Color c2 = static_cast<Color>(num);
    std::cout << "int to Color: " << c2 << std::endl;
    
    // 强类型枚举转换
    Status s = Status::ACTIVE;
    int status_value = static_cast<int>(s);
    std::cout << "Status to int: " << status_value << std::endl;
}

int main() {
    basic_type_conversion();
    function_overload_resolution();
    pointer_conversion();
    enum_conversion();
    
    return 0;
}