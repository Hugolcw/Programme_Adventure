# C++ 快速参考卡片

## 📋 基础语法速查

### 数据类型
```cpp
int x = 10;
double d = 3.14;
char c = 'A';
bool b = true;
string s = "Hello";
```

### 输入输出
```cpp
#include <iostream>
using namespace std;

cin >> variable;
cout << value << endl;
```

### 控制流
```cpp
// if-else
if (condition) {
    // ...
} else {
    // ...
}

// for循环
for (int i = 0; i < n; i++) {
    // ...
}

// while循环
while (condition) {
    // ...
}
```

---

## 🔧 函数

### 函数定义
```cpp
返回类型 函数名(参数列表) {
    // 函数体
    return 值;
}
```

### 参数传递
```cpp
void func1(int x);           // 值传递
void func2(int& x);          // 引用传递
void func3(int* x);          // 指针传递
```

### 函数重载
```cpp
int add(int a, int b);
double add(double a, double b);
```

---

## 📦 数组和指针

### 数组
```cpp
int arr[5] = {1, 2, 3, 4, 5};
arr[0] = 10;
```

### 指针
```cpp
int x = 10;
int* ptr = &x;      // 取地址
*ptr = 20;          // 解引用
```

### 动态内存
```cpp
int* p = new int(10);
int* arr = new int[10];
delete p;
delete[] arr;
```

---

## 🏗️ 类与对象

### 类定义
```cpp
class MyClass {
private:
    int privateVar;
public:
    int publicVar;
    
    MyClass() { }                    // 默认构造函数
    MyClass(int x) { }               // 带参构造函数
    ~MyClass() { }                   // 析构函数
    
    void func() { }                  // 成员函数
};
```

### 对象创建
```cpp
MyClass obj;              // 调用默认构造函数
MyClass obj2(10);         // 调用带参构造函数
obj.func();               // 调用成员函数
```

---

## 🔄 继承

### 继承语法
```cpp
class Base {
protected:
    int x;
public:
    Base(int _x) : x(_x) { }
};

class Derived : public Base {
private:
    int y;
public:
    Derived(int _x, int _y) : Base(_x), y(_y) { }
};
```

### 访问控制
- `public`：外部可访问
- `private`：仅类内可访问
- `protected`：类内和派生类可访问

---

## 🎭 多态

### 虚函数
```cpp
class Base {
public:
    virtual void func() { }
};

class Derived : public Base {
public:
    void func() override { }
};
```

### 多态使用
```cpp
Base* ptr = new Derived();
ptr->func();  // 调用Derived的func
```

---

## 🧠 智能指针

### unique_ptr
```cpp
#include <memory>
unique_ptr<int> p = make_unique<int>(10);
unique_ptr<int> p2 = move(p);  // 转移所有权
```

### shared_ptr
```cpp
shared_ptr<int> p1 = make_shared<int>(10);
shared_ptr<int> p2 = p1;  // 共享所有权
```

### weak_ptr
```cpp
weak_ptr<int> wp = p1;
if (auto sp = wp.lock()) {
    // 使用sp
}
```

---

## 📚 STL容器

### vector
```cpp
#include <vector>
vector<int> v;
v.push_back(10);
v.pop_back();
v.size();
v.at(0);
v[0];
```

### list
```cpp
#include <list>
list<int> l;
l.push_back(10);
l.push_front(5);
```

### map
```cpp
#include <map>
map<string, int> m;
m["key"] = 10;
m.find("key");
```

### string
```cpp
#include <string>
string s = "Hello";
s += " World";
s.length();
s.substr(0, 5);
```

---

## 🔍 STL算法

### sort
```cpp
#include <algorithm>
sort(v.begin(), v.end());
sort(v.begin(), v.end(), greater<int>());
```

### find
```cpp
auto it = find(v.begin(), v.end(), value);
if (it != v.end()) { }
```

### count
```cpp
int cnt = count(v.begin(), v.end(), value);
```

---

## 🚀 移动语义

### 移动构造函数
```cpp
class MyClass {
public:
    MyClass(MyClass&& other) noexcept {
        // 移动资源
        data = other.data;
        other.data = nullptr;
    }
};
```

### std::move
```cpp
MyClass obj1;
MyClass obj2 = move(obj1);  // 使用移动构造函数
```

---

## ⚠️ 常见错误

1. **数组越界**：访问 `arr[n]` 当数组大小为n
2. **内存泄漏**：`new` 后忘记 `delete`
3. **悬空指针**：使用已释放的内存
4. **未初始化**：使用未初始化的变量
5. **忘记分号**：语句末尾缺少 `;`

---

## 💡 常用技巧

### Lambda表达式
```cpp
auto func = [](int x) { return x * 2; };
sort(v.begin(), v.end(), [](int a, int b) { return a > b; });
```

### 范围for循环
```cpp
for (int val : vector) {
    cout << val << " ";
}
```

### auto关键字
```cpp
auto x = 10;           // int
auto s = "Hello";      // const char*
auto it = v.begin();   // iterator
```

---

## 📌 重要概念速记

| 概念 | 说明 |
|------|------|
| **封装** | 将数据和行为封装在类中 |
| **继承** | 子类继承父类的成员 |
| **多态** | 同一接口，不同实现 |
| **RAII** | 资源获取即初始化 |
| **左值** | 有名字的变量 |
| **右值** | 临时对象、字面量 |
| **引用计数** | shared_ptr使用的机制 |
| **虚函数表** | 实现多态的机制 |

---

**快速查阅，祝你考试顺利！** 🎯

