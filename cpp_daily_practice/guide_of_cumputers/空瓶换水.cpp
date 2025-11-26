#include <iostream>

using namespace std;

int main()
{
    int n, m;
    // 1. 读取初始瓶数 n 和 交换所需的空瓶数 m
    cin >> n >> m;

    int total_drank = n;   // 至少能喝 n 瓶
    int empty_bottles = n; // 喝完后，有 n 个空瓶

    // 2. 开始循环交换
    // 只要我们手头的空瓶数 (empty_bottles) 足够换 (>= m)
    while (empty_bottles >= m)
    {

        // 2a. 计算能换多少新瓶子
        int new_bottles = empty_bottles / m;

        // 2b. 把新换的瓶子计入总数
        total_drank += new_bottles;

        // 2c. 计算换完后剩下的空瓶
        int remaining_empty = empty_bottles % m;

        // 2d. 更新空瓶总数：
        // (换完剩下的) + (刚喝完的新瓶子)
        empty_bottles = remaining_empty + new_bottles;
    }

    // 3. 应用“赊1瓶”逻辑
    // 循环结束后，我们手头有 empty_bottles 个空瓶 (此时 < m)
    // 正如你的分析：如果我们手头的空瓶数 (empty_bottles)
    // 刚好比交换所需的 (m) 少一个，即等于 m - 1
    //
    // 示例 (15, 4):
    // 循环结束时, total_drank = 19, empty_bottles = 3
    // 此时 m = 4, m - 1 = 3
    // empty_bottles == (m - 1) 成立
    if (empty_bottles == m - 1)
    {
        // 我们可以"赊"1瓶，总数+1
        total_drank++;
    }

    // 4. 输出最终结果
    cout << total_drank << endl;

    return 0;
}