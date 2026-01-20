#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(int n);

//判断输入的正整数n是否素数，是则输出yes，否则输出no
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}
int main() {
    int n;
    while(cin>>n) {
        if(isPrime(n)==true)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }    
    return 0;
}

//请在此处填写答案