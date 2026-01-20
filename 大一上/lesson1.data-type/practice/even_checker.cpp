#include <iostream>
using namespace std;

int main() {
    int number;

    cout << "请输入一个整数:";
    cin >> number;

    if (number % 2 == 0) {
        cout << number << " 是偶数" << endl;
    } else {
        cout << number << " 是奇数" << endl;
    }

    return 0;
}
       
