#include <iostream>
#include <memory>

struct Target {
    void method1() { std::cout << "Target::method1()" << std::endl; }
    void method2(int n) { std::cout << "Target::method2(" << n << ")" << std::endl; }
    int data = 999;
};

// 自定义智能指针类，演示 ->* 运算符重载
template<typename T>
class MySmartPtr {
private:
    T* ptr;

public:
    MySmartPtr(T* p) : ptr(p) {}
    
    ~MySmartPtr() {
        // 注意：这里不删除指针，因为我们可能传入栈对象的地址
        // 在实际的智能指针中，需要管理内存
    }
    
    // 重载 -> 运算符
    T* operator->() {
        std::cout << "[MySmartPtr] 通过 -> 访问成员" << std::endl;
        return ptr;
    }
    
    // 重载 ->* 运算符
    template<typename MemberPtr>
    auto operator->*(MemberPtr mp) -> decltype((ptr->*mp)) {
        std::cout << "[MySmartPtr] 通过 ->* 访问成员指针" << std::endl;
        return ptr->*mp;
    }
    
    // 重载 * 运算符（解引用）
    T& operator*() {
        return *ptr;
    }
};

// 代理类，添加日志功能
class LoggingProxy {
private:
    Target* target;

public:
    LoggingProxy(Target* t) : target(t) {}
    
    // 重载 -> 运算符
    Target* operator->() {
        std::cout << "[LOG] 通过 -> 访问成员" << std::endl;
        return target;
    }
    
    // 重载 ->* 运算符
    template<typename MemberPtr>
    auto operator->*(MemberPtr mp) -> decltype((target->*mp)) {
        std::cout << "[LOG] 通过 ->* 访问成员指针" << std::endl;
        return target->*mp;
    }
};

void demonstrate_builtin_operators() {
    std::cout << "=== 内置 .* 和 ->* 运算符 ===" << std::endl;
    
    Target obj;
    Target* ptr = &obj;
    
    void (Target::*func_ptr1)() = &Target::method1;
    void (Target::*func_ptr2)(int) = &Target::method2;
    int Target::*member_ptr = &Target::data;
    
    // 使用 .* 运算符（对象 + 成员指针）
    std::cout << "使用 .* 运算符:" << std::endl;
    (obj.*func_ptr1)();
    (obj.*func_ptr2)(42);
    std::cout << "obj.*member_ptr = " << (obj.*member_ptr) << std::endl;
    
    // 使用 ->* 运算符（指针 + 成员指针）
    std::cout << "\n使用 ->* 运算符:" << std::endl;
    (ptr->*func_ptr1)();
    (ptr->*func_ptr2)(100);
    std::cout << "ptr->*member_ptr = " << (ptr->*member_ptr) << std::endl;
}

void demonstrate_custom_smart_ptr() {
    std::cout << "\n=== 自定义智能指针的 ->* 重载 ===" << std::endl;
    
    Target obj;
    MySmartPtr<Target> smart_ptr(&obj);
    
    void (Target::*func_ptr1)() = &Target::method1;
    void (Target::*func_ptr2)(int) = &Target::method2;
    int Target::*member_ptr = &Target::data;
    
    // 使用重载的 -> 运算符
    smart_ptr->method1();
    
    // 使用重载的 ->* 运算符
    (smart_ptr->*func_ptr1)();
    (smart_ptr->*func_ptr2)(200);
    std::cout << "smart_ptr->*member_ptr = " << (smart_ptr->*member_ptr) << std::endl;
}

void demonstrate_logging_proxy() {
    std::cout << "\n=== 日志代理的 ->* 重载 ===" << std::endl;
    
    Target obj;
    LoggingProxy proxy(&obj);
    
    void (Target::*func_ptr1)() = &Target::method1;
    void (Target::*func_ptr2)(int) = &Target::method2;
    int Target::*member_ptr = &Target::data;
    
    // 通过代理访问成员
    proxy->method1();  // 使用 ->
    
    // 通过代理使用成员指针
    (proxy->*func_ptr1)();     // 使用 ->*
    (proxy->*func_ptr2)(300);  // 使用 ->*
    std::cout << "proxy->*member_ptr = " << (proxy->*member_ptr) << std::endl;
}

void demonstrate_std_shared_ptr() {
    std::cout << "\n=== std::shared_ptr 的 ->* 支持 ===" << std::endl;
    
    auto smart_ptr = std::make_shared<Target>();
    
    void (Target::*func_ptr)() = &Target::method1;
    int Target::*member_ptr = &Target::data;
    
    // std::shared_ptr 重载了 ->* 运算符
    (smart_ptr->*func_ptr)();
    std::cout << "shared_ptr->*member_ptr = " << (smart_ptr->*member_ptr) << std::endl;
}

int main() {
    demonstrate_builtin_operators();
    demonstrate_custom_smart_ptr();
    demonstrate_logging_proxy();
    demonstrate_std_shared_ptr();
    
    std::cout << "\n=== 总结 ===" << std::endl;
    std::cout << "operator.* 不可重载 - 语言核心机制，编译时确定" << std::endl;
    std::cout << "operator->* 可以重载 - 支持智能指针和代理对象" << std::endl;
    
    return 0;
}