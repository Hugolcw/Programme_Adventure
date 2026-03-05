#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <cctype>

void f() noexcept
{
    std::cout << "hello\n";
}

void f2()
{
    std::cout << "hello\n";
}

void f3() throw()
{
    std::cout << "hello\n";
}
int main()
{
    std::cout << std::boolalpha << noexcept(f()) << std::endl;
    std::cout << std::boolalpha << noexcept(f2()) << std::endl;
    auto p = f3;
    p();
}