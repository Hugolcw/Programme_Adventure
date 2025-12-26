#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int total_drank = n;   // 至少能喝 n 瓶
    int empty_bottles = n; // 喝完后，有 n 个空瓶

    // 循环换瓶
    while (empty_bottles >= m)
    {
        int new_bottles = empty_bottles / m;  // 能换多少新瓶子
        total_drank += new_bottles;           // 把新换的瓶子计入总数
        
        int remaining_empty = empty_bottles % m;  // 换完剩下的空瓶
        empty_bottles = remaining_empty + new_bottles;  // 更新空瓶总数
    }

    // 检查是否可以"赊"1瓶
    if (empty_bottles == m - 1)
    {
        total_drank++;  // 可以"赊"1瓶
    }

    cout << total_drank << endl;

    return 0;
}

