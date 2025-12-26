#include <iostream>
using namespace std;

class A {
protected:
    int i;
public:
    A(int i) {
        this->i = i;
        cout << "Call A:i=" << i << endl;
    }
    void display() {
        cout << "i=" << i << endl;
    }
};

class A1 : virtual public A {
protected:
    int j;
public:
    A1(int i, int j) : A(i) {
        this->j = j;
        cout << "Call A1:i=" << i << endl;
    }
    void display() {
        cout << "j=" << j << endl;
    }
};

class A2 : virtual public A {
protected:
    int k;
public:
    A2(int i, int k) : A(i) {
        this->k = k;
        cout << "Call A2:i=" << i << endl;
    }
    void display() {
        cout << "k=" << k << endl;
    }
};

class A3 : public A1, public A2 {
public:
    A3(int i, int j, int k) : A(i), A1(i, j), A2(i, k) {
        cout << "Call A3:i=" << i << endl;
    }
    void disp() {
        A::display();
        A1::display();
        A2::display();
    }
};

int main() {
    int i, j, k;
    cin >> i >> j >> k;
    A3 a3(i, j, k);
    a3.disp();
    return 0;
}