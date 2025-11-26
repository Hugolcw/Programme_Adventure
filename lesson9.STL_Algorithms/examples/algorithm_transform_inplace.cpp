#include <iostream>
#include <vector>
#include <algorithm> // transform
#include <cctype>    // 包含 tolower, toupper

using namespace std;

// “平方”函数 (和上次一样)
int square(int n)
{
    return n * n;
}

// 打印 vector 函数 (和上次一样)
void print_vector(const string &title, const vector<int> &v)
{
    cout << title << ": [ ";
    for (int val : v)
    {
        cout << val << " ";
    }
    cout << "]" << endl;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    print_vector("v (Original)", v);
    cout << endl;

    // --- 使用 std::transform 进行“原地”修改 ---
    cout << "--- Applying std::transform in-place ---" << endl;

    // 关键改动：
    // 输入是 v.begin() ... v.end()
    // 输出的起始位置也是 v.begin()！
    transform(v.begin(), v.end(), v.begin(), square);

    // 观察：v 本身被修改了
    print_vector("v (After transform)", v); // 预期: [ 1 4 9 16 25 ]
    cout << endl;

    // --- 我们之前学过的其他“直接修改”方式 ---

    // 1. 通过索引 (最直接)
    v[0] = 999;

    // 2. 通过迭代器 (也很直接)
    auto it = v.begin();
    ++it;      // 指向第二个元素 (4)
    *it = 888; // 把 4 改成 888

    print_vector("v (After manual edits)", v); // 预期: [ 999 888 9 16 25 ]

    return 0;
}