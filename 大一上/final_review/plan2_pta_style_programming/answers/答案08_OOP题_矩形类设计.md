# 答案08：矩形类设计

## 完整代码

见 `答案08_OOP题_矩形类设计.cpp`

## 解题思路

### 核心设计
设计一个Rectangle类，封装矩形的数据和行为。

### 类设计
```cpp
class Rectangle {
private:
    double width, height;  // 私有成员，外部不能直接访问
    
public:
    Rectangle(double w, double h);  // 构造函数
    double getArea();                // 计算面积
    double getPerimeter();           // 计算周长
    void display();                  // 显示信息
};
```

### 关键点
- **封装**：width和height设为private，通过公有函数访问
- **构造函数**：初始化成员变量
- **成员函数**：可以访问私有成员
- **输出格式**：使用setprecision控制小数位数

## 测试用例

### 输入
```
2
5.0 3.0
10.5 8.5
```

### 输出
```
Rectangle: width=5.0, height=3.0, area=15.0, perimeter=16.0
Rectangle: width=10.5, height=8.5, area=89.25, perimeter=38.0
```

### 验证
- 第一个矩形：面积=5.0*3.0=15.0，周长=2*(5.0+3.0)=16.0 ✓
- 第二个矩形：面积=10.5*8.5=89.25，周长=2*(10.5+8.5)=38.0 ✓

## 常见错误

1. **访问控制错误**：width和height应该是private
2. **构造函数错误**：忘记初始化成员变量
3. **输出格式错误**：小数位数不对，或格式字符串错误
4. **函数调用错误**：在display中调用getArea()和getPerimeter()

## 扩展思考

- 如何添加setter和getter函数？（设置和获取width、height）
- 如何添加默认构造函数？（无参构造函数）
- 如何添加析构函数？（虽然这个例子不需要）

