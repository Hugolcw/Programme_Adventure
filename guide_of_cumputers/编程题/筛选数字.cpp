#include <iostream>

using namespace std;

// 找到第 k 个满足条件的数字（不能被3整除且个位数不是3）
int findKthNumber(int k)
{
    int count = 0;
    int num = 0;

    while (count < k)
    {
        num++;
        if (num % 3 != 0 && num % 10 != 3)
        {
            count++;
        }
    }
    return num;
}

int main()
{
    int t;
    cin >> t;
    
    // 如果没有输入测试用例数量，或者输入为0，则处理为单个测试用例
    if (t <= 0)
    {
        // 这种情况不会发生，因为 cin >> t 会等待输入
        // 但为了代码健壮性，我们保留这个检查
        return 0;
    }
    
    for (int i = 0; i < t; i++)
    {
        int k;
        cin >> k;
        cout << findKthNumber(k) << endl;
    }
    return 0;
}