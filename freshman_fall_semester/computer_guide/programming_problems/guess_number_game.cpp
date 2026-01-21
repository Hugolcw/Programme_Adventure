#include <iostream>
using namespace std;
const int T = 5;
int main() {
    int N;
    cin >> N;
    int guess;
    bool success = false;
    for (int i = 0; i < T; i++) {
        cin >> guess;
        if (guess == N) {
            cout << "猜对了" << endl;
            success = true;
            break;
        } else if (guess > N) {
            cout << "猜大了" << endl;
        } else {
            cout << "猜小了" << endl;
        }
    }
    if (!success) {
        cout << "游戏失败" << endl;
    }
    return 0;
}