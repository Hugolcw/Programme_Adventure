#include <iostream>
using namespace std;
//请在此处添加代码
float& cut(float &a, float &b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}
int main(){
    float a,b;
    cin>>a>>b;
    cut(a,b)=0;
    cout<<"to pay:"<<a+b<<endl;    
    return 0;
}