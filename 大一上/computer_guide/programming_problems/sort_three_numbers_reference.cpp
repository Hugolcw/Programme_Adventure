#include <iostream>
using namespace std;

void swap (int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void sortThree(int &a, int &b, int &c) {
    if (a > b) swap(a, b);
    if (a > c) swap(a, c);
    if (b > c) swap(b, c);
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    sortThree(a, b, c);
    cout << a << " " << b << " " << c << endl;
    return 0;
}