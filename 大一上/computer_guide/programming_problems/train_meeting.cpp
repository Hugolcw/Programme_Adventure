#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double len_a = 150.0;
    double len_b = 200.0;
    double total_distance = len_a + len_b;

    double x, y;
    // 输入两个火车的速度（在同一行用空格分隔，或者分别输入）
    // 例如：5 5  或者  5 回车 5
    cin >> x >> y;

    double relative_speed = x + y;
    
    // 避免除零错误
    if (relative_speed <= 0)
    {
        cout << "错误：速度必须大于0" << endl;
        return 1;
    }

    double time = total_distance / relative_speed;

    cout << fixed << setprecision(2) << time << " seconds." << endl;

    return 0;
}