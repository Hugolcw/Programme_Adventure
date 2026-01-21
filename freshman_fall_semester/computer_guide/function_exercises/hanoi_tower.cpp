#include<iostream>
using namespace std;

//将n个圆盘借助by从from移到to
void hanoi(int n, char from, char to, char by);

//输入n，输出将原来在A上的n个圆盘借助C移动到B上的移动过程，控制到文件尾
int main() {
    int n, cnt=0;
    while(cin>>n) {
        cnt++;
        if (cnt>1) cout<<endl;
        hanoi(n, 'A', 'B', 'C');
    }
    return 0;
}

//请在此处填写答案
void hanoi(int n, char from, char to, char by) {
    if (n == 1) {
        cout << from << "->" << to << endl;
        return;
    }
    
    hanoi(n - 1, from, by, to);

    cout << from << "->" << to << endl;

    hanoi(n - 1, by, to, from);
}