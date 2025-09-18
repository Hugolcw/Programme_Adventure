#include <iostream>
using namespace std;

int main() {
    double fahrenheit;
    double celsius;

    cout << "请输入华氏摄氏度：";
    cin >> fahrenheit;

    celsius = (fahrenheit - 32) * 5 / 9;

    cout << endl;
    cout << "转换结果：" << endl;
    cout << "华氏 " << fahrenheit << "°F = 摄氏 " << celsius << "°C" << endl;

    return 0;
}
