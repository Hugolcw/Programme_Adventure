#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    float weight;
    cin >> weight;
    float tip = 0.0;
    if (weight > 50) {
        tip = 10 + (weight - 50) * 0.5;
    }
    else if (weight > 0) {
        tip = weight * 0.2;
    }
    cout << "应付的行李费为：" << fixed << setprecision(2) << tip << endl;
    return 0;
}