#include <iostream>
#include <stdexcept>

// 1. 基本使用：声明函数不会抛出异常
void safe_function() noexcept
{
    std::cout << "This function is noexcept" << std::endl;
    // 如果这里有可能抛出异常的代码，编译器会警告
}

// 2. 有条件的 noexcept
void conditional_noexcept(int x) noexcept(true)
{
    if (x < 0)
    {
        // 当 x < 0 时，noexcept 条件为 false，函数可能抛出异常
        throw std::invalid_argument("x must be non-negative");
    }
    std::cout << "x is non-negative: " << x << std::endl;
}

// 3. 移动构造函数和移动赋值运算符通常标记为 noexcept
// 这样容器在重新分配内存时可以使用移动操作而不是复制操作
class MyClass
{
public:
    MyClass()
    {
        std::cout << "Default constructor" << std::endl;
    }

    MyClass(const MyClass &)
    {
        std::cout << "Copy constructor" << std::endl;
    }

    // 移动构造函数标记为 noexcept
    MyClass(MyClass &&) noexcept
    {
        std::cout << "Move constructor (noexcept)" << std::endl;
    }

    // 移动赋值运算符标记为 noexcept
    MyClass &operator=(MyClass &&) noexcept
    {
        std::cout << "Move assignment (noexcept)" << std::endl;
        return *this;
    }
};

// 4. 析构函数默认是 noexcept
// 从 C++11 开始，析构函数默认是 noexcept(true)
class AnotherClass
{
public:
    ~AnotherClass()
    {
        // 析构函数不应该抛出异常
        std::cout << "Destructor (implicitly noexcept)" << std::endl;
    }
};

// 5. 使用 noexcept 操作符检查表达式是否会抛出异常
template <typename T>
void check_noexcept(T &&t)
{
    if (noexcept(t()))
    {
        std::cout << "Expression is noexcept" << std::endl;
    }
    else
    {
        std::cout << "Expression may throw exceptions" << std::endl;
    }
}

// 可能抛出异常的函数
void may_throw()
{
    throw std::runtime_error("Error");
}

// 不会抛出异常的函数
void no_throw() noexcept
{
    // 安全操作
}

int main()
{
    std::cout << "=== Testing noexcept keyword ===" << std::endl;

    // 测试基本的 noexcept 函数
    safe_function();

    std::cout << "\n=== Testing conditional noexcept ===" << std::endl;
    try
    {
        conditional_noexcept(42); // 不会抛出异常
        conditional_noexcept(-1); // 会抛出异常
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Testing move operations ===" << std::endl;
    MyClass a;
    MyClass b = std::move(a); // 使用移动构造函数
    MyClass c;
    c = std::move(b); // 使用移动赋值运算符

    std::cout << "\n=== Testing noexcept operator ===" << std::endl;
    check_noexcept(no_throw);  // 检查 no_throw 函数
    check_noexcept(may_throw); // 检查 may_throw 函数

    std::cout << "\n=== Testing destructor ===" << std::endl;
    AnotherClass d;

    return 0;
}