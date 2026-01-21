#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
using namespace std;

int main() {

    // 1. 整型数据类型（Integer Types）
    short shortVar = 32767;
    int intVar = 2147483647;
    long longVar = 2147483647L;
    long long longlongVar = 9223372036854775807LL;

    cout << "short:" << shortVar << " (大小：" << sizeof(short) << "字节)" << endl;
    cout << "int:" << intVar << " (大小：" << sizeof(int) << "字节)" << endl;
    cout << "long:" << longVar << " (大小：" << sizeof(long) << "字节)" << endl;
    cout << "long long:" << longlongVar << " (大小：" << sizeof(long long) << "字节)" << endl;
    cout << endl;

    // 2.浮点数数据类型（Floating-Point Types）
    float floatVar = 3.1415926535f;
    double doubleVar = 3.141592653589793;
    long double longdoubleVar = 3.1415926535897932385L;

    cout << fixed << setprecision(10);
    cout << "float:" << floatVar << "(大小：" << sizeof(float) << "字节）" << endl;
    cout << "double:" << doubleVar << "(大小：" << sizeof(double) << "字节）" << endl;
    cout << "long double:" << longdoubleVar << "(大小：" << sizeof(long double) << "字节）" << endl;
    cout << endl;

    // 3.字符类型（Character Types）
    char charVar = 'A';
    signed char signedcharVar = -128;
    unsigned char unsignedcharVar = 255;
    wchar_t widecharVar = L'中';

    cout << "char: '" << charVar << "'(ASCII:" << (int)charVar << ")" <<endl;
    cout << "signed char: " << (int)signedcharVar << endl;
    cout << "unsigned char: " << (int)unsignedcharVar << endl;
    cout << "wchar_t: (宽字符）" << endl;
    cout <<endl;

    // 4.布尔类型（Boolean Type）
    bool trueVar = true;
    bool falseVar = false;

    cout << boolalpha;
    cout << "true:" << trueVar << endl;
    cout << "false:" << falseVar << endl;
    cout << noboolalpha;
    cout << "true(数值）:" << trueVar << endl;
    cout << "false(数值）:" << falseVar << endl;
    cout << endl;

    // 5.字符串类型（String Types）

    // C风格字符串
    char cString[] = "Hello C String";
    // C++ String类
    string cppString = "Holle C++ String";

    cout << "C风格字符串：" << cString << endl;
    cout << "C++ string:" << cppString << endl;
    cout << "string长度:" << cppString.length() << endl;
    cout << endl;

    // 6.类型修饰符（Type Modifiers）
    unsigned int unsignedInt = 4294967295U;
    signed int signedInt = -2147483628;
    const int constInt = 100; //常量

    cout << "unsigned int:" << unsignedInt << endl;
    cout << "signed int:" << signedInt << endl;
    cout << "const int:" << constInt << endl;
    // constInt = 200; // 错误：常量不能修改
    cout << endl;

    // 7.类型转换（Type Conversion）
    int intNum = 10;
    double doubleNum = 3.14;

    // 隐式转换
    double result1 = intNum + doubleNum;
    // 显式转换（C风格）
    int result2 = intNum + (int)doubleNum;
    // 显式转换（C++风格）
    int result3 = intNum + static_cast<int>(doubleNum);

    cout << "隐式转换：" << intNum << " + " << doubleNum << " = " << result1 << endl;
    cout << "C风格显式转换：" << intNum << " + (int)" << doubleNum << " = " << result2 << endl;
    cout << "C++风格显式转换：" << intNum << " + static_cast<int>(" << doubleNum << ") = " << result3 <<endl;
    cout << endl;

    // 8.类型范围查看（Type Limits）
    cout << "int范围：" << numeric_limits<int>::min() << " 到 " << numeric_limits<int>::max() << endl;
    cout << "double范围：" << numeric_limits<double>::min() << " 到 " << numeric_limits<double>::max() << endl;
    cout << "char范围：" << numeric_limits<char>::min() << " 到 " << numeric_limits<char>::max() << endl;
    cout << endl;

    // 9.内存地址查看（Memory Addresses）
    cout << "intVar地址：" << &intVar << endl;
    cout << "doubleVar地址：" << &doubleVar << endl;
    cout << "charVar地址：" << (void*)&charVar << endl;
    cout << "cppString地址：" << &cppString << endl;
    cout << endl;

    // 10,实践练习（Practice Erexcise）

    // 练习1：类型转换
    cout << "练习1 - 类型转换:" << endl;
    int practiceInt = 97;
    char practiceChar = static_cast<char>(practiceInt);
    cout << "ASCII " << practiceInt << " 对应的字符：" << practiceChar << "'" << endl;

    // 练习2：数值计算
    cout << "练习2 - 数值计算:" << endl;
    double radius = 5.0;
    double area = 3.14159 * radius * radius;
    cout << "半径 " << radius << " 的圆面积：" << area <<endl;

    // 练习3.字符串操作
    cout << "练习3 - 字符串操作:" << endl;
    string fristName = "张";
    string lastName = "三";
    string fullName = fristName + " " + lastName;
    cout << "全名：" << fullName << endl;

    cout << endl << "=== 数据类型学习完成 ===" << endl;

    return 0;
}
    
    
    
    
