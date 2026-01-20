#include <iostream>
#include <string> // 使用string需要包含头文件
#include <vector>
using namespace std;

int main()
{
    string n; // 1. 必须用字符串接收，因为数字太大，int存不下
    cin >> n;

    int sum = 0;
    // 2. 遍历字符串，计算各位数字之和
    for (int i = 0; i < n.length(); i++)
    {
        // n[i] 是字符，比如 '2'，减去 '0' 才能变成整数 2
        sum += (n[i] - '0');
    }

    // 3. 把计算出来的和（例如135）转换成字符串，方便逐位输出
    string sum_str = to_string(sum);

    // 4. 定义拼音映射表（下标0对应ling，下标1对应yi...）
    string pinyin[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

    // 5. 输出
    for (int i = 0; i < sum_str.length(); i++)
    {
        // 获取当前位的数字
        int digit = sum_str[i] - '0';

        // 输出拼音
        cout << pinyin[digit];

        // 格式控制：如果是最后一位，后面不加空格；否则加空格
        if (i != sum_str.length() - 1)
        {
            cout << " ";
        }
    }

    return 0;
}