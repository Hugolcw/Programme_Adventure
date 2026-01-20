#include <iostream>
#include <vector>
#include <algorithm> // remove 在这里

using namespace std;

// 辅助函数，打印 vector (包含 size 和 capacity)
void print_stats(const string &title, const vector<int> &v)
{
    cout << title << ": [ ";
    for (int val : v)
    {
        cout << val << " ";
    }
    cout << "]" << endl;
    cout << "  - Size: " << v.size() << ", Capacity: " << v.capacity() << endl;
    cout << "--------------------" << endl;
}

int main()
{
    vector<int> v = {10, 20, 30, 40, 30, 50, 30};
    print_stats("Original", v);

    int value_to_remove = 30;

    // --- 1. 单独使用 std::remove (看清它的“搬运”行为) ---
    cout << "--- Calling std::remove(v.begin(), v.end(), 30) ---" << endl;

    // remove 会把所有“不等于30”的元素 (10, 20, 40, 50) 搬到最前面
    // 它会返回一个迭代器，指向最后一个“好元素”(50)的下一个位置
    auto new_end = remove(v.begin(), v.end(), value_to_remove);

    // 观察：vector 的内容和大小都变了...吗？
    print_stats("After remove (before erase)", v);

    // 你会看到输出：[ 10 20 40 50 ? ? ? ]
    // (注意: ? 代表“未定义的值”，它们是“垃圾数据”)
    // 并且 Size 仍然是 7！remove 没有改变 vector 的大小！
    // new_end 正是指向 ? 的位置。

    cout << "new_end is pointing to value: " << *new_end << endl;
    cout << "(The values at the end are junk, ignore them.)" << endl;
    cout << endl;

    // --- 2. 使用 Erase-Remove Idiom (正确的删除方式) ---
    cout << "--- Calling the 'Erase-Remove Idiom' ---" << endl;

    // 我们必须手动调用 erase，告诉 vector：“请从 new_end 开始，
    // 一直删除到你真正的 v.end() 为止。”
    v.erase(new_end, v.end());

    print_stats("After erase (final result)", v);
    // 现在，Size 变成了 4，Capacity 保持不变
    // vector 真正地缩小了！[ 10 20 40 50 ]

    return 0;
}