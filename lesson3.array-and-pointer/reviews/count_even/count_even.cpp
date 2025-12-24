#include <iostream>
using namespace std;

int main() {
    int number[5];

    cout << "请输入 5 个整数：" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "请输入第 " << i + 1 << " 个数：";
        cin >> number[i];
    }

    int even_count = 0;

    for (int i = 0; i < 5; i++) {
        if (number[i] % 2 == 0) {
            even_count++;
        }
    }

    cout << "数组中的是偶数个数是：" << even_count << endl;

    return 0;

}