# 题目07：代码填空 - STL算法

## 题目类型
代码填空题

## 知识点
Lesson 9: STL算法 - sort、find、count

## 题目描述

请补充完整以下代码，使用STL算法对vector进行操作。

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6};
    
    // 1. 请使用sort算法对vector进行升序排序
    // 补充代码：________________
    
    cout << "After sort: ";
    for (int x : v) cout << x << " ";
    cout << endl;
    
    // 2. 请使用find算法查找值为5的元素
    // 补充代码：________________
    // 如果找到，输出"Found 5"，否则输出"Not found 5"
    
    // 3. 请使用count算法统计值为1的元素个数
    // 补充代码：________________
    // 输出：Count of 1: [个数]
    
    return 0;
}
```

## 要求
1. 使用 `sort` 对vector进行升序排序
2. 使用 `find` 查找指定元素
3. 使用 `count` 统计元素出现次数
4. 补充完整的代码，使程序能够正确运行

---

## 提示
- `sort(v.begin(), v.end())` - 对容器排序
- `find(v.begin(), v.end(), value)` - 查找元素，返回迭代器
- `count(v.begin(), v.end(), value)` - 统计元素个数

