#include <iostream>
#include <list>
#include <iterator>

using namespace std;

void print_list(const list<int> &my_list)
{
    cout << "List contents: [";
    // 只能用迭代器或范围for来历遍
    for (int val : my_list)
    {
        cout << val << " ";
    }
    cout << "]" << endl;
}

int main()
{
    // 1.创建和初始化
    list<int> my_list = {10, 20, 30, 40};
    print_list(my_list);
    cout << endl;

    // 2.添加元素（list 的独特方式）
    cout << "--- Adding elements..." << endl;
    my_list.push_back(50); // 与 vector 一样可在末尾添加
    my_list.push_front(0); // list 的独有的开头添加
    print_list(my_list);
    cout << endl;

    // 3.随机访问
    // list 不支持 [] 运算符，需要迭代器
    // cout << my_list[2] << endl; // 语法错误

    // 4.中间插入元素
    cout << "--- Inserting in the middle..." << endl;
    // 在 30 之前插入 999

    // a.获取一个指向开头的迭代器
    auto it = my_list.begin();

    // b.使迭代器指向 30
    // 不能使用 it = it + 3，因为迭代器在物理上内存不连续，不支持跳跃
    ++it;
    ++it;
    ++it;

    // (更快的移动方式是使用 std::advance)
    // auto it = my_list.begin();
    // std::advance(it, 3); // it 现在指向 30

    my_list.insert(it, 999);
    print_list(my_list);
    cout << endl;

    // 5.删除元素
    cout << "--- Removing elements..." << endl;
    my_list.pop_front(); // 删除开头元素 0
    my_list.pop_back();  // 删除末尾元素 50
    print_list(my_list);

    // 按值删除
    my_list.remove(999); // 删除所有值为 999 的元素
    print_list(my_list);

    return 0;
}