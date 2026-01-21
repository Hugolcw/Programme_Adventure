#include <iostream>
#include <string>    // 1. 必须包含 <string> 头文件
#include <algorithm> // 为了 std::reverse

using namespace std;

int main()
{
    // 1. 创建和拼接
    string s1 = "Hello";
    string s2 = "World";

    // 使用 + 运算符轻松拼接
    string s3 = s1 + ", " + s2 + "!";
    cout << "s3: " << s3 << endl;

    // 2. string 作为“字符容器”
    cout << "\n--- String as a container ---" << endl;
    cout << "s3[0]: " << s3[0] << endl;        // 像 vector 一样用 [] 访问
    cout << "Length: " << s3.length() << endl; // .length() 和 .size() 都可以

    // 像 vector 一样用迭代器遍历
    cout << "Using iterators: ";
    for (auto it = s3.begin(); it != s3.end(); ++it)
    {
        cout << *it << "-";
    }
    cout << endl;

    // 3. 强大的文本查找：.find()
    cout << "\n--- Finding substrings ---" << endl;
    string greeting = "Hello, C++ World!";

    // 查找 "C++"
    // .find() 返回子字符串的起始索引
    size_t pos = greeting.find("C++");

    if (pos == string::npos) // string::npos 是个特殊值，表示“未找到”
    {
        cout << "'C++' not found." << endl;
    }
    else
    {
        cout << "'C++' found at index: " << pos << endl;
    }

    // 4. 提取子字符串：.substr()
    cout << "\n--- Extracting substrings ---" << endl;
    // 从索引 7 开始，提取 3 个字符
    string sub = greeting.substr(7, 3);   // 7是 "C" 的索引, 3是 "C++" 的长度
    cout << "Substring: " << sub << endl; // 输出: C++

    // 5. 替换文本：.replace()
    cout << "\n--- Replacing text ---" << endl;
    cout << "Original: " << greeting << endl;
    // 从索引 7 开始，替换 3 个字符，换成 "Python"
    greeting.replace(7, 3, "Python");
    cout << "Replaced: " << greeting << endl;

    // 6. 配合 <algorithm>
    // 既然 string 是一个容器，它就可以使用 STL 算法！
    string test = "ABCDE";
    reverse(test.begin(), test.end()); // 翻转字符串
    cout << "\nReversed 'ABCDE': " << test << endl;

    return 0;
}