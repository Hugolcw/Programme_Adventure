#include<iostream>
using namespace std;

bool check(int n);

//判断输入的n是否回文数，处理到文件尾 
int main() {
    int n;
    while(cin>>n) {
        if(check(n)==true)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}

//请在此处填写答案
bool check(int n) {
    if (n < 0) {
        return false;
    }

    int original = n;
    int reversed = 0;

    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }

    return original == reversed;
}