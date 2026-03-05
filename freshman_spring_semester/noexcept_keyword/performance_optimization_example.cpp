#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

// noexcept 性能优化示例：
//  - noexcept 对容器性能的影响
//  - 移动操作与 noexcept 的关系
//  - 性能对比测试

// 1. 不使用 noexcept 的类型
class NoexceptFalse {
public:
    NoexceptFalse() = default;
    NoexceptFalse(const NoexceptFalse&) = default;
    NoexceptFalse(NoexceptFalse&&) {}  // 没有 noexcept
    NoexceptFalse& operator=(const NoexceptFalse&) = default;
    NoexceptFalse& operator=(NoexceptFalse&&) {}  // 没有 noexcept
    
private:
    int data_ = 0;
};

// 2. 使用 noexcept 的类型
class NoexceptTrue {
public:
    NoexceptTrue() = default;
    NoexceptTrue(const NoexceptTrue&) = default;
    NoexceptTrue(NoexceptTrue&&) noexcept = default;
    NoexceptTrue& operator=(const NoexceptTrue&) = default;
    NoexceptTrue& operator=(NoexceptTrue&&) noexcept = default;
    
private:
    int data_ = 0;
};

// 3. 性能测试函数
template <typename T>
void test_vector_performance(const std::string& type_name) {
    const int size = 1000000;
    std::vector<T> vec;
    vec.reserve(size);
    
    // 填充向量
    for (int i = 0; i < size; ++i) {
        vec.push_back(T{});
    }
    
    // 测试重新分配时的性能
    auto start = std::chrono::high_resolution_clock::now();
    vec.push_back(T{});  // 触发重新分配
    auto end = std::chrono::high_resolution_clock::now();
    
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    std::cout << type_name << " - Reallocation time: " << duration.count() << " microseconds\n";
    std::cout << type_name << " - is_nothrow_move_constructible: " 
              << std::is_nothrow_move_constructible_v<T> << "\n";
}

// 4. 测试 sort 算法的性能
template <typename T>
void test_sort_performance(const std::string& type_name) {
    const int size = 100000;
    std::vector<T> vec(size);
    
    // 填充随机数据
    for (int i = 0; i < size; ++i) {
        vec[i] = T{};
    }
    
    // 测试排序性能
    auto start = std::chrono::high_resolution_clock::now();
    std::sort(vec.begin(), vec.end());
    auto end = std::chrono::high_resolution_clock::now();
    
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    std::cout << type_name << " - Sort time: " << duration.count() << " microseconds\n";
}

// 5. 自定义可比较类型
class ComparableNoexceptFalse {
public:
    ComparableNoexceptFalse(int value = 0) : value_(value) {}
    ComparableNoexceptFalse(const ComparableNoexceptFalse&) = default;
    ComparableNoexceptFalse(ComparableNoexceptFalse&&) {}  // 没有 noexcept
    
    bool operator<(const ComparableNoexceptFalse& other) const {
        return value_ < other.value_;
    }
    
private:
    int value_;
};

class ComparableNoexceptTrue {
public:
    ComparableNoexceptTrue(int value = 0) : value_(value) {}
    ComparableNoexceptTrue(const ComparableNoexceptTrue&) = default;
    ComparableNoexceptTrue(ComparableNoexceptTrue&&) noexcept = default;
    
    bool operator<(const ComparableNoexceptTrue& other) const {
        return value_ < other.value_;
    }
    
private:
    int value_;
};

// 6. 测试移动语义的使用
template <typename T>
void test_move_semantics_usage(const std::string& type_name) {
    T obj1, obj2;
    T obj3 = std::move(obj1);
    obj2 = std::move(obj3);
    
    std::cout << type_name << " - Move operations completed\n";
}

// 练习建议：
// 1. 运行程序，观察两种类型的性能差异
// 2. 尝试修改容器大小，观察性能差异的变化
// 3. 创建一个包含动态内存的自定义类型，测试性能差异
// 4. 使用性能分析工具（如 perf、VTune）深入分析性能瓶颈
// 5. 思考：在什么情况下 noexcept 的性能影响最明显？

int main() {
    std::cout << "=== noexcept Performance Optimization Examples ===\n\n";
    
    std::cout << "1. Testing vector reallocation performance:\n";
    test_vector_performance<NoexceptFalse>("NoexceptFalse");
    test_vector_performance<NoexceptTrue>("NoexceptTrue");
    
    std::cout << "\n2. Testing sort algorithm performance:\n";
    test_sort_performance<ComparableNoexceptFalse>("ComparableNoexceptFalse");
    test_sort_performance<ComparableNoexceptTrue>("ComparableNoexceptTrue");
    
    std::cout << "\n3. Testing move semantics usage:\n";
    test_move_semantics_usage<NoexceptFalse>("NoexceptFalse");
    test_move_semantics_usage<NoexceptTrue>("NoexceptTrue");
    
    // 4. 解释性能差异的原因
    std::cout << "\n4. Performance difference explanation:\n";
    std::cout << "- When move operations are noexcept, containers can use them\n";
    std::cout << "  during reallocation instead of copy operations.\n";
    std::cout << "- This significantly improves performance for types with\n";
    std::cout << "  expensive copy operations (e.g., types with dynamic memory).\n";
    std::cout << "- Algorithms like std::sort can also use noexcept move operations\n";
    std::cout << "  for better performance.\n";
    
    // TODO: 在这里添加你自己的性能测试
    // 例如：测试不同大小的容器、不同类型的对象等
    
    return 0;
}