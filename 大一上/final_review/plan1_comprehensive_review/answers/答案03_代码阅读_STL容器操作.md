# 答案03：代码阅读 - STL容器操作

## 正确答案

```
Vector size: 2
First element: 10
Last element: 20
Map size: 2
apple: 8
banana: 3
```

## 解析

### Vector操作

1. **初始状态**：空vector
2. **push_back(10)**：v = [10]
3. **push_back(20)**：v = [10, 20]
4. **push_back(30)**：v = [10, 20, 30]
5. **pop_back()**：删除最后一个元素，v = [10, 20]
6. **v.size()**：返回2
7. **v[0]**：第一个元素是10
8. **v[v.size()-1]**：即v[1]，最后一个元素是20

### Map操作

1. **m["apple"] = 5**：插入键值对 {"apple": 5}
2. **m["banana"] = 3**：插入键值对 {"banana": 3}，此时m = {"apple": 5, "banana": 3}
3. **m["apple"] = 8**：**覆盖**已存在的键"apple"的值，m = {"apple": 8, "banana": 3}
4. **m.size()**：返回2（两个不同的键）
5. **m["apple"]**：返回8（被覆盖后的值）

### 关键知识点
- **vector的pop_back()**：删除最后一个元素，size减1
- **map的特性**：
  - 键唯一，重复赋值会覆盖
  - 使用[]访问不存在的键会自动创建（值为0或默认值）
- **STL容器的size()**：返回元素个数

### 常见错误
- 误以为map的重复赋值会创建多个键值对
- 忘记pop_back()会改变vector的大小

