#include <iostream>
#include <functional>
using namespace std;

struct Test_bind {
    void t(int n) {
        for (; n; n--) std::cout << "t\n";
    }
    
    void t() {
        std::cout << "重载的t\n";
    }
    
    void print_info(int id, const string& msg) {
        std::cout << "ID: " << id << ", Message: " << msg << std::endl;
    }
};

int main() {
    Test_bind t_b;
    
    // 1. 你的原始例子：绑定所有参数
    auto n1 = std::bind(static_cast<void(Test_bind::*)(int)>(&Test_bind::t), &t_b, 3);
    n1();  // 输出 3 个 "t"
    
    // 2. 绑定无参数版本
    auto n2 = std::bind(static_cast<void(Test_bind::*)()>(&Test_bind::t), &t_b);
    n2();  // 输出 "重载的t"
    
    // 3. 部分参数绑定 - 使用占位符
    auto n3 = std::bind(&Test_bind::print_info, &t_b, 100, std::placeholders::_1);
    n3("Hello");  // 相当于 t_b.print_info(100, "Hello")
    
    // 4. 改变参数顺序
    auto n4 = std::bind(&Test_bind::print_info, &t_b, std::placeholders::_2, std::placeholders::_1);
    n4("World", 200);  // 相当于 t_b.print_info(200, "World")
    
    return 0;
}
