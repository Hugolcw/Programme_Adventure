# 题目03：代码阅读 - STL容器操作

## 题目类型
代码阅读题

## 知识点
Lesson 8: STL容器 - vector、map的使用

## 题目描述

阅读以下代码，写出程序的输出结果。

```cpp
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.pop_back();
    
    cout << "Vector size: " << v.size() << endl;
    cout << "First element: " << v[0] << endl;
    cout << "Last element: " << v[v.size()-1] << endl;
    
    map<string, int> m;
    m["apple"] = 5;
    m["banana"] = 3;
    m["apple"] = 8;
    
    cout << "Map size: " << m.size() << endl;
    cout << "apple: " << m["apple"] << endl;
    cout << "banana: " << m["banana"] << endl;
    
    return 0;
}
```

## 要求
请写出程序的完整输出结果（包括所有换行）。

---

## 提示
注意vector的pop_back操作和map的键值覆盖。

