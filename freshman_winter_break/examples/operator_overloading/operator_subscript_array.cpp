#include <iostream>
#include <vector>
#include <stdexcept>

// 自定义数组类，演示下标运算符重载
class MyArray {
private:
    std::vector<int> data;

public:
    MyArray(int size) : data(size, 0) {}
    
    // 重载 [] 运算符（非const版本）
    int& operator[](int index) {
        if (index < 0 || index >= static_cast<int>(data.size())) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }
    
    // 重载 [] 运算符（const版本）
    const int& operator[](int index) const {
        if (index < 0 || index >= static_cast<int>(data.size())) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }
    
    int size() const { return static_cast<int>(data.size()); }
    
    // 重载输出运算符
    friend std::ostream& operator<<(std::ostream& os, const MyArray& arr) {
        os << "[";
        for (int i = 0; i < arr.size(); ++i) {
            os << arr[i];
            if (i < arr.size() - 1) os << ", ";
        }
        os << "]";
        return os;
    }
};

// 演示函数调用运算符重载
class Calculator {
public:
    // 重载 () 运算符 - 加法
    int operator()(int a, int b) const {
        return a + b;
    }
    
    // 重载 () 运算符 - 三个参数的加法
    int operator()(int a, int b, int c) const {
        return a + b + c;
    }
    
    // 重载 () 运算符 - 乘法版本
    double operator()(double a, double b) const {
        return a * b;
    }
};

int main() {
    std::cout << "=== 下标运算符重载示例 ===" << std::endl;
    
    MyArray arr(5);
    
    // 使用重载的 [] 运算符赋值
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 50;
    
    std::cout << "数组内容: " << arr << std::endl;
    
    // 使用 const 版本的 [] 运算符读取
    std::cout << "arr[2] = " << arr[2] << std::endl;
    
    // 演示边界检查
    try {
        arr[10] = 100;  // 这会抛出异常
    } catch (const std::out_of_range& e) {
        std::cout << "捕获异常: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== 函数调用运算符重载示例 ===" << std::endl;
    
    Calculator calc;
    
    // 使用重载的 () 运算符
    std::cout << "calc(5, 3) = " << calc(5, 3) << std::endl;
    std::cout << "calc(1, 2, 3) = " << calc(1, 2, 3) << std::endl;
    std::cout << "calc(2.5, 4.0) = " << calc(2.5, 4.0) << std::endl;
    
    return 0;
}