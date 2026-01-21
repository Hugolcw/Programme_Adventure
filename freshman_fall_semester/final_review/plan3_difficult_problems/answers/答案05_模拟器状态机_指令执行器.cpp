#include <iostream>
#include <string>
using namespace std;

int main() {
    string code;
    getline(cin, code);
    
    int len = code.length();
    
    // 1. 预处理：建立跳转表（使用数组模拟栈）
    int stack[1005];
    int top = 0;
    int jump_map[1005] = {0};
    
    for (int i = 0; i < len; i++) {
        if (code[i] == '[') {
            stack[top++] = i;
        } else if (code[i] == ']') {
            int start = stack[--top];
            jump_map[start] = i;  // [ -> ]
            jump_map[i] = start;  // ] -> [
        }
    }
    
    // 2. 执行指令
    int acc = 0;  // 累加器
    int pc = 0;   // 程序计数器
    
    while (pc < len) {
        char op = code[pc];
        
        switch (op) {
            case 'A':
                acc++;
                break;
            case 'S':
                acc--;
                break;
            case 'P':
                cout << acc << endl;
                break;
            case '[':
                if (acc == 0) {
                    pc = jump_map[pc];  // 跳转到匹配的]
                }
                break;
            case ']':
                if (acc != 0) {
                    pc = jump_map[pc];  // 跳转回匹配的[
                }
                break;
        }
        pc++;
    }
    
    return 0;
}

