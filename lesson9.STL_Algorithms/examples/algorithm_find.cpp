#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    // 1. 在 vector 中查找
    cout << "--- Finding in std::vector ---" << endl;
    vector<int> v = {10, 20, 30, 40, 50};
    int value_to_find_1 = 30;

    // find() 接收一个 [being,end) 区间和一个要查找的值
    auto result1 = find(v.begin(), v.end(), value_to_find_1);

    // 检查返回的迭代器
    if (result1 != v.end())
    {
        // 返回值不为 v.end() 说明找到了
        // result1 是一个指向 30 的迭代器
        cout << "找到了 result1 ，值为：" << *result1 << endl;
    }
    else
    {
        cout << "未找到" << value_to_find_1 << endl;
    }

    // 2. 查找一个不存在的值
    cout << "\n--- Searching for a non-existent value ---" << endl;
    int value_to_find_2 = 99;
    auto result2 = find(v.begin(), v.end(), value_to_find_2);

    if (result2 != v.end())
    {
        cout << "找到了 result2 ，值为：" << *result2 << endl;
    }
    else
    {
        cout << "未找到" << value_to_find_2 << endl;
    }

    // 3. 在 string 中查找（展示算法的通用性）
    cout << "\n--- Finding in std::string ---" << endl;
    string s = "Hello, C++ World";
    char char_to_find = 'W';

    // 还是用同一个 find() 函数，无需关心容器类型
    auto result3 = find(s.begin(), s.end(), char_to_find);

    if (result3 != s.end())
    {
        cout << "找到了 result3 ，值为：" << *result3 << endl;
        // 可以使用 distance() 来计算出迭代器离开头有多远（即索引）
        // 要引入 iterator 头文件
        cout << "它在索引 " << distance(s.begin(), result3) << " 的位置。" << endl;
    }
    else
    {
        cout << "未找到" << char_to_find << endl;
    }

    return 0;
}
