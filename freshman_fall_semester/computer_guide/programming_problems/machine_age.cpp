#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

unsigned char data_mem[65536];

int jump_map[65536];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string code;
    getline(cin, code);

    stack<int> s;
    int len = code.length();

    for (int i = 0; i < len; ++i) {
        if (code[i] == '6') {
            s.push(i);
        } else if (code[i] == '7') {
            if (!s.empty()) {
                int start = s.top();
                s.pop();
                jump_map[start] = i;
                jump_map[i] = start;
            }
        }
    }

    unsigned short pc = 0;
    unsigned short pd = 0;

    while (pc < len) {
        char op = code[pc];

        switch (op) {
            case '0':
                cout.put((char)data_mem[pd]);
                break;
            case '1':
                {
                    char c;
                    if (cin.get(c)) {
                        data_mem[pd] = (unsigned char)c;
                    }
                }
                break;
            case '2':
                data_mem[pd]++;
                break;
            case '3':
                data_mem[pd]--;
                break;
            case '4':
                pd++;
                break;
            case '5':
                pd--;
                break;
            case '6':
                if (data_mem[pd] == 0) {
                    pc = jump_map[pc];
                }
                break;
            case '7':
                if (data_mem[pd] != 0) {
                    pc = jump_map[pc];
                }
                break;
            default:
                break;
        }
        pc++;
    }
    return 0;
    
}