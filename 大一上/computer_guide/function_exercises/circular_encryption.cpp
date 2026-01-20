
#include <iostream>
#include <cmath>
using namespace std;
char Encode(char plain, int key);

int main()
{
    char plain, y;
    int key;
    cin>>plain>>key;
    y = Encode(plain, key);
    cout<<y;
    return 0;
}

/* 请在这里填写答案 */
char Encode(char plain, int key) {
    // 仅处理英文字母，其余字符直接返回
    if (!isalpha(static_cast<unsigned char>(plain))) {
        return plain;
    }

    // 选择大小写的起始码点
    const char base = isupper(static_cast<unsigned char>(plain)) ? 'A' : 'a';
    // 在 0-25 区间内归一化偏移量
    int shift = key % 26;
    // 计算偏移后的位置，确保结果仍在 0-25 内
    int pos = (plain - base + shift + 26) % 26;
    return static_cast<char>(base + pos);
}