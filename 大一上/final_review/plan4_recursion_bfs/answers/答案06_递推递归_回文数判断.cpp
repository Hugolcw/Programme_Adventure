#include<iostream>
#include<string>
using namespace std;

bool isPalindrome(string s, int left, int right);

int main() {
    int n;
    while(cin >> n) {
        string s = to_string(n);
        if(isPalindrome(s, 0, s.length() - 1) == true)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}

bool isPalindrome(string s, int left, int right) {
    // 终止条件：左右指针相遇或交叉
    if (left >= right) {
        return true;
    }
    
    // 递归关系：比较首尾字符
    if (s[left] == s[right]) {
        // 首尾相同，递归判断中间部分
        return isPalindrome(s, left + 1, right - 1);
    } else {
        // 首尾不同，不是回文
        return false;
    }
}

