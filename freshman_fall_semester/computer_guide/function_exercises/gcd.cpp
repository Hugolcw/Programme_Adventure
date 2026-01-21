#include<iostream>
using namespace std;

int gcd(int a, int b);

//输入若干对整数，输出它们的最大公约数，处理到文件尾 
int main() {
    int a,b;
    while(cin>>a>>b) {
        cout<<gcd(a, b)<<endl;
    }
    return 0;
}

//请在此处填写答案
int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}