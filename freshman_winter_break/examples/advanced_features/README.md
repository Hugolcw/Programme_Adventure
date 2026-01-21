# 🚀 C++高级特性示例

> 探索现代C++的高级特性，掌握函数指针、类型转换、函数绑定等核心技术

## 📁 文件说明

### 🎯 成员函数指针
- **`member_function_pointer.cpp`** - 成员函数指针详解
  - 成员函数指针的声明和使用
  - 处理函数重载的技巧
  - 成员变量指针的应用
  - 实际应用场景和最佳实践

### 🔄 类型转换
- **`static_cast_examples.cpp`** - static_cast类型转换详解
  - 基本类型转换
  - 指针和引用转换
  - 解决函数重载歧义
  - 与其他转换方式的对比

### 🔗 函数绑定器
- **`std_bind.cpp`** - std::bind基础用法
  - 函数参数绑定
  - 占位符的使用
  - 成员函数绑定

- **`std_bind_advanced.cpp`** - std::bind高级应用
  - 复杂参数绑定场景
  - 与lambda表达式的对比
  - 实际项目中的应用模式

### 🎪 统一调用接口
- **`std_invoke_examples.cpp`** - std::invoke详解
  - 统一调用不同类型的可调用对象
  - 泛型编程中的应用
  - 与std::bind的结合使用

## 🎯 学习目标

### 核心概念
- ✅ 掌握成员函数指针的语法和应用
- ✅ 理解C++类型转换机制
- ✅ 熟练使用std::bind和std::invoke
- ✅ 了解现代C++函数式编程特性

### 实际应用
- ✅ 回调函数的实现
- ✅ 事件处理系统设计
- ✅ 泛型编程技巧
- ✅ 函数式编程模式

### 设计模式
- ✅ 命令模式的实现
- ✅ 观察者模式的应用
- ✅ 策略模式的函数式实现

## 🛠️ 编译和运行

```bash
# 编译单个示例
g++ -std=c++17 -Wall -O2 -o build/member_ptr member_function_pointer.cpp
g++ -std=c++17 -Wall -O2 -o build/static_cast static_cast_examples.cpp
g++ -std=c++17 -Wall -O2 -o build/bind_basic std_bind.cpp
g++ -std=c++17 -Wall -O2 -o build/bind_advanced std_bind_advanced.cpp
g++ -std=c++17 -Wall -O2 -o build/invoke std_invoke_examples.cpp

# 运行示例
./build/member_ptr
./build/static_cast
./build/bind_basic
./build/bind_advanced
./build/invoke
```

## 📚 核心知识点

### 1. 成员函数指针

#### 基本语法
```cpp
class MyClass {
public:
    void func1();
    int func2(int x);
    static void static_func();
};

// 成员函数指针声明
void (MyClass::*ptr1)() = &MyClass::func1;
int (MyClass::*ptr2)(int) = &MyClass::func2;

// 调用方式
MyClass obj;
(obj.*ptr1)();           // 通过对象调用
(&obj->*ptr1)();         // 通过指针调用
```

#### 处理重载函数
```cpp
class MyClass {
public:
    void print();
    void print(int x);
    void print(const std::string& s);
};

// 使用static_cast明确指定函数签名
auto ptr1 = static_cast<void(MyClass::*)()>(&MyClass::print);
auto ptr2 = static_cast<void(MyClass::*)(int)>(&MyClass::print);
auto ptr3 = static_cast<void(MyClass::*)(const std::string&)>(&MyClass::print);
```

### 2. 类型转换

#### static_cast用法
```cpp
// 基本类型转换
double d = 3.14;
int i = static_cast<int>(d);

// 指针转换
class Base {};
class Derived : public Base {};

Derived* derived = new Derived;
Base* base = static_cast<Base*>(derived);  // 向上转换

// 解决重载歧义
void func(int);
void func(double);

func(static_cast<int>(3.14));  // 明确调用int版本
```

#### 与其他转换的区别
```cpp
// C风格转换（不推荐）
int i = (int)3.14;

// static_cast（推荐）
int i = static_cast<int>(3.14);

// dynamic_cast（运行时检查）
Base* base = new Derived;
Derived* derived = dynamic_cast<Derived*>(base);

// const_cast（移除const）
const int* const_ptr = &i;
int* ptr = const_cast<int*>(const_ptr);

// reinterpret_cast（重新解释内存）
int i = 42;
char* char_ptr = reinterpret_cast<char*>(&i);
```

### 3. 函数绑定器

#### std::bind基础
```cpp
#include <functional>

// 普通函数绑定
int add(int a, int b) { return a + b; }
auto add5 = std::bind(add, 5, std::placeholders::_1);
int result = add5(3);  // 等价于 add(5, 3)

// 成员函数绑定
class Calculator {
public:
    int multiply(int a, int b) { return a * b; }
};

Calculator calc;
auto multiply_by_2 = std::bind(&Calculator::multiply, &calc, 2, std::placeholders::_1);
int result = multiply_by_2(5);  // 等价于 calc.multiply(2, 5)
```

#### 高级绑定技巧
```cpp
// 参数重排序
auto subtract_reversed = std::bind(subtract, std::placeholders::_2, std::placeholders::_1);

// 嵌套绑定
auto complex_func = std::bind(func1, std::bind(func2, std::placeholders::_1), 42);

// 绑定引用
int x = 10;
auto increment = std::bind(add, std::ref(x), 1);
```

### 4. 统一调用接口

#### std::invoke用法
```cpp
#include <functional>

// 调用普通函数
int add(int a, int b) { return a + b; }
int result = std::invoke(add, 3, 4);

// 调用成员函数
class MyClass {
public:
    int multiply(int a, int b) { return a * b; }
};

MyClass obj;
int result = std::invoke(&MyClass::multiply, obj, 3, 4);

// 调用lambda
auto lambda = [](int x) { return x * x; };
int result = std::invoke(lambda, 5);

// 调用函数对象
struct Functor {
    int operator()(int x) { return x + 1; }
};
Functor f;
int result = std::invoke(f, 10);
```

## 🎨 实际应用场景

### 1. 事件处理系统
```cpp
class EventHandler {
    using EventCallback = std::function<void()>;
    std::map<std::string, EventCallback> callbacks;

public:
    template<typename Func, typename... Args>
    void register_event(const std::string& name, Func&& func, Args&&... args) {
        callbacks[name] = std::bind(std::forward<Func>(func), std::forward<Args>(args)...);
    }

    void trigger_event(const std::string& name) {
        if (callbacks.find(name) != callbacks.end()) {
            callbacks[name]();
        }
    }
};
```

### 2. 命令模式实现
```cpp
class Command {
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
};

template<typename Func, typename... Args>
class FunctionCommand : public Command {
    std::function<void()> func;
public:
    FunctionCommand(Func&& f, Args&&... args) 
        : func(std::bind(std::forward<Func>(f), std::forward<Args>(args)...)) {}
    
    void execute() override { func(); }
};
```

### 3. 泛型回调系统
```cpp
template<typename Callable, typename... Args>
auto make_callback(Callable&& callable, Args&&... args) {
    return [callable = std::forward<Callable>(callable), 
            args = std::make_tuple(std::forward<Args>(args)...)]() mutable {
        return std::apply(callable, args);
    };
}
```

## 🚀 现代C++替代方案

### Lambda vs std::bind
```cpp
// 使用std::bind
auto add5 = std::bind(add, 5, std::placeholders::_1);

// 使用lambda（推荐）
auto add5 = [](int x) { return add(5, x); };

// 复杂情况下lambda更清晰
auto complex_bind = std::bind(func, std::placeholders::_2, 42, std::placeholders::_1);
auto complex_lambda = [](int a, int b) { return func(b, 42, a); };
```

### 成员函数指针的现代用法
```cpp
// 传统方式
void (MyClass::*ptr)() = &MyClass::func;
(obj.*ptr)();

// 现代方式（使用std::invoke）
auto func_ptr = &MyClass::func;
std::invoke(func_ptr, obj);

// 或者使用lambda
auto caller = [&obj](){ obj.func(); };
caller();
```

## 💡 学习建议

1. **理解原理**: 深入理解每个特性的工作原理
2. **对比学习**: 了解传统方法和现代方法的区别
3. **实际应用**: 在项目中尝试使用这些特性
4. **性能考虑**: 了解各种方法的性能影响
5. **代码可读性**: 选择最清晰易懂的实现方式

## 🔗 相关资源

- [std::bind - cppreference](https://en.cppreference.com/w/cpp/utility/functional/bind)
- [std::invoke - cppreference](https://en.cppreference.com/w/cpp/utility/functional/invoke)
- [Member function pointers - cppreference](https://en.cppreference.com/w/cpp/language/pointer#Pointers_to_members)
- [Type casting - cppreference](https://en.cppreference.com/w/cpp/language/cast)