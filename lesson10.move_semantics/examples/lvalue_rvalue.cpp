#include <iostream>
#include <string>

using namespace std;

string create_greeting()
{
    // "Hello" 是一个临时的右值
    return string("Hello");
}

int main()
{
    // “引用” (References) 是我们区分左值/右值的第一个工具

    // --- 1. 左值引用 (Lvalue Reference) ---
    // 这是你以前学过的“标准引用”，用一个 &
    // 它只能绑定到左值 (有名字、有地址的东西)

    string s = "world";     // s 是一个左值
    string &lvalue_ref = s; // 正确：左值引用 绑定到 左值 s

    // string& bad_ref = string("temp"); // 错误！左值引用不能绑定到右值(临时对象)
    // const string& const_ref = string("temp"); // (特例：const 左值引用可以绑定到右值)

    // --- 2. 右值引用 (Rvalue Reference) ---
    // 这是 C++11 的新特性，用两个 &&
    // 它只能绑定到右值 (临时的、将死的东西)

    // string&& bad_ref_2 = s; // 错误！右值引用不能绑定到左值 s

    string &&rvalue_ref_1 = string("temp");    // 正确：右值引用 绑定到 临时对象(右值)
    string &&rvalue_ref_2 = create_greeting(); // 正确：绑定到函数返回的临时对象(右值)
    string &&rvalue_ref_3 = s + "!";           // 正确：绑定到 s + "!" 产生的临时字符串(右值)

    cout << "s (lvalue): " << s << endl;
    cout << "rvalue_ref_1 (bound to 'temp'): " << rvalue_ref_1 << endl;

    // 我们可以通过右值引用来修改这个“临时工”
    rvalue_ref_1 = "new value";
    cout << "rvalue_ref_1 (modified): " << rvalue_ref_1 << endl;

    return 0;
}