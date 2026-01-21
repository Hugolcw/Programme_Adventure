# 答案12：编程题 - STL应用

## 完整代码

见 `答案12_编程题_STL应用.cpp`

## 关键知识点解析

### 1. vector的基本操作

```cpp
vector<int> scores;
scores.push_back(score);  // 添加元素
scores.size();            // 获取大小
scores[i];                // 访问元素
```

### 2. STL算法 - accumulate（求和）

```cpp
#include <numeric>
double sum = accumulate(scores.begin(), scores.end(), 0);
```

- **功能**：计算容器中所有元素的和
- **参数**：起始迭代器、结束迭代器、初始值
- **需要头文件**：`<numeric>`

### 3. STL算法 - max_element / min_element

```cpp
int max_score = *max_element(scores.begin(), scores.end());
int min_score = *min_element(scores.begin(), scores.end());
```

- **返回值**：指向最大/最小元素的迭代器
- **解引用**：使用 `*` 获取值

### 4. STL算法 - count_if（条件计数）

```cpp
int pass_count = count_if(scores.begin(), scores.end(), 
                          [](int s) { return s >= 60; });
```

- **Lambda表达式**：`[](int s) { return s >= 60; }`
- **功能**：统计满足条件的元素个数
- **C++11特性**：Lambda表达式

### 5. STL算法 - sort（排序）

```cpp
sort(scores.begin(), scores.end(), greater<int>());
```

- **默认**：升序排序
- **降序**：使用 `greater<int>()` 作为比较函数
- **修改原容器**：直接修改vector

### 6. STL算法 - find（查找）

```cpp
auto it = find(scores.begin(), scores.end(), target);
if (it != scores.end()) {
    // 找到
} else {
    // 未找到
}
```

- **返回值**：迭代器，指向找到的元素
- **判断**：`it != scores.end()` 表示找到

## 测试用例

### 输入
```
5
85 92 58 76 90
76
```

### 输出
```
Average: 80.20
Max: 92, Min: 58
Pass: 4
92 90 85 76 58
Found
```

## 代码解析

### 计算平均分
```cpp
double sum = accumulate(scores.begin(), scores.end(), 0);
double avg = sum / n;
```
- 使用accumulate求和，然后除以n

### 统计及格人数
```cpp
int pass_count = count_if(scores.begin(), scores.end(), 
                          [](int s) { return s >= 60; });
```
- Lambda表达式：`[](int s) { return s >= 60; }`
- 等价于：检查每个分数是否 >= 60

### 降序排序
```cpp
sort(scores.begin(), scores.end(), greater<int>());
```
- `greater<int>()`：从大到小排序
- 也可以自定义比较函数

## 常见错误

1. **忘记包含头文件**：
   - `<numeric>` - accumulate
   - `<algorithm>` - sort, find等

2. **Lambda表达式语法错误**：
   ```cpp
   // 正确
   [](int s) { return s >= 60; }
   // 错误
   (int s) { return s >= 60; }  // 缺少[]
   ```

3. **迭代器解引用错误**：
   ```cpp
   // 正确
   int max = *max_element(...);
   // 错误
   int max = max_element(...);  // 忘记解引用
   ```

## 扩展思考

1. 如何使用自定义比较函数排序？
2. 如何使用find_if进行条件查找？
3. 如何使用transform转换容器元素？

