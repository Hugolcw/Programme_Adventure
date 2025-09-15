#include <iostream>
using namespace std;

int main() {
    cout << "1-100之间所有3的倍数:";

    for (int i = 1; i <= 100; i++) {
        if (i % 3 == 0) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}
