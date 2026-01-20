#include <bits/stdc++.h>
using namespace std;

/* s为主串，t为模式串。
 * 函数返回t在s中第一次出现的位置。
 */
int BF(string s, string t);

int main(int argc, char const *argv[])
{
    string s, t;
    getline(cin, s);    //输入主串
    getline(cin, t);    //输入模式串
    int pos = BF(s, t);    //搜索
    cout << pos << endl;//输出模式串在主串中第一次出现的位置
    return 0;
}

/* 请在这里填写答案 */
int BF(string s, string t) {
    int lenS = s.length();
    int lenT = t.length();

    if (lenT > lenS) return -1;

    for (int i = 0; i <= lenS - lenT; i++) {
        int j = 0;

        while (j < lenT && s[i + j] == t[j]) {
            j++;
        }

        if (j == lenT) {
            return i;
        }
    }

    return -1;
}