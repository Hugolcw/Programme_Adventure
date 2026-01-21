#include <iostream>
#include <string>
using namespace std;

// 定义一个 Car 类
class Car {
public:
    // 成员变量（数据）
    string color;
    string brand;
    int speed;

    // 构造函数：与类名相同，没有返回函数
    // 第一个构造函数（默认构造函数）
    Car() {
        cout << "正在创建一辆新车..." << endl;
        // 自动初始化成员变量
        color = "未设定";
        brand = "未知";
        speed = 0;
    }

    // 第二个构造函数（带参数的构造函数）
    Car(string _brand, string _color) {
        brand = _brand;
        color = _color;
        speed = 0;
    }

    // 成员函数（行为）
    void start() {
        cout << "汽车启动了！" << endl;
    }
};

int main() {
    // 获取用户输入
    string user_brand, user_color;
    cout << "请输入你想要的汽车品牌：";
    cin >> user_brand;
    cout << "请输入你想要的汽车颜色：";
    cin >> user_color;

    // 使用用户的输入来创建对象
    Car yourCar(user_brand, user_color);

    // 打印结果，验证对象是否被正确初始化
    cout << "你的新车品牌是：" << yourCar.brand << endl;
    cout << "你的新车颜色是：" << yourCar.color << endl;


    return 0;
}