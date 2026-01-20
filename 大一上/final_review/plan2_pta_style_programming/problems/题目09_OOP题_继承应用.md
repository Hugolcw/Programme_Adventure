# 题目09：继承应用

## 题目类型
OOP题

## 难度
中等

## 知识点
继承、构造函数初始化列表、函数重写

## 题目描述

设计一个基类Shape和派生类Circle：
- **基类Shape**：
  - 保护成员：name（string类型），表示形状名称
  - 公有成员：
    - 构造函数：Shape(string n)，初始化name
    - 虚函数：virtual double getArea() = 0（纯虚函数）
    - 成员函数：void display()，输出"Shape: [name]"

- **派生类Circle**：
  - 私有成员：radius（double类型），表示半径
  - 公有成员：
    - 构造函数：Circle(string n, double r)，使用初始化列表调用基类构造函数
    - 实现getArea()函数：返回圆的面积（π * r^2，π取3.14159）
    - 重写display()函数：先调用基类的display()，然后输出", radius=[半径], area=[面积]"

## 输入格式

第一行输入一个整数t（1 <= t <= 100），表示测试用例的数量。
接下来t行，每行输入一个字符串name和一个浮点数radius（1 <= radius <= 100），表示圆的名称和半径。

## 输出格式

对于每个测试用例，输出圆的信息（调用display函数）。

## 样例输入

```
2
Circle1 5.0
Circle2 10.5
```

## 样例输出

```
Shape: Circle1, radius=5.0, area=78.5
Shape: Circle2, radius=10.5, area=346.4
```

## 提示

- 使用初始化列表调用基类构造函数：Circle(...) : Shape(...) { }
- 重写display()时，先调用基类版本：Shape::display()
- 注意输出格式和精度

---

## 要求

1. 使用继承和虚函数
2. 使用构造函数初始化列表
3. 实现函数重写
4. 注意输出格式

