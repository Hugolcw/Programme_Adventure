# 🔧 运算符重载示例

> 深入理解C++运算符重载机制，掌握自定义类型的运算符设计

## 📁 文件说明

### 🧮 算术运算符重载
- **`overloading_arithmetic_operators.cpp`** - 基础算术运算符重载
  - 加法、减法、乘法、除法运算符
  - 复合赋值运算符 (+=, -=, *=, /=)
  - 前置和后置递增递减运算符

### 📊 比较运算符重载
- **`overloading_comparison_operator.cpp`** - 比较运算符重载
  - 相等性运算符 (==, !=)
  - 关系运算符 (<, >, <=, >=)
  - C++20三路比较运算符 (<=>)

### 📝 输入输出运算符重载
- **`operator_overloading_io.cpp`** - 流运算符重载
  - 输出运算符 (<<) 重载
  - 输入运算符 (>>) 重载
  - 友元函数的使用

### 🔍 下标和函数调用运算符
- **`operator_subscript_array.cpp`** - 特殊运算符重载
  - 下标运算符 ([]) 重载
  - 函数调用运算符 (()) 重载
  - 容器类的实现

### 🎯 智能指针运算符
- **`operator_arrow_star.cpp`** - 指针相关运算符重载
  - 箭头运算符 (->) 重载
  - 解引用运算符 (*) 重载
  - 智能指针的实现原理

## 🎯 学习目标

### 基础概念
- ✅ 理解运算符重载的语法规则
- ✅ 掌握成员函数 vs 友元函数的选择
- ✅ 了解可重载和不可重载的运算符

### 设计原则
- ✅ 保持运算符语义的直观性
- ✅ 遵循对称性原则
- ✅ 考虑效率和异常安全性

### 实际应用
- ✅ 自定义数值类型 (复数、分数、矩阵)
- ✅ 容器类的设计
- ✅ 智能指针的实现

## 🛠️ 编译和运行

```bash
# 编译单个示例
g++ -std=c++17 -Wall -O2 -o build/arithmetic overloading_arithmetic_operators.cpp
g++ -std=c++17 -Wall -O2 -o build/comparison overloading_comparison_operator.cpp
g++ -std=c++17 -Wall -O2 -o build/io operator_overloading_io.cpp
g++ -std=c++17 -Wall -O2 -o build/subscript operator_subscript_array.cpp
g++ -std=c++17 -Wall -O2 -o build/arrow operator_arrow_star.cpp

# 运行示例
./build/arithmetic
./build/comparison
./build/io
./build/subscript
./build/arrow
```

## 📚 核心知识点

### 1. 运算符重载规则

#### 可重载的运算符
```cpp
+ - * / % ^ & | ~ ! = < > += -= *= /= %= ^= &= |= << >> >>= <<= == != <= >= && || ++ -- , ->* -> () []
```

#### 不可重载的运算符
```cpp
:: .* . ?: sizeof typeid
```

### 2. 成员函数 vs 友元函数

#### 成员函数形式
```cpp
class MyClass {
public:
    MyClass operator+(const MyClass& other) const;
    MyClass& operator+=(const MyClass& other);
};
```

#### 友元函数形式
```cpp
class MyClass {
    friend MyClass operator+(const MyClass& lhs, const MyClass& rhs);
    friend std::ostream& operator<<(std::ostream& os, const MyClass& obj);
};
```

### 3. 设计指导原则

#### 对称性原则
```cpp
// 如果 a + b 有意义，那么 b + a 也应该有意义
MyClass operator+(const MyClass& lhs, const MyClass& rhs);
```

#### 复合赋值优先
```cpp
// 先实现 +=，再用它实现 +
MyClass& operator+=(const MyClass& other) {
    // 实际的加法逻辑
    return *this;
}

MyClass operator+(MyClass lhs, const MyClass& rhs) {
    lhs += rhs;
    return lhs;
}
```

#### 前置后置递增
```cpp
// 前置递增
MyClass& operator++() {
    // 递增逻辑
    return *this;
}

// 后置递增
MyClass operator++(int) {
    MyClass temp = *this;
    ++(*this);
    return temp;
}
```

## 🎨 最佳实践

### 1. 保持语义直观
```cpp
// 好的设计：符合直觉
Vector v1, v2;
Vector v3 = v1 + v2;  // 向量加法

// 不好的设计：违反直觉
String s1, s2;
String s3 = s1 * s2;  // 字符串相乘？
```

### 2. 考虑效率
```cpp
// 返回引用避免不必要的拷贝
MyClass& operator+=(const MyClass& other) {
    // ...
    return *this;
}

// 参数传递优化
MyClass operator+(MyClass lhs, const MyClass& rhs) {  // 按值传递lhs
    return lhs += rhs;
}
```

### 3. 异常安全性
```cpp
MyClass& operator=(const MyClass& other) {
    if (this != &other) {  // 自赋值检查
        // 使用copy-and-swap惯用法
        MyClass temp(other);
        swap(temp);
    }
    return *this;
}
```

## 🚀 进阶主题

### 1. 转换运算符
```cpp
class MyClass {
public:
    operator int() const { return value; }  // 隐式转换
    explicit operator bool() const { return value != 0; }  // 显式转换
};
```

### 2. 函数对象
```cpp
class Multiplier {
    int factor;
public:
    Multiplier(int f) : factor(f) {}
    int operator()(int x) const { return x * factor; }
};
```

### 3. 智能指针实现
```cpp
template<typename T>
class SmartPtr {
    T* ptr;
public:
    T& operator*() const { return *ptr; }
    T* operator->() const { return ptr; }
};
```

## 💡 学习建议

1. **从简单开始**: 先实现算术运算符，再尝试复杂的运算符
2. **理解语义**: 每个运算符都应该有清晰的语义
3. **测试充分**: 考虑边界情况和异常情况
4. **参考标准库**: 学习std::string、std::vector等的设计
5. **实践项目**: 实现自己的复数类、矩阵类或容器类

## 🔗 相关资源

- [C++ Operator Overloading Guidelines](https://en.cppreference.com/w/cpp/language/operators)
- [Effective C++ Item 23-25](https://www.aristeia.com/books.html)
- [C++ Core Guidelines: Overloading](https://github.com/isocpp/CppCoreGuidelines)