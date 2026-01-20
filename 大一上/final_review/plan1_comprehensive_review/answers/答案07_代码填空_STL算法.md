# 答案07：代码填空 - STL算法

## 正确答案

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6};
    
    // 1. 使用sort算法对vector进行升序排序
    sort(v.begin(), v.end());
    
    cout << "After sort: ";
    for (int x : v) cout << x << " ";
    cout << endl;
    
    // 2. 使用find算法查找值为5的元素
    auto it = find(v.begin(), v.end(), 5);
    if (it != v.end()) {
        cout << "Found 5" << endl;
    } else {
        cout << "Not found 5" << endl;
    }
    
    // 3. 使用count算法统计值为1的元素个数
    int cnt = count(v.begin(), v.end(), 1);
    cout << "Count of 1: " << cnt << endl;
    
    return 0;
}
```

## 解析

### 1. sort算法

```cpp
sort(v.begin(), v.end());
```

**关键点**：
- **参数**：两个迭代器，表示排序范围 `[begin, end)`
- **默认行为**：升序排序
- **修改原容器**：直接修改vector，不返回新容器
- **时间复杂度**：O(n log n)

**输出**：`After sort: 1 1 2 3 4 5 6 9`

### 2. find算法

```cpp
auto it = find(v.begin(), v.end(), 5);
if (it != v.end()) {
    cout << "Found 5" << endl;
} else {
    cout << "Not found 5" << endl;
}
```

**关键点**：
- **返回值**：迭代器，指向找到的元素；如果未找到，返回 `v.end()`
- **判断方法**：`it != v.end()` 表示找到
- **auto关键字**：自动推导迭代器类型
- **时间复杂度**：O(n)

**输出**：`Found 5`

### 3. count算法

```cpp
int cnt = count(v.begin(), v.end(), 1);
cout << "Count of 1: " << cnt << endl;
```

**关键点**：
- **返回值**：整数，表示元素出现次数
- **参数**：范围迭代器和要统计的值
- **时间复杂度**：O(n)

**输出**：`Count of 1: 2`（排序后有两个1）

### 完整程序输出

```
After sort: 1 1 2 3 4 5 6 9
Found 5
Count of 1: 2
```

### 常见错误

1. **忘记包含头文件**：
   ```cpp
   #include <algorithm>  // 必须包含
   ```

2. **find的返回值判断错误**：
   ```cpp
   // 错误
   if (find(...) == 5) { }
   // 正确
   if (find(...) != v.end()) { }
   ```

3. **迭代器范围理解错误**：
   - `[begin, end)` 是左闭右开区间
   - `end()` 指向最后一个元素的下一个位置

### 扩展知识

- **降序排序**：`sort(v.begin(), v.end(), greater<int>())`
- **自定义比较**：可以传入比较函数或Lambda表达式
- **find_if**：条件查找，如 `find_if(v.begin(), v.end(), [](int x) { return x > 5; })`

