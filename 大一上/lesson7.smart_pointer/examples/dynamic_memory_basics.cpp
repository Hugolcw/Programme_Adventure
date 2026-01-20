#include <iostream>
using namespace std;

int main() {
    int* myPtr = new int{100};

    cout << "*myPtr 的值是：" << *myPtr << endl;

    *myPtr = 200;

    cout << "现在 *myPtr 的值是：" << *myPtr << endl;

    delete myPtr;

    myPtr = nullptr;

    cout << *myPtr << endl;

    return 0;

}