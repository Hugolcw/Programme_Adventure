#include <iostream>
#include <functional>
#include <string>

// 普通函数
void free_function(int x) {
    std::cout << "Free function: " << x << std::endl;
}

int add_numbers(int a, int b) {
    return a + b;
}

// 类定义
class MyClass {
public:
    void member_func(int x) {
        std::cout << "Member function: " << x << std::endl;
    }
    
    int multiply(int a, int b) {
        return a * b;
    }
    
    static void static_func(int x) {
        std::cout << "Static function: " << x << std::endl;
    }
    
    int data = 42;
    static int static_data;
};

int MyClass::static_data = 100;

// 函数对象
struct FunctionObject {
    void operator()(int x) const {
        std::cout << "Function object: " << x << std::endl;
    }
};

void demonstrate_basic_invoke() {
    std::cout << "=== std::invoke 基本用法 ===" << std::endl;
    
    MyClass obj;
    
    // 1. 调用普通函数
    std::invoke(free_function, 10);
    
    // 2. 调用成员函数
    std::invoke(&MyClass::member_func, obj, 20);
    
    // 3. 通过指针调用成员函数
    MyClass* ptr = &obj;
    std::invoke(&MyClass::member_func, ptr, 30);
    
    // 4. 调用静态成员函数
    std::invoke(&MyClass::static_func, 40);
    
    // 5. 访问成员变量
    std::cout << "Member data: " << std::invoke(&MyClass::data, obj) << std::endl;
    
    // 6. 访问静态成员变量
    std::cout << "Static data: " << std::invoke(&MyClass::static_data) << std::endl;
}

void demonstrate_callable_objects() {
    std::cout << "\n=== 调用各种可调用对象 ===" << std::endl;
    
    // 1. 调用lambda
    auto lambda = [](int x) { std::cout << "Lambda: " << x << std::endl; };
    std::invoke(lambda, 50);
    
    // 2. 调用函数对象
    FunctionObject func_obj;
    std::invoke(func_obj, 60);
    
    // 3. 调用std::function
    std::function<void(int)> std_func = free_function;
    std::invoke(std_func, 70);
    
    // 4. 调用绑定的函数
    MyClass obj;
    auto bound_func = std::bind(&MyClass::member_func, &obj, std::placeholders::_1);
    std::invoke(bound_func, 80);
}

// 模板函数，演示 std::invoke 在泛型编程中的应用
template<typename Callable, typename... Args>
auto safe_invoke(Callable&& func, Args&&... args) -> decltype(std::invoke(std::forward<Callable>(func), std::forward<Args>(args)...)) {
    std::cout << "[SAFE_INVOKE] 调用函数..." << std::endl;
    return std::invoke(std::forward<Callable>(func), std::forward<Args>(args)...);
}

void demonstrate_generic_programming() {
    std::cout << "\n=== 泛型编程中的 std::invoke ===" << std::endl;
    
    MyClass obj;
    
    // 统一调用接口
    safe_invoke(free_function, 90);
    safe_invoke(&MyClass::member_func, obj, 100);
    safe_invoke([](int x) { std::cout << "Generic lambda: " << x << std::endl; }, 110);
    
    // 返回值处理
    int result1 = safe_invoke(add_numbers, 5, 7);
    std::cout << "add_numbers(5, 7) = " << result1 << std::endl;
    
    int result2 = safe_invoke(&MyClass::multiply, obj, 6, 8);
    std::cout << "obj.multiply(6, 8) = " << result2 << std::endl;
}

// 演示 std::invoke 与成员函数重载
struct Calculator {
    int compute(int a) {
        return a * 2;
    }
    
    int compute(int a, int b) {
        return a + b;
    }
    
    double compute(double a, double b) {
        return a * b;
    }
};

void demonstrate_overload_resolution() {
    std::cout << "\n=== 重载函数的 std::invoke ===" << std::endl;
    
    Calculator calc;
    
    // 需要明确指定重载版本
    int result1 = std::invoke(static_cast<int(Calculator::*)(int)>(&Calculator::compute), calc, 5);
    std::cout << "compute(5) = " << result1 << std::endl;
    
    int result2 = std::invoke(static_cast<int(Calculator::*)(int, int)>(&Calculator::compute), calc, 3, 4);
    std::cout << "compute(3, 4) = " << result2 << std::endl;
    
    double result3 = std::invoke(static_cast<double(Calculator::*)(double, double)>(&Calculator::compute), calc, 2.5, 3.0);
    std::cout << "compute(2.5, 3.0) = " << result3 << std::endl;
}

// 实际应用：事件系统
class EventSystem {
public:
    template<typename Callable, typename... Args>
    void trigger_event(const std::string& event_name, Callable&& callback, Args&&... args) {
        std::cout << "[EVENT] 触发事件: " << event_name << std::endl;
        std::invoke(std::forward<Callable>(callback), std::forward<Args>(args)...);
    }
};

class GamePlayer {
public:
    void on_level_up(int new_level) {
        std::cout << "玩家升级到等级: " << new_level << std::endl;
    }
    
    void on_item_collected(const std::string& item) {
        std::cout << "玩家收集到物品: " << item << std::endl;
    }
};

void demonstrate_event_system() {
    std::cout << "\n=== 事件系统应用示例 ===" << std::endl;
    
    EventSystem event_system;
    GamePlayer player;
    
    // 触发不同类型的事件
    event_system.trigger_event("level_up", &GamePlayer::on_level_up, player, 10);
    event_system.trigger_event("item_collected", &GamePlayer::on_item_collected, player, "Magic Sword");
    
    // 使用lambda作为事件处理器
    event_system.trigger_event("game_over", [](int score) {
        std::cout << "游戏结束，最终得分: " << score << std::endl;
    }, 9999);
}

int main() {
    demonstrate_basic_invoke();
    demonstrate_callable_objects();
    demonstrate_generic_programming();
    demonstrate_overload_resolution();
    demonstrate_event_system();
    
    std::cout << "\n=== std::invoke 总结 ===" << std::endl;
    std::cout << "1. 统一调用接口，支持各种可调用对象" << std::endl;
    std::cout << "2. 完美转发参数，保持效率" << std::endl;
    std::cout << "3. 泛型编程的重要工具" << std::endl;
    std::cout << "4. 处理成员函数指针更简洁" << std::endl;
    std::cout << "5. C++17标准引入" << std::endl;
    
    return 0;
}