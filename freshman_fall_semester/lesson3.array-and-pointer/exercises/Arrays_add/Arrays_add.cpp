#include <iostream>
using namespace std;

int main() {
    int number[5] = {10, 20, 30 ,40 ,50};
    int sum = 0;

    for (int i = 0; i < 5; i++) {
        sum += number[i];
    }
    cout << "数组的总和是：" << sum << endl;

    return 0;
}
