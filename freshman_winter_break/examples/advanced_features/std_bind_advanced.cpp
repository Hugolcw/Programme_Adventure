#include <iostream>
#include <functional>
#include <string>

struct Test_bind {
    void t(int n) {
        for (; n; n--) std::cout << "t\n";
    }
    
    void t() {
        std::cout << "重载的t\n";
    }
    
    void print_info(int id, const std::string& msg) {
        std::cout << "ID: " << id << ", Message: " << msg << std::endl;
    }
    
    int calculate(int a, int b, int c) {
        return a + b * c;
    }
};

// 普通函数示例
void free_function(int x, const std::string& str) {
    std::cout << "Free function: " << x << " - " << str << std::endl;
}

int multiply(int a, int b) {
    return a * b;
}

void demonstrate_basic_bind() {
    std::cout << "=== 基本 std::bind 用法 ===" << std::endl;
    
    Test_bind t_b;
    
    // 1. 绑定所有参数的成员函数
    auto n1 = std::bind(static_cast<void(Test_bind::*)(int)>(&Test_bind::t), &t_b, 3);
    std::cout << "绑定所有参数: ";
    n1();  // 输出 3 个 "t"
    
    // 2. 绑定无参数版本
    auto n2 = std::bind(static_cast<void(Test_bind::*)()>(&Test_bind::t), &t_b);
    std::cout << "绑定无参数版本: ";
    n2();  // 输出 "重载的t"
}

void demonstrate_placeholders() {
    std::cout << "\n=== 占位符 (Placeholders) 用法 ===" << std::endl;
    
    Test_bind t_b;
    
    // 1. 部分参数绑定 - 使用占位符
    auto n3 = std::bind(&Test_bind::print_info, &t_b, 100, std::placeholders::_1);
    n3("Hello");  // 相当于 t_b.print_info(100, "Hello")
    
    // 2. 改变参数顺序
    auto n4 = std::bind(&Test_bind::print_info, &t_b, std::placeholders::_2, std::placeholders::_1);
    n4("World", 200);  // 相当于 t_b.print_info(200, "World")
    
    // 3. 复杂的参数绑定
    auto n5 = std::bind(&Test_bind::calculate, &t_b, std::placeholders::_1, 10, std::placeholders::_2);
    std::cout << "calculate(5, 10, 3) = " << n5(5, 3) << std::endl;  // 相当于 calculate(5, 10, 3)
}

void demonstrate_free_function_bind() {
    std::cout << "\n=== 普通函数的 std::bind ===" << std::endl;
    
    // 1. 绑定普通函数的部分参数
    auto bound_free = std::bind(free_function, std::placeholders::_1, "Fixed String");
    bound_free(42);  // 相当于 free_function(42, "Fixed String")
    
    // 2. 绑定所有参数
    auto bound_multiply = std::bind(multiply, 6, 7);
    std::cout << "multiply(6, 7) = " << bound_multiply() << std::endl;
    
    // 3. 参数顺序重排
    auto reorder_multiply = std::bind(multiply, std::placeholders::_2, std::placeholders::_1);
    std::cout << "reorder multiply(3, 4) = " << reorder_multiply(3, 4) << std::endl;  // 实际调用 multiply(4, 3)
}

void demonstrate_lambda_vs_bind() {
    std::cout << "\n=== Lambda vs std::bind 对比 ===" << std::endl;
    
    Test_bind t_b;
    
    // 使用 std::bind
    auto bind_version = std::bind(&Test_bind::print_info, &t_b, std::placeholders::_1, "from bind");
    
    // 使用 lambda（通常更清晰）
    auto lambda_version = [&t_b](int id) {
        t_b.print_info(id, "from lambda");
    };
    
    std::cout << "std::bind 版本: ";
    bind_version(999);
    
    std::cout << "lambda 版本: ";
    lambda_version(888);
}

// 回调函数示例
void register_callback(std::function<void()> callback) {
    std::cout << "执行回调: ";
    callback();
}

void register_callback_with_param(std::function<void(int)> callback) {
    std::cout << "执行带参数的回调: ";
    callback(777);
}

void demonstrate_callback_usage() {
    std::cout << "\n=== 回调函数应用 ===" << std::endl;
    
    Test_bind t_b;
    
    // 1. 将成员函数绑定为无参回调
    register_callback(std::bind(static_cast<void(Test_bind::*)()>(&Test_bind::t), &t_b));
    
    // 2. 将带参数的成员函数绑定为无参回调
    register_callback(std::bind(static_cast<void(Test_bind::*)(int)>(&Test_bind::t), &t_b, 2));
    
    // 3. 将成员函数绑定为带参回调
    register_callback_with_param(std::bind(&Test_bind::print_info, &t_b, std::placeholders::_1, "callback"));
}

int main() {
    demonstrate_basic_bind();
    demonstrate_placeholders();
    demonstrate_free_function_bind();
    demonstrate_lambda_vs_bind();
    demonstrate_callback_usage();
    
    std::cout << "\n=== std::bind 总结 ===" << std::endl;
    std::cout << "1. std::bind 创建可调用对象，预设参数" << std::endl;
    std::cout << "2. 使用占位符控制参数传递" << std::endl;
    std::cout << "3. 处理函数重载需要 static_cast" << std::endl;
    std::cout << "4. 常用于回调函数和事件处理" << std::endl;
    std::cout << "5. 现代C++中，lambda通常更清晰" << std::endl;
    
    return 0;
}