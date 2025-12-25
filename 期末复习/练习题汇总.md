# C++ 练习题汇总

## 📝 各章节练习题位置

### Lesson 1: 数据类型
**练习文件位置：** `lesson1.data-type/practice/`

1. **circle_calculator.cpp** - 圆面积计算
   - 计算半径为5的圆的面积和周长
   - 重点：基本数据类型、数学运算

2. **even_checker.cpp** - 偶数判断
   - 判断输入的整数是奇数还是偶数
   - 重点：条件判断、取模运算

3. **multiples_of_three.cpp** - 3的倍数
   - 输出1-100之间所有3的倍数
   - 重点：循环语句、条件判断

4. **calculator.cpp** - 四则运算计算器
   - 简单的四则运算计算器
   - 重点：输入输出、运算符、switch-case

---

### Lesson 2: 函数和作用域
**练习文件位置：** `lesson2.function-and-scope/exercises/`

1. **exercise1_functions** - 函数练习
   - 计算圆的面积和周长
   - 重点：函数定义、函数调用、返回值

2. **exercise2_overload** - 函数重载
   - 实现不同类型的add函数
   - 重点：函数重载、参数类型

3. **exercise3_reference** - 引用传递
   - 使用引用修改变量值
   - 重点：引用传递 vs 值传递

4. **exercise4_default** - 默认参数
   - 使用默认参数的函数
   - 重点：默认参数的位置和用法

**复习题位置：** `lesson2.function-and-scope/review/`
- `find_max` - 找最大值（值传递和引用传递对比）
- `passBy` - 值传递和引用传递示例
- `swapNumber` - 交换两个数字

---

### Lesson 3: 数组和指针
**练习文件位置：** `lesson3.array-and-pointer/exercises/`

**重点练习：**
- 数组的声明和初始化
- 指针的基本操作
- 指针与数组的关系
- 动态内存分配

**复习题位置：** `lesson3.array-and-pointer/reviews/`

---

### Lesson 4: OOP上
**练习文件位置：** `lesson4.OOP上/exercises/`

1. **car_constructor_input.cpp** - 汽车类练习
   - 创建Car类，包含构造函数
   - 重点：类的定义、构造函数、成员函数、访问控制

---

### Lesson 5: OOP下
**练习文件位置：** `lesson5.OOP下/exercises/`

1. **car_Rectangle.cpp** - 继承练习
   - 实现Rectangle类继承Shape类
   - 重点：继承、构造函数初始化列表、函数重写

---

### Lesson 6: 多态
**练习文件位置：** `lesson6.polymorphism/exercises/`

1. **vehicle_polymorphism.cpp** - 多态练习
   - 实现Vehicle基类和多个派生类
   - 重点：虚函数、多态、动态绑定

---

### Lesson 7: 智能指针
**练习文件位置：** `lesson7.smart_pointer/exercises/`

1. **weapon_shop_unique_ptr.cpp** - unique_ptr练习
   - 使用unique_ptr管理武器对象
   - 重点：unique_ptr的使用、所有权转移

2. **weapon_shop_shared_ptr.cpp** - shared_ptr练习
   - 使用shared_ptr管理共享资源
   - 重点：shared_ptr的使用、引用计数

---

### Lesson 8: STL容器
**练习文件位置：** `lesson8.STL_Containers/exercises/`

1. **vector_scores_statistics.cpp** - vector练习
   - 统计学生分数（总数、总和、平均分）
   - 重点：vector的基本操作、范围for循环

2. **word_frequency_counter.cpp** - map练习
   - 统计单词出现频率
   - 重点：map的使用、迭代器

---

### Lesson 9: STL算法
**练习文件位置：** `lesson9.STL_Algorithms/exercises/`

1. **stl_practice_student_roster.cpp** - 学生名册管理
   - 使用STL算法管理学生信息
   - 重点：sort、find_if、Lambda表达式

2. **stl_practice_inventory_map.cpp** - 库存管理
   - 使用map和算法管理库存
   - 重点：map操作、算法应用

---

## 🎯 综合练习题

### 题目1：学生管理系统（综合OOP）
**要求：**
1. 定义Student基类，包含name、id、age
2. 定义Undergraduate类继承Student，添加major字段
3. 使用虚函数实现多态显示信息
4. 使用vector存储多个学生对象

**关键点：**
- 类的定义和继承
- 构造函数初始化列表
- 虚函数和多态
- STL容器的使用

---

### 题目2：图书管理系统（综合STL）
**要求：**
1. 使用map存储图书信息（书名->价格）
2. 实现添加、查找、删除功能
3. 按价格排序显示所有图书
4. 统计总价和平均价格

**关键点：**
- map的基本操作
- STL算法的使用（sort、find）
- 迭代器的使用

---

### 题目3：内存管理（智能指针）
**要求：**
1. 创建一个Resource类，包含动态分配的内存
2. 使用unique_ptr管理Resource对象
3. 实现资源的转移
4. 确保没有内存泄漏

**关键点：**
- 动态内存分配
- unique_ptr的使用
- RAII原则

---

## 📋 常见题型

### 1. 代码阅读题
- 给出代码，要求写出输出结果
- 重点：理解执行流程、作用域、多态

### 2. 代码填空题
- 给出不完整的代码，要求填空
- 重点：语法规则、常见模式

### 3. 代码改错题
- 给出有错误的代码，要求找出并修正
- 重点：常见错误识别

### 4. 编程题
- 根据需求编写完整程序
- 重点：综合运用知识点

---

## 🔍 练习建议

### 1. 基础练习
- [ ] 完成所有章节的基础练习题
- [ ] 理解每道题的解题思路
- [ ] 尝试修改代码，观察结果变化

### 2. 综合练习
- [ ] 完成综合练习题
- [ ] 将多个知识点结合使用
- [ ] 注意代码的规范性和可读性

### 3. 模拟考试
- [ ] 限时完成编程题
- [ ] 练习手写代码
- [ ] 检查常见错误

---

## 💡 解题技巧

### 1. 理解题目
- 仔细阅读题目要求
- 明确输入输出格式
- 注意边界条件

### 2. 设计思路
- 先设计整体结构
- 再实现具体功能
- 最后优化代码

### 3. 代码实现
- 先写框架（类定义、函数声明）
- 再实现功能
- 最后测试和调试

### 4. 检查要点
- 语法错误（括号、分号）
- 逻辑错误（条件判断、循环）
- 内存管理（new/delete配对）
- 边界情况（空指针、空容器）

---

## 📚 推荐练习顺序

1. **第一周**：Lesson 1-3（基础语法）
   - 数据类型、函数、数组指针

2. **第二周**：Lesson 4-6（面向对象）
   - 类、继承、多态

3. **第三周**：Lesson 7-10（高级特性）
   - 智能指针、STL、移动语义

4. **第四周**：综合练习和模拟考试
   - 综合运用所有知识点

---

## 🎓 考试重点题型预测

### 必考题型
1. **类的定义和实现**（OOP基础）
2. **继承和多态**（虚函数）
3. **STL容器和算法**（vector、map、sort）
4. **内存管理**（智能指针）

### 高频考点
1. 构造函数和析构函数
2. 函数重载和重写
3. 引用传递和值传递
4. 迭代器的使用
5. Lambda表达式

---

**多练习，多思考，祝你考试顺利！** 🚀

