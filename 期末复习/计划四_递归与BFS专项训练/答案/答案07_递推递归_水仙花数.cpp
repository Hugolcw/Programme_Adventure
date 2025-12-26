#include <iostream>
using namespace std;

int sumOfCubes(int n);

int main()
{
    int m;
    cin >> m;
    if(sumOfCubes(m) == m)
        cout << m << " is a narcissistic number.";
    else
        cout << m << " is not a narcissistic number.";
    return 0;
}

int sumOfCubes(int n) {
    // 终止条件
    if (n == 0) {
        return 0;
    }
    
    // 递归关系：提取个位数字，计算立方，递归处理剩余部分
    int digit = n % 10;
    return digit * digit * digit + sumOfCubes(n / 10);
}

