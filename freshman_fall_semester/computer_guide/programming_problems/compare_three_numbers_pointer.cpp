#include <iostream>
using namespace std;

void swap(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void sortThree(int *p1, int *p2, int *p3) {
    if (*p1 > *p2) swap(p1, p2);
    if (*p1 > *p3) swap(p1, p3);
    if (*p2 > *p3) swap(p2, p3);
}
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    sortThree(&a, &b, &c);
    cout << a << "   " << b << "   " << c << endl;
    return 0;
}