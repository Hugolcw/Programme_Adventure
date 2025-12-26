在这里给出函数被调用进行测试的例子。例如：
#include<iostream>
using namespace std;
int tao(int n);
int main()
{
    int day;
    cin >> day;
    int num = tao(day);
    cout << num;
    return 0;
}
/* 请在这里填写答案 */
int tao(int n) {
    if (n == 1) {
        return 1;
    } else {
        return tao(n - 1) * 2 + 1;
    }
}