#include <iostream>
using namespace std;

/* 请在这里填写答案 */
void square(int &a) {
    a = a * a;
}
void square(int &);
int main(){
    int a;
    cin>>a;
    square(a);        //将a的值变为原值的平方 
    cout<<a<<endl;
    return 0;    
}

