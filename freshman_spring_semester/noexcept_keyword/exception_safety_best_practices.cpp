#include <iostream>
#include <memory>
#include <vector>
#include <stdexcept>
#include <algorithm>

// 异常安全和 noexcept 最佳实践示例：
//  - 异常安全级别
//  - noexcept 在异常安全中的作用
//  - 最佳实践和常见陷阱

// 1. 基本异常安全保证
class BasicExceptionSafe {
public:
    BasicExceptionSafe(int size) : data_(size) {}
    
    void set_value(int index, int value) {
        if (index < 0 || index >= static_cast<int>(data_.size())) {
            throw std::out_of_range("Index out of range");
        }
        data_[index] = value;
    }
    
    // 基本异常安全：如果抛出异常，对象保持有效状态
    int get_value(int index) const {
        if (index < 0 || index >= static_cast<int>(data_.size())) {
            throw std::out_of_range("Index out of range");
        }
        return data_[index];
    }
    
private:
    std::vector<int> data_;
};

// 2. 强异常安全保证
class StrongExceptionSafe {
public:
    StrongExceptionSafe() = default;
    
    void add_item(int item) {
        std::vector<int> new_data = data_;  // 先创建副本
        new_data.push_back(item);           // 可能抛出异常
        data_ = std::move(new_data);        // noexcept 移动
    }
    
    // 强异常安全：如果抛出异常，对象状态不变
    // 使用 copy-and-swap 惯用语实现
    void replace_all(int old_value, int new_value) {
        std::vector<int> new_data = data_;
        std::replace(new_data.begin(), new_data.end(), old_value, new_value);
        data_ = std::move(new_data);
    }
    
    const std::vector<int>& get_data() const noexcept {
        return data_;
    }
    
private:
    std::vector<int> data_;
};

// 3. noexcept 函数的最佳实践
namespace Good {
    // 析构函数：应该是 noexcept
    class GoodClass {
    public:
        ~GoodClass() noexcept {
            cleanup();
        }
        
    private:
        void cleanup() noexcept {
            // 清理资源，不抛出异常
        }
    };
    
    // swap 函数：应该是 noexcept
    template <typename T>
    void swap(T& a, T& b) noexcept(noexcept(std::swap(a, b))) {
        std::swap(a, b);
    }
    
    // 移动操作：应该是 noexcept
    class MovableClass {
    public:
        MovableClass() = default;
        MovableClass(const MovableClass&) = default;
        MovableClass(MovableClass&&) noexcept = default;
        MovableClass& operator=(const MovableClass&) = default;
        MovableClass& operator=(MovableClass&&) noexcept = default;
    };
    
    // 简单的访问器：可以是 noexcept
    class AccessorClass {
    public:
        int get_value() const noexcept {
            return value_;
        }
        
    private:
        int value_ = 0;
    };
}

// 4. 常见陷阱
namespace Bad {
    // 陷阱1：析构函数抛出异常
    class BadDestructor {
    public:
        ~BadDestructor() {
            throw std::runtime_error("Destructor threw exception");
        }
    };
    
    // 陷阱2：noexcept 函数中调用可能抛出异常的函数
    void bad_noexcept_function() noexcept {
        throw std::runtime_error("This should not happen");
    }
    
    // 陷阱3：忘记标记移动操作为 noexcept
    class BadMovable {
    public:
        BadMovable() = default;
        BadMovable(const BadMovable&) = default;
        BadMovable(BadMovable&&) {}  // 缺少 noexcept
        BadMovable& operator=(const BadMovable&) = default;
        BadMovable& operator=(BadMovable&&) {}  // 缺少 noexcept
    };
}

// 5. 条件 noexcept 的正确使用
template <typename T>
void conditional_noexcept_swap(T& a, T& b) noexcept(noexcept(std::swap(a, b))) {
    std::swap(a, b);
}

// 6. RAII 和 noexcept 的结合
class RAIIResource {
public:
    explicit RAIIResource(int* ptr) : ptr_(ptr) {}
    
    ~RAIIResource() noexcept {
        delete ptr_;  // 不会抛出异常
    }
    
    // 禁止复制，允许移动
    RAIIResource(const RAIIResource&) = delete;
    RAIIResource& operator=(const RAIIResource&) = delete;
    
    RAIIResource(RAIIResource&& other) noexcept : ptr_(other.ptr_) {
        other.ptr_ = nullptr;
    }
    
    RAIIResource& operator=(RAIIResource&& other) noexcept {
        if (this != &other) {
            delete ptr_;
            ptr_ = other.ptr_;
            other.ptr_ = nullptr;
        }
        return *this;
    }
    
private:
    int* ptr_;
};

// 练习任务（建议按步骤完成）：
// 1. 阅读上面的代码，理解异常安全的三个级别
// 2. 运行程序，观察不同异常安全级别的行为
// 3. 实现一个具有强异常安全保证的类
// 4. 识别并修复 Bad 命名空间中的问题
// 5. 思考：在什么情况下应该使用 noexcept，什么时候不应该使用？

int main() {
    std::cout << "=== Exception Safety and noexcept Best Practices ===\n\n";
    
    // 测试基本异常安全
    std::cout << "1. Testing basic exception safety:\n";
    BasicExceptionSafe basic(10);
    try {
        basic.set_value(5, 42);
        std::cout << "Value at index 5: " << basic.get_value(5) << "\n";
        basic.set_value(15, 100);  // 会抛出异常
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << "\n";
    }
    
    // 测试强异常安全
    std::cout << "\n2. Testing strong exception safety:\n";
    StrongExceptionSafe strong;
    strong.add_item(1);
    strong.add_item(2);
    strong.add_item(3);
    
    std::cout << "Before replace: ";
    for (int val : strong.get_data()) {
        std::cout << val << " ";
    }
    std::cout << "\n";
    
    strong.replace_all(2, 99);
    
    std::cout << "After replace: ";
    for (int val : strong.get_data()) {
        std::cout << val << " ";
    }
    std::cout << "\n";
    
    // 测试条件 noexcept
    std::cout << "\n3. Testing conditional noexcept:\n";
    int x = 10, y = 20;
    std::cout << "swap is noexcept: " << noexcept(conditional_noexcept_swap(x, y)) << "\n";
    conditional_noexcept_swap(x, y);
    std::cout << "After swap: x = " << x << ", y = " << y << "\n";
    
    // 测试 RAII 和 noexcept
    std::cout << "\n4. Testing RAII with noexcept:\n";
    {
        RAIIResource resource(new int(42));
        RAIIResource resource2 = std::move(resource);
        std::cout << "Resource moved successfully\n";
    }
    std::cout << "Resources cleaned up\n";
    
    // 最佳实践总结
    std::cout << "\n5. Best practices summary:\n";
    std::cout << "- Destructors should always be noexcept\n";
    std::cout << "- Move operations should be noexcept when possible\n";
    std::cout << "- swap functions should be noexcept\n";
    std::cout << "- Use conditional noexcept in templates\n";
    std::cout << "- Ensure noexcept functions don't throw exceptions\n";
    std::cout << "- Use RAII for resource management\n";
    std::cout << "- Aim for strong exception safety guarantee\n";
    
    // TODO: 在这里添加你自己的测试代码
    // 例如：测试 Bad 命名空间中的陷阱（小心！）
    
    return 0;
}