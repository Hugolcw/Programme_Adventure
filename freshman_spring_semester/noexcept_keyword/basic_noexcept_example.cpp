#include <iostream>
#include <stdexcept>
#include <vector>

// 基础 noexcept 示例：
//  - noexcept 说明符的基本用法
//  - noexcept 运算符的使用
//  - 函数的异常声明

// 1. 基本的 noexcept 函数声明
void safe_function() noexcept
{
    std::cout << "This function is noexcept\n";
}

// 2. 可能抛出异常的函数（默认）
void may_throw_function()
{
    std::cout << "This function may throw exceptions\n";
    // 可以在这里抛出异常
}

// 3. 有条件的 noexcept
void conditional_function(int x) noexcept
{
    if (x <= 0)
    {
        throw std::invalid_argument("x must be positive");
    }
    std::cout << "x is positive: " << x << "\n";
}

// 4. 使用 noexcept 运算符检查表达式
void check_expression_noexcept()
{
    std::cout << "noexcept(safe_function()) = " << std::boolalpha
              << noexcept(safe_function()) << "\n";
    std::cout << "noexcept(may_throw_function()) = " << std::boolalpha
              << noexcept(may_throw_function()) << "\n";
}

// 5. 析构函数默认是 noexcept
class MyClass
{
public:
    ~MyClass()
    {
        std::cout << "Destructor called (implicitly noexcept)\n";
    }
};

// 6. 移动操作通常标记为 noexcept
class VectorWrapper
{
public:
    VectorWrapper() = default;

    VectorWrapper(const VectorWrapper &) = default;

    // 移动构造函数标记为 noexcept
    VectorWrapper(VectorWrapper &&) noexcept = default;

    // 移动赋值运算符标记为 noexcept
    VectorWrapper &operator=(VectorWrapper &&) noexcept = default;

private:
    std::vector<int> data_;
};

// 练习建议：
// 1. 尝试在 safe_function 中添加可能抛出异常的代码，观察编译器警告
// 2. 创建一个模板函数，使用 noexcept 运算符根据类型特性决定是否为 noexcept
// 3. 实现一个 swap 函数，使用 noexcept 说明符
// 4. 测试条件 noexcept 的不同情况

int main()
{
    std::cout << "=== Basic noexcept Examples ===\n\n";

    // 测试基本的 noexcept 函数
    std::cout << "1. Testing noexcept function:\n";
    safe_function();

    // 测试可能抛出异常的函数
    std::cout << "\n2. Testing may-throw function:\n";
    may_throw_function();

    // 测试条件 noexcept
    std::cout << "\n3. Testing conditional noexcept:\n";
    try
    {
        conditional_function(5);
        conditional_function(-1);
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << "\n";
    }

    // 测试 noexcept 运算符
    std::cout << "\n4. Testing noexcept operator:\n";
    check_expression_noexcept();

    // 测试析构函数
    std::cout << "\n5. Testing destructor (implicitly noexcept):\n";
    {
        MyClass obj;
    }

    // 测试移动操作
    std::cout << "\n6. Testing move operations:\n";
    VectorWrapper v1, v2;
    VectorWrapper v3 = std::move(v1);
    v2 = std::move(v3);

    return 0;
}