#include <iostream>
#include <string>
using namespace std;
int main()
{
    int v, n;
    cin >> v >> n;
    int d0 = v % 10;
    int d1 = (v / 10) % 10;
    int d2 = v / 100;
    int decimal_result = d2 * (n * n) + d1 * n + d0 * 1;
    cout << decimal_result;
    return 0;
}