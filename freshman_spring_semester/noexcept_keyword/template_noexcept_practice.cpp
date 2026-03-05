#include <iostream>
#include <vector>
#include <string>
#include <type_traits>

// 模板与条件 noexcept 练习：
//  - 在模板中使用 noexcept 运算符
//  - 根据类型特性决定函数是否为 noexcept
//  - 实现条件 noexcept 的 swap 函数

// 1. 基本的 swap 函数，使用条件 noexcept
template <typename T>
void my_swap(T &a, T &b) noexcept(noexcept(std::swap(a, b)))
{
    std::swap(a, b);
}

// 2. 自定义类型，移动操作是 noexcept
class SafeMovable
{
public:
    SafeMovable() = default;
    SafeMovable(const SafeMovable &) = default;
    SafeMovable(SafeMovable &&) noexcept = default;
    SafeMovable &operator=(const SafeMovable &) = default;
    SafeMovable &operator=(SafeMovable &&) noexcept = default;
};

// 3. 自定义类型，移动操作不是 noexcept
class UnsafeMovable
{
public:
    UnsafeMovable() = default;
    UnsafeMovable(const UnsafeMovable &) = default;
    UnsafeMovable(UnsafeMovable &&) {} // 没有 noexcept
    UnsafeMovable &operator=(const UnsafeMovable &) = default;
    UnsafeMovable &operator=(UnsafeMovable &&) {} // 没有 noexcept
};

// 4. 根据类型特性选择不同的实现
template <typename T>
void process_type(T &&t)
{
    if constexpr (noexcept(T(std::forward<T>(t))))
    {
        std::cout << "Type is noexcept movable\n";
    }
    else
    {
        std::cout << "Type is not noexcept movable\n";
    }
}

// 5. 容器操作的条件 noexcept
template <typename T>
class MyContainer
{
public:
    void push_back(const T &value) noexcept(std::is_nothrow_copy_constructible_v<T>)
    {
        data_.push_back(value);
    }

    void push_back(T &&value) noexcept(std::is_nothrow_move_constructible_v<T>)
    {
        data_.push_back(std::move(value));
    }

private:
    std::vector<T> data_;
};

// 6. 使用 type_traits 检查 noexcept 特性
template <typename T>
void check_noexcept_traits()
{
    std::cout << "is_nothrow_copy_constructible: "
              << std::is_nothrow_copy_constructible_v<T> << "\n";
    std::cout << "is_nothrow_move_constructible: "
              << std::is_nothrow_move_constructible_v<T> << "\n";
    std::cout << "is_nothrow_copy_assignable: "
              << std::is_nothrow_copy_assignable_v<T> << "\n";
    std::cout << "is_nothrow_move_assignable: "
              << std::is_nothrow_move_assignable_v<T> << "\n";
}

// 练习任务（建议按步骤完成）：
// 1. 阅读上面的代码，理解条件 noexcept 的语法和用法
// 2. 在 main 中添加更多测试用例，包括基本类型和自定义类型
// 3. 实现一个模板函数，根据类型是否为 noexcept 来选择不同的算法
// 4. 创建一个自定义类型，使其某些操作是 noexcept，某些不是
// 5. 思考：在什么情况下使用条件 noexcept 是必要的？

int main()
{
    std::cout << "=== Template and Conditional noexcept Practice ===\n\n";

    // 测试 swap 函数的条件 noexcept
    std::cout << "1. Testing conditional noexcept swap:\n";
    int a = 10, b = 20;
    std::cout << "Before swap: a = " << a << ", b = " << b << "\n";
    std::cout << "my_swap is noexcept: " << noexcept(my_swap(a, b)) << "\n";
    my_swap(a, b);
    std::cout << "After swap: a = " << a << ", b = " << b << "\n";

    // 测试不同类型的 noexcept 特性
    std::cout << "\n2. Testing different types:\n";
    SafeMovable safe_obj;
    UnsafeMovable unsafe_obj;

    process_type(safe_obj);
    process_type(unsafe_obj);

    // 测试 type_traits
    std::cout << "\n3. Testing noexcept traits:\n";
    std::cout << "For int:\n";
    check_noexcept_traits<int>();

    std::cout << "\nFor SafeMovable:\n";
    check_noexcept_traits<SafeMovable>();

    std::cout << "\nFor UnsafeMovable:\n";
    check_noexcept_traits<UnsafeMovable>();

    // 测试容器操作
    std::cout << "\n4. Testing container operations:\n";
    MyContainer<int> int_container;
    MyContainer<SafeMovable> safe_container;
    MyContainer<UnsafeMovable> unsafe_container;

    std::cout << "push_back(int) is noexcept: "
              << noexcept(int_container.push_back(42)) << "\n";
    std::cout << "push_back(SafeMovable) is noexcept: "
              << noexcept(safe_container.push_back(SafeMovable())) << "\n";
    std::cout << "push_back(UnsafeMovable) is noexcept: "
              << noexcept(unsafe_container.push_back(UnsafeMovable())) << "\n";

    // TODO: 在这里添加你自己的更多测试用例
    // 例如：测试字符串类型、自定义复杂类型等

    return 0;
}