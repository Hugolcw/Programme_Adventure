#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // sort 也在 <algorithm> 中

using namespace std;

void print_vector(const string &title, const vector<int> &v)
{
    cout << title << ": [ ";
    for (int val : v)
    {
        cout << val << " ";
    }
    cout << "]" << endl;
}

// --- 这是一个“比较谓词” (Comparison Predicate) ---
// sort 算法将使用这个函数来决定两个元素 'a' 和 'b' 的顺序
// 如果这个函数返回 true，'a' 就会被排在 'b' 的前面
bool compare_descending(int a, int b)
{
    return a > b;
}

int main()
{
    vector<int> v = {10, 30, 20, 30, 40, 50, 15, 25};
    print_vector("Original", v);
    cout << endl;

    // 1. 默认排序（从小到大）
    cout << "--- Default sort (ascending) ---" << endl;

    // 语法：sort(begin, end)
    sort(v.begin(), v.end());

    print_vector("Sorted (ascending)", v);
    cout << endl;

    // 2. 自定义排序（从大到小）
    cout << "--- Custom sort (descending) ---" << endl;

    // 重置 vector 以便演示
    v = {10, 30, 20, 30, 40, 50, 15, 25};
    print_vector("Restored", v);

    // 语法：sort(begin, end, comparison_function)
    // 我们把“比较函数” compare_descending 作为第三个参数传进去
    sort(v.begin(), v.end(), compare_descending);

    print_vector("Sorted (descending)", v);
    cout << endl;

    // 3. 对 string 排序（展示通用性）
    cout << "--- Sorting a String ---" << endl;
    string s = "Hello, C++ World!";
    cout << "Original string: '" << s << "'" << endl;

    // 算法不关心类型，只认迭代器
    sort(s.begin(), s.end());

    // string 也会被按字符顺序排序
    cout << "Sorted string: '" << s << "'" << endl;

    return 0;
}