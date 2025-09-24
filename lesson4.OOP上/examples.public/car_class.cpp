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

    // 成员函数（行为）
    void start() {
        cout << "汽车启动了！" << endl;        
    }

    void accelerate(int increase) {
        speed += increase;
    }

};

int main() {
    // 根据 Car 蓝图，创建一个名为 myCar 的对象
    Car myCar;

    // 给 myCar 对象的成员变量赋值
    myCar.color = "红色";
    myCar.brand = "法拉利";
    myCar.speed = 0;

    // 调用 myCar 对象的成员函数
    myCar.start();

    // 自定义速度增量
    int acceleration_increase;
    cout << "你想让汽车加速多少？";
    cin >> acceleration_increase;

    // 将用户输入的值作为参数传递给 accelerate 函数
    myCar.accelerate(acceleration_increase);
    cout << "现在加速了： " << myCar.speed << endl;

    return 0;
}

