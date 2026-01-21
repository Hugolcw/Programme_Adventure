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

// 简化版：直接输入 k 值，无需先输入测试用例数量
int main()
{
    int k;
    cin >> k;
    cout << findKthNumber(k) << endl;
    return 0;
}

