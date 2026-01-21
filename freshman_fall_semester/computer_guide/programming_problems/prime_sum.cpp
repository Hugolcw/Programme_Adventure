#include <iostream>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    
    int count = 0;
    int sum = 0;

    for (int i = m; i <= n; i++) {
        if (i < 2) {
            continue;
        }
        bool is_prime = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            count++;
            sum += i;
            }
    }
    cout << m << "和" << n << "之间有" << count << "个素数，" << "这些素数的和是" << sum << "。" << endl;

    return 0;
}
