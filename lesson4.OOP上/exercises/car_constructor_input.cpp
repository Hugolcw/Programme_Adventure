#include <iostream>
#include <string>
using namespace std;

// 定义一个 Car 类
class Car {
public:
    string getColor() {
        return color;
    }
    string getBrand() {
        return brand;
    }

    int getSpeed() {
        return speed;
    }

    // 构造函数：与类名相同，没有返回函数
    // 第一个构造函数（默认构造函数）
    Car() {
        cout << "正在创建一辆新车..." << endl;
        // 自动初始化成员变量
        color = "未设定";
        brand = "未知";
        speed = 0;
    }

    void drive(int distance_km, int speed_increase) {
        speed += speed_increase;
        cout << "汽车行驶了 " << distance_km << " 公里，" 
        << "现在的速度是 " << speed << " km/h" << endl;
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

    void setColor(string c) {
        color = c;
    }

    void setBrand(string b) {
        brand = b;
    }

    void setSpeed(int s) {
        speed = s;
    }

    // 示例
    void stop() {
        speed = 0;
        cout << "汽车已经停下了。" << endl;
    }
private:
    // 成员变量（数据）
    string color;
    string brand;
    int speed;
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
    cout << "你的新车品牌是：" << yourCar.getBrand() << endl;
    cout << "你的新车颜色是：" << yourCar.getColor() << endl;

    // 获取用户输入，自定义修改速度
    int new_speed, distance;
    cout << "你想将汽车加速到多少？";
    cin >> new_speed;
    cout << "你想让汽车行驶多少公里？";
    cin >> distance;

    // 调用 Setter 函数来修改速度
    yourCar.drive(distance, new_speed);

    yourCar.stop();

    // 打印新的速度，验证修改是否成功
    cout << "汽车现在的速度是：" << yourCar.getSpeed() << " km/h" << endl;

    return 0;
}