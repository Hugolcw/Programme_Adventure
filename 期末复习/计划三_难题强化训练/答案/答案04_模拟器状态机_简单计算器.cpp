#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    
    // 1. 解析表达式，提取数字和运算符
    int nums[1005];
    char ops[1005];
    int numCount = 0, opCount = 0;
    
    int i = 0;
    while (i < s.length()) {
        // 跳过空格
        if (s[i] == ' ') {
            i++;
            continue;
        }
        
        // 提取数字
        if (s[i] >= '0' && s[i] <= '9') {
            int num = 0;
            while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            nums[numCount++] = num;
        }
        // 提取运算符
        else if (s[i] == '+' || s[i] == '*') {
            ops[opCount++] = s[i];
            i++;
        }
    }
    
    // 2. 先处理所有乘法
    int newNums[1005];
    char newOps[1005];
    int newNumCount = 0, newOpCount = 0;
    
    newNums[0] = nums[0];
    newNumCount = 1;
    
    for (int i = 0; i < opCount; i++) {
        if (ops[i] == '*') {
            // 乘法：将最后一个数字与下一个数字相乘
            newNums[newNumCount - 1] *= nums[i + 1];
        } else {
            // 加法：保留数字和运算符
            newNums[newNumCount++] = nums[i + 1];
            newOps[newOpCount++] = ops[i];
        }
    }
    
    // 3. 处理所有加法
    int result = newNums[0];
    for (int i = 0; i < newOpCount; i++) {
        result += newNums[i + 1];
    }
    
    cout << result << endl;
    
    return 0;
}

