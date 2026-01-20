#include <thread>
#include <iostream>

struct X {
    void f() { std::cout << "Hello from thread!\n"; }
};

int main() {
    X x;
    // 传递成员函数指针和对象
    std::thread t(&X::f, &x);  // 或者 std::thread t(&X::f, x);
    t.join();
}
