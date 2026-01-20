#include<iostream>
using namespace std;

long long int fact(int n); //求n的阶乘

//输入n，求其阶乘并输出，处理到文件尾 
int main() {
    int n;
    while(cin>>n) {        
        cout<<fact(n)<<endl; 
    }    
    return 0;
}

//请在此处填写答案
long long int fact(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    else {
        return n * fact(n - 1);
    }
}