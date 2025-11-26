#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

// --- 这是一个“一元操作” (Unary Operation) ---
// 它接受一个 int，返回一个 int
// 它的“操作”是：返回这个数的平方
int square(int n)
{
    return n * n;
}

void print_vector(const string &title, const vector<int> &v)
{
    cout << title << ":[ ";
    for (int val : v)
    {
        cout << val << " ";
    }
    cout << "]" << endl;
}

int main()
{
    vector<int> v1 = {1, 2, 3, 4, 5};

    // 1. 准备一个“输出”容器
    // 我们要存放 v1 中 5 个元素的平方
    // 所以 v2 必须有足够的空间来接收这 5 个结果
    vector<int> v2(v1.size());

    print_vector("v1 (Input)", v1);
    print_vector("v2 (Output, before)", v2);
    cout << endl;

    // 1. 使用 std::transform
    cout << "--- Applying std::transform to square numbers ---" << endl;

    // 语法：transform(v1.begin(), v1.end(), v2.begin(), 操作函数)
    transform(v1.begin(), v1.end(), v2.begin(), square);

    print_vector("v1 (Input, unchanged)", v1);
    print_vector("v2 (Output, after)", v2);
    cout << endl;

    // 2. 转换 string （原地转换）
    cout << "--- Applying std::transform to a string ---" << endl;
    string s = "Hello C++";
    cout << "Original: " << s << endl;

    // 我们可以让“输入”和“输出”是同一个容器！
    // 这样 transform 就会“原地”修改 string
    // ::toupper 是一个系统自带的“将字符转为大写”的函数
    transform(s.begin(), s.end(), s.begin(), ::toupper);

    cout << "Transformed: " << s << endl; // 预测："HELLO C++"

    return 0;
}