# 题目08：矩形类设计

## 题目类型
OOP题

## 难度
中等

## 知识点
类设计、构造函数、成员函数、封装

## 题目描述

设计一个Rectangle类，包含以下功能：
- 私有成员：width（宽度）、height（高度），都是double类型
- 公有成员：
  - 构造函数：Rectangle(double w, double h)，初始化宽度和高度
  - 成员函数getArea()：返回矩形的面积
  - 成员函数getPerimeter()：返回矩形的周长
  - 成员函数display()：输出矩形的信息，格式："Rectangle: width=宽度, height=高度, area=面积, perimeter=周长"

## 输入格式

第一行输入一个整数t（1 <= t <= 100），表示测试用例的数量。
接下来t行，每行输入两个浮点数w和h（1 <= w, h <= 1000），表示矩形的宽度和高度。

## 输出格式

对于每个测试用例，输出矩形的信息（调用display函数）。

## 样例输入

```
2
5.0 3.0
10.5 8.5
```

## 样例输出

```
Rectangle: width=5.0, height=3.0, area=15.0, perimeter=16.0
Rectangle: width=10.5, height=8.5, area=89.25, perimeter=38.0
```

## 提示

- 面积 = width * height
- 周长 = 2 * (width + height)
- 注意输出格式的精确性（保留小数位数）

---

## 要求

1. 定义Rectangle类
2. 实现构造函数和所有成员函数
3. 注意访问控制（私有成员、公有函数）
4. 输出格式要精确

