#include <iostream>
#include <string>
using namespace std;

/* 你的代码将嵌在这里 */
void reverse_string(string &str) {
    int n = str.length();
    for (int i = 0; i < n / 2; i++) {
        swap(str[i], str[n - i - 1]);
    }
}

int main(int argc, char const *argv[])
{
    string str;
    getline(cin, str);        //输入字符串
    reverse_string(str);     //逆序字符串str
    cout << str << endl;    //输出逆序后的字符串
    return 0;
}