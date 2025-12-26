# 答案09：继承应用

## 完整代码

见 `答案09_OOP题_继承应用.cpp`

## 解题思路

### 核心设计
使用继承实现代码复用，基类定义接口，派生类实现具体功能。

### 类设计
```cpp
class Shape {
protected:
    string name;  // 保护成员，派生类可以访问
public:
    Shape(string n);           // 构造函数
    virtual double getArea() = 0;  // 纯虚函数
    void display();            // 基类display
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(string n, double r) : Shape(n), radius(r) {}  // 初始化列表
    double getArea() override;  // 实现纯虚函数
    void display();            // 重写display
};
```

### 关键点
- **继承**：`class Circle : public Shape`
- **初始化列表**：`Circle(...) : Shape(n), radius(r) {}`
- **纯虚函数**：基类中`= 0`，派生类必须实现
- **函数重写**：派生类重写display，先调用基类版本

## 测试用例

### 输入
```
2
Circle1 5.0
Circle2 10.5
```

### 输出
```
Shape: Circle1, radius=5.0, area=78.5
Shape: Circle2, radius=10.5, area=346.4
```

### 验证
- Circle1：面积 = 3.14159 * 5.0 * 5.0 ≈ 78.5 ✓
- Circle2：面积 = 3.14159 * 10.5 * 10.5 ≈ 346.4 ✓

## 常见错误

1. **初始化列表错误**：忘记调用基类构造函数
2. **纯虚函数未实现**：派生类必须实现getArea()
3. **函数重写错误**：重写display时忘记调用基类版本
4. **访问控制错误**：name应该是protected而不是private

## 扩展思考

- 如何添加更多派生类？（如Rectangle继承Shape）
- 如何使用多态？（基类指针指向派生类对象）
- 为什么getArea()要声明为虚函数？（实现多态）

